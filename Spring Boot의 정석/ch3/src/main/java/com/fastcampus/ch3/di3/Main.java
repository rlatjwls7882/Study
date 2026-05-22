package com.fastcampus.ch3.di3;

import com.fastcampus.ch3.di3.AppConfig;
import jakarta.annotation.Resource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.stereotype.Component;

import javax.inject.Inject;
import java.util.Arrays;
import java.util.Map;

@Component
class Car {
//    @Autowired
//    @Resource(name="engine") // ByName으로 검색
//    @Resource(name="superEngine")
    @Autowired // byType으로 빈을 검색
    @Qualifier("superEngine") // 검색된 빈 중에서 이름이 superEngine을 주입
//    @Inject // @Autowired와 거의 같음. required=false가 없음
    Engine engine;
//    @Autowired
    @Resource(name="door")
    Door door;

//    public Car() {}
//
//    @Autowired
//    public Car(Engine[] engine, Door door) {
//        this.engine = engine;
//        this.door = door;
//    }

    @Override
    public String toString() {
        return "Car{" +
                "engine=" + engine +
                ", door=" + door +
                '}';
    }
}
//@Component
class Engine {}
@Component
class Door {}
@Component
class SuperEngine extends Engine {}
@Component
class TurboEngine extends Engine {}

public class Main {
    public static void main(String[] args) {
        // AC 생성 - AC의 설정파일은 AppConfig.class 자바설정
        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);
        Car car = (Car)ac.getBean("car"); // byName 객체(빈)을 조회
//        Car car = ac.getBean("car", Car.class); // 위와 동일
//        Engine engine = ac.getBean(Engine.class);
//        Engine engine2 = ac.getBean(Engine.class);
//        Engine engine3 = ac.getBean(Engine.class);
//        System.out.println("car = " + car);
//        System.out.println("engine = " + engine);
//        System.out.println("engine2 = " + engine2);
//        System.out.println("engine3 = " + engine3);
//
//        System.out.println("ac.getBeanDefinitionCount() = " + ac.getBeanDefinitionCount());
//        System.out.println("ac.getBeanDefinitionNames() = " + Arrays.toString(ac.getBeanDefinitionNames()));
//        System.out.println("ac.containsBeanDefinition(\"engine\") = " + ac.containsBeanDefinition("engine"));
//        System.out.println("ac.isSingleton(\"car\") = " + ac.isSingleton("car"));
//        System.out.println("ac.isPrototype(\"engine\") = " + ac.isPrototype("engine"));


//        SysInfo info = ac.getBean(SysInfo.class);
//        System.out.println("info = " + info);
//        Map<String, String> env = System.getenv();
//        System.out.println("env = " + env);

        System.out.println("car = " + car);
    }
}
