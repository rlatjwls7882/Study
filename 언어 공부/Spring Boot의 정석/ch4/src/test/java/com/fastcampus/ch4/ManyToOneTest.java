package com.fastcampus.ch4;

import jakarta.persistence.EntityManager;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

import java.util.Date;

import static org.junit.jupiter.api.Assertions.assertTrue;

@SpringBootTest
class ManyToOneTest {
    @Autowired
    public EntityManager em;
    @Autowired
    private BoardRepository boardRepository;
    @Autowired
    private UserRepository userRepository;

    @Test
    @Transactional
    public void test() {
        // 1. 테스트 데이터 작성
        User user = new User();
        user.setId("aaa");
        user.setPassword("1234");
        user.setName("LEE");
        user.setEmail("aaa@aaa.com");
        user.setInDate(new Date());
        user.setUpDate(new Date());
        userRepository.save(user);

        Board b1 = new Board();
        b1.setBno(1L);
        b1.setTitle("title1");
        b1.setContent("content1");
        b1.setUser(user);
        b1.setViewCnt(0L);
        b1.setInDate(new Date());
        b1.setUpDate(new Date());
        boardRepository.save(b1);

        Board b2 = new Board();
        b2.setBno(2L);
        b2.setTitle("title2");
        b2.setContent("content2");
        b2.setUser(user);
        b2.setViewCnt(0L);
        b2.setInDate(new Date());
        b2.setUpDate(new Date());
        boardRepository.save(b2);

        b1 = boardRepository.findById(1L).orElse(null);
        b2 = boardRepository.findById(2L).orElse(null);

        System.out.println("b1 = " + b1);
        System.out.println("b2 = " + b2);
        assertTrue(b1!=null);
        assertTrue(b2!=null);

        user = userRepository.findById(user.getId()).orElse(null);
        System.out.println("user = " + user);
        System.out.println("user.getList() = " + user.getList());
        assertTrue(user!=null);
    }
}
