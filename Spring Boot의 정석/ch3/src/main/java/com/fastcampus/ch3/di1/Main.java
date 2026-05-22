package com.fastcampus.ch3.di1;

import org.springframework.beans.factory.annotation.Autowired;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

class Car {
    @Autowired
    Engine engine;
    @Autowired
    Door door;

    @Override
    public String toString() {
        return "Car{" +
                "engine=" + engine +
                ", door=" + door +
                '}';
    }

    public Engine getEngine() {
        return engine;
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    public Door getDoor() {
        return door;
    }

    public void setDoor(Door door) {
        this.door = door;
    }
}
class SportsCar extends Car {}
class Truck extends Car {}
class Engine {}
class Door {}

public class Main {
    public static void main(String[] args) throws Exception {
        Car car = (Car)getObject("car");
        Engine engine = (Engine)getObject("engine");
        System.out.println("engine = " + engine);
        System.out.println("car = " + car);

    }

    static Object getObject(String key) throws Exception {
        Properties properties = new Properties();
        Class clazz = null;
        properties.load(new FileReader("config.txt"));
        String className = properties.getProperty(key); // 지정한 key의 value를 반환
        clazz = Class.forName(className);

        return clazz.newInstance();
    }

    static Car getCar() {
        return new SportsCar();
    }
}
