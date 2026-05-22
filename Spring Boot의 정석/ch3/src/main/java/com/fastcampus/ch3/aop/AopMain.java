package com.fastcampus.ch3.aop;

import org.springframework.transaction.annotation.Transactional;

import java.lang.reflect.Method;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class AopMain {
    public static void main(String[] args) throws Exception {
        Class myClass = Class.forName("com.fastcampus.ch3.aop.MyClass");
        Object obj = myClass.newInstance();

        MyAdvice myAdvice = new MyAdvice();

        for(Method m : myClass.getDeclaredMethods()) {
            myAdvice.invoke(m, obj, null);
        }
    }
}

class MyAdvice {
    Pattern p = Pattern.compile("a.*"); // a로 시작하는 문자열

    boolean matches(Method m) { // 지정된 메서드가 패턴에 일치하는지 알려줌.
        Matcher matcher = p.matcher(m.getName());
        return matcher.matches();
    }

    void invoke(Method m, Object obj, Object... args) throws Exception {
        if(m.getAnnotation(Transactional.class) != null)
            System.out.println("[before]]{"); // 공통으로 들어갈 코드

        m.invoke(obj, args); // aaa() aaa2() bbb()

        if(m.getAnnotation(Transactional.class) != null)
            System.out.println("}[after]"); // 공통으로 들어갈 코드
    }
}

class MyClass {
    @Transactional
    void aaa() {
        System.out.println("aaa() is called");
    }
    void aaa2() {
        System.out.println("aaa2() is called");
    }
    void bbb() {
        System.out.println("bbb() is called");
    }
}