package com.fastcampus.ch3.di4;

import com.fastcampus.ch3.Ch3Application;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.SpringBootConfiguration;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.*;
import org.springframework.core.annotation.AnnotationAttributes;
import org.springframework.core.env.Environment;
import org.springframework.core.type.AnnotatedTypeMetadata;
import org.springframework.core.type.AnnotationMetadata;
import org.springframework.data.relational.core.sql.FalseCondition;
import org.springframework.stereotype.Component;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.util.Arrays;

@Component
@Conditional(TrueCondition.class)
class Engine {
    public String toString() {
        return "Engine{}";
    }
}

class Car {
    public String toString() {
        return "Car{}";
    }
}

class SportsCar extends Car {
    public String toString() {
        return "SportsCar{}";
    }
}

class SportsCar2 extends Car {
    public String toString() {
        return "SportsCar2{}";
    }
}

@Component
@Conditional(OsCondition.class)
class Door {
    public String toString() {
        return "Door{}";
    }
}

class TrueCondition implements Condition {
    public boolean matches(ConditionContext context, AnnotatedTypeMetadata metadata) {
        return true;
    }
}

class OsCondition implements Condition {
    public boolean matches(ConditionContext context, AnnotatedTypeMetadata metadata) {
        Environment env = context.getEnvironment();
//        System.out.println("System.getProperties() = " + System.getProperties());
        return env.getProperty("mode").equals("test");
    }
}

@Configuration
@Import({Config1.class, Config2.class})
//@EnableMyAutoConfiguration("test")
class MainConfig { // 자바 설정 파일
    @Bean Car car() { return new Car(); }
}

@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
@Import(MyImportSelector.class)
@interface EnableMyAutoConfiguration {
    String value() default "";
}

class MyImportSelector implements ImportSelector {
    @Override
    public String[] selectImports(AnnotationMetadata importingClassMetadata) {
        AnnotationAttributes attr = AnnotationAttributes.fromMap(importingClassMetadata.getAnnotationAttributes(EnableMyAutoConfiguration.class.getName()));
//        String mode = "test";
        String mode = attr.getString("value");
        if(mode.equals("test")) {
            return new String[] { Config1.class.getName()};
        } else {
            return new String[] { Config2.class.getName()};
        }
    }
}

class Config1 { @Bean Car sportsCar() { return new SportsCar(); }}
class Config2 { @Bean Car sportsCar() { return new SportsCar2(); }}

@EnableConfigurationProperties({MyProperties.class})
//@SpringBootApplication // 아래의 3개 애너테이션을 붙인것과 동일
//@SpringBootConfiguration // @Configuration하고 동일
@Configuration
//@EnableAutoConfiguration
@ComponentScan
public class Main implements CommandLineRunner {
    @Autowired
    MyProperties prop; // 인스턴스 변수, 자동 주입

    @Autowired
    ApplicationContext ac;

    @Override
    public void run(String... args) throws Exception { // 인스턴스 메소드
        String[] beanDefinitionNames = ac.getBeanDefinitionNames();

        Arrays.sort(beanDefinitionNames);
        Arrays.stream(beanDefinitionNames) // 배열을 스트림으로 변환
                .filter(b->!b.startsWith("org"))
                .forEach(System.out::println); // 스트림의 요소를 하나씩 꺼내서 출력.

        System.out.println("prop.getEmail() = " + prop.getEmail());
        System.out.println("prop.getDomain() = " + prop.getDomain());
    }

    public static void main(String[] args) {
        ApplicationContext ac = SpringApplication.run(Main.class, args);
//        ApplicationContext ac = new AnnotationConfigApplicationContext(MainConfig.class, Config1.class, Config2.class); // 자바 설정을 이용하는 AC
//        ApplicationContext ac = new AnnotationConfigApplicationContext(MainConfig.class); // 자바 설정을 이용하는 AC
//        System.out.println("ac = " + ac);
//        String[] beanDefinitionNames = ac.getBeanDefinitionNames();
//
//        Arrays.sort(beanDefinitionNames);
//        Arrays.stream(beanDefinitionNames) // 배열을 스트림으로 변환
//                .filter(b->!b.startsWith("org"))
//                .forEach(System.out::println); // 스트림의 요소를 하나씩 꺼내서 출력.
//        System.out.println("ac.getBean(\"sportsCar\") = " + ac.getBean("sportsCar"));

//        MyProperties prop = ac.getBean(MyProperties.class); // 수동으로 빈을 검색해서 주입
//        System.out.println("prop.getEmail() = " + prop.getEmail());
//        System.out.println("prop.getDomain() = " + prop.getDomain());
    }

    @Bean
    MyBean myBean() { return new MyBean(); }
}

class MyBean {}