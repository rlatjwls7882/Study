package com.fastcampus.ch3.di1;

import org.springframework.beans.factory.annotation.Autowire;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.util.StringUtils;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class ReflectionTest {
    public static void main(String[] args) throws Exception {
        Car car = new Car();
        Class carClass = car.getClass(); // 1. 객체로부터 Class객체(설계도) 얻기
        carClass = Car.class; // 2. 객체 리터럴로부터 Class 객체 얻기
        carClass = Class.forName("com.fastcampus.ch3.di1.Car");

        // 1. 설계도 객체로부터 객체 생성하기
        Car car2 = (Car)carClass.newInstance();
        System.out.println("car2 = " + car2);

        // 2. 클래스에 선언된 멤버변수(field)와 method목록 얻기
        Field[] mvArr = carClass.getDeclaredFields();
        Method[] methodArr = carClass.getDeclaredMethods();
//        Method[] methodArr = carClass.getMethods();

        for(Field mv : mvArr) System.out.println(mv.getName());
        for(Method method : methodArr) System.out.println(method.getName());

        Method method = carClass.getMethod("setEngine", Engine.class);
        method.invoke(car, new Engine()); // car.setEngine(new Engine()), car.setDoor(new Door());
        System.out.println("car = " + car);

        // 3. mv에 set을 붙여서 setter를 호출하기
        for(Field mv : mvArr) {
            System.out.println("mv = " + mv);
            String methodName = "set" + StringUtils.capitalize(mv.getName()); // "set" + "Engine" = "setEngine"
            System.out.println("methodName = " + methodName);
            method = carClass.getMethod(methodName, mv.getType()); // carClass.getMethod("setEngine", Engine.class);
            method.invoke(car, mv.getType().newInstance()); // car.setEngine(new Engine());
        }

        System.out.println("car = " + car);

        // 4. mv에 @Autowired 붙었는지 확인하기
        for(Field mv : mvArr) {
            Annotation[] annArr = mv.getDeclaredAnnotations();
            for(Annotation anno : annArr) {
                System.out.println("mv = " + mv);
                System.out.println("anno.annotationType().getSimpleName() = " + anno.annotationType().getSimpleName());
                System.out.println(anno.annotationType() == Autowired.class);
            }
        }

        // 5. @Autowired 붙은 mv에 setter 호출하기
        car = new Car();

        for(Field mv : mvArr) {
            Annotation[] annArr = mv.getDeclaredAnnotations();
            for(Annotation anno : annArr) {
                if(anno.annotationType() == Autowired.class) {
                    // setter 호출
                    String methodName = "set" + StringUtils.capitalize(mv.getName()); // "setEngine"
                    method = carClass.getMethod(methodName, mv.getType());
                    method.invoke(car, mv.getType().newInstance()); // car.setEngine(new Engine());
                }
            }
        }
        System.out.println("car = " + car);
    }
}
