package com.fastcampus.ch4;

import org.junit.jupiter.api.MethodOrderer;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestMethodOrder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@TestMethodOrder(MethodOrderer.OrderAnnotation.class)
class BoardRepositoryTest {
    @Autowired
    private BoardRepository boardRepo;

//    @Test
//    @Order(4)
//    public void deleteTest() {
//        boardRepo.deleteById(1L); // 1번 게시물 삭제
//
//        // 못찾으면 null 반환
//        Board board = boardRepo.findById(1L).orElse(null);
//        assertTrue(board==null); // 삭제되었으니까 null이어야 함.
//    }
//
//    @Test
//    @Order(3)
//    public void updateTest() {
//        Board board = boardRepo.findById(1L).orElse(null);
//        assertNotNull(board != null);
//
//        board.setTitle("modified title");
//        boardRepo.save(board);
//        Board board2 = boardRepo.findById(1L).orElse(null);
//        System.out.println("board = " + board);
//        System.out.println("board2 = " + board2);
//
//        assertTrue(board.getTitle().equals(board2.getTitle()));
//    }
//
//    @Test
//    @Order(2)
//    public void selectTest() {
////        Board board = boardRepo.findById(1L).get(); // 값이 없을 때 예외 발생
//        Board board = boardRepo.findById(1L).orElse(null); // 값이 없을 때 null 반환
//        System.out.println("board = " + board);
//        assertTrue(board != null);
//    }
//
//    @Test
//    @Order(1)
//    public void insertTest() {
//        Board board = new Board();
//        board.setBno(1L);
//        board.setTitle("Test Title");
//        board.setContent("This is Test");
//        board.setWriter("aaa");
//        board.setViewCnt(0L);
//        board.setInDate(new Date());
//        board.setUpDate(new Date());
//        boardRepo.save(board);
//    }
}