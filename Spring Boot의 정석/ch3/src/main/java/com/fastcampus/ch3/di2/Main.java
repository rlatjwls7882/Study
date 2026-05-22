package com.fastcampus.ch3.di2;

import jakarta.annotation.Resource;
import org.springframework.beans.factory.annotation.Autowired;

class Car {
    @Autowired Engine engine; // byType
    @Resource(name="door") Door door;

    @Override
    public String toString() {
        return "Car{" +
                "engine=" + engine +
                ", door=" + door +
                '}';
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    public void setDoor(Door door) {
        this.door = door;
    }
}
class SportsCar extends Car {
    @Override
    public String toString() {
        return "SportsCar{" +
                "engine=" + engine +
                ", door=" + door +
                '}';
    }
}
class Engine {}
class Door {}

public class Main {
    public static void main(String[] args) {
        // AppContext(Class clazz) - 설정파일 자바클래스를 지정
        AppContext ac = new AppContext(AppConfig.class);
        Car car = (Car)ac.getBean("car"); // byName
        Car car2 = (Car)ac.getBean(Car.class); // byType
        Engine engine = (Engine)ac.getBean("engine"); // byName
        Door door = (Door)ac.getBean(Door.class); // byType

        // 빈들끼리의 관계를 설정 - 수동
//        car.setEngine(engine); // car.engine = engine;
//        car.setDoor(door);

        System.out.println("car = " + car);
        System.out.println("car2 = " + car2);
        System.out.println("engine = " + engine);
        System.out.println("door = " + door);
    }
}
