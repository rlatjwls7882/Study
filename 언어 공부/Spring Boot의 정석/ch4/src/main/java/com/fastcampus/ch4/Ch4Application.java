package com.fastcampus.ch4;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.EntityTransaction;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import javax.swing.*;
import java.util.Date;

@SpringBootApplication
public class Ch4Application implements CommandLineRunner {
    @Autowired
    EntityManagerFactory emf;
    public static void main(String[] args) {
        SpringApplication app = new SpringApplication(Ch4Application.class);
//        app.setWebApplicationType(WebApplicationType.NONE);
        app.run(args);
    }

    @Override
    public void run(String... args) throws Exception {
//        EntityManager em = emf.createEntityManager();
//        System.out.println("emf = " + emf);
//        EntityTransaction tx = em.getTransaction();
//
//
//        User user = new User();
//        user.setId("aaa");
//        user.setPassword("1234");
//        user.setName("Lee");
//        user.setEmail("aaa@aaa.com");
//        user.setInDate(new Date());
//        user.setUpDate(new Date());
//
//        tx.begin(); // 트랜젝션 시작
//
//        // 1. 저장
//        em.persist(user); // user엔티티를 em에 영속화(저장)
//        em.persist(user); // 같은 user엔티티를 여러번 저장해도 한번만 insert
//
//        // 2. 변경
//        user.setPassword("4321"); // PersistenceContext가 변경감지. update 실행
//        user.setEmail("bbb@bbb.com");
//        tx.commit(); // 트랜젝션 종료(DB에 반영)
//
//        // 3. 조회
//        User user2 = em.find(User.class, "aaa"); // em에 있으면 DB조회 안함
//        System.out.println("(user==user2) = " + (user == user2));
//        User user3 = em.find(User.class, "bbb"); // em에 없으면 DB조회
//        System.out.println("user3 = " + user3); // null, DB에 없음
//
//        // 4. 삭제
//        tx.begin();
//        em.remove(user); // em에서 user엔티티를 삭제
//        tx.commit();
    }
}
