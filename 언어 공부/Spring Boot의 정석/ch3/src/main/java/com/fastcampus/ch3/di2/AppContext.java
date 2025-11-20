package com.fastcampus.ch3.di2;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import com.fastcampus.ch3.di2.Door;
import com.fastcampus.ch3.di2.Engine;
import com.fastcampus.ch3.di2.SportsCar;
import jakarta.annotation.Resource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;

public class AppContext {
    Map map = new HashMap();
    AppContext() {
        map.put("car", new SportsCar());
        map.put("engine", new Engine());
        map.put("door", new Door());
    }

    AppContext(Class clazz) {
        Object config = null;
        try {
            config = clazz.newInstance();
        } catch (InstantiationException e) {
            throw new RuntimeException(e);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        Method[] methods = clazz.getDeclaredMethods();

        for(Method method : methods) {
            System.out.println("method = " + method.getName());
            for(Annotation annotation : method.getDeclaredAnnotations()) {
                if(annotation.annotationType() == Bean.class) {
                    try {
                        map.put(method.getName(), method.invoke(config, null));
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                    // map.put("car", config.car());
                }
            }
        }
        doAutowired(); // @Autowired를 찾아서 빈(객체)간의 자동 연결처리 byType
        doResource(); // @Resource를 찾아서 빈(객체)간의 자동 연결처리 byName
    }

    private void doResource() {
        for(Object bean : map.values()) {
            for(Field fld : bean.getClass().getDeclaredFields()) {
                if(fld.getDeclaredAnnotation(Resource.class)!=null) {
                    try {
                        fld.set(bean, getBean(fld.getName()));
                    } catch (IllegalAccessException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
        }
    }

    private void doAutowired() {
        for(Object bean : map.values()) {
            for(Field fld : bean.getClass().getDeclaredFields()) {
                if(fld.getDeclaredAnnotation(Autowired.class)!=null) {
                    try {
                        fld.set(bean, getBean(fld.getType())); // car.engine = obj
                    } catch (IllegalAccessException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
        }
    }

    public Object getBean(Class clazz) {
        for(Object obj : map.values()) {
            if(clazz.isInstance(obj)) {
                return obj;
            }
        }
        return null;
    }
    public Object getBean(String id) {
        return map.get(id);
    }
}
