package com.fastcampus.ch4;

import org.aspectj.lang.annotation.Before;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class BoardServiceTest {
    @Autowired
    BoardService boardService;
    @Autowired
    UserRepository userRepository;

    @Test
    public void getListTest() {
        List<Board> list = boardService.getList();
        System.out.println("list = " + list);
        assertEquals(10, list.size());
    }

    @Test
    public void writeAndReadTest() {
        User user = new User();
        user.setId("bbb");
        userRepository.save(user);

        Board board = new Board();
        board.setBno(11L);
        board.setTitle("new Title");
        board.setContent("new Content");
        board.setUser(user);
        board.setViewCnt(0L);
        board.setInDate(new Date());
        board.setUpDate(new Date());
        boardService.write(board);

        Board board2 = boardService.read(11L);
        assertTrue(board2!=null);
        assertEquals(board.getTitle(), board2.getTitle());
        assertEquals(board.getContent(), board2.getContent());
    }

    @Test
    public void modifyTest() {
        Board board = boardService.read(1L);
        board.setTitle("modified title");
        board.setContent("modified content");
        boardService.modify(board);

        Board board2 = boardService.read(1L);
        assertEquals(board.getTitle(), board2.getTitle());
        assertEquals(board.getContent(), board2.getContent());
    }

    @Test
    public void removeTest() {
        Long testBno = 5L;
        assertTrue(boardService.read(testBno)!=null);
        boardService.remove(testBno);
        assertTrue(boardService.read(testBno)==null);
    }

    @BeforeEach
    public void init() {
        for(Long i=1L;i<=10;i++) {
            Board board = new Board();
            board.setBno(i);
            board.setTitle("title"+i);
            board.setContent("content"+i);

            User user = new User();
            user.setId("aaa");
            userRepository.save(user);

            board.setUser(user);
            board.setViewCnt(0L);
            board.setInDate(new Date());
            board.setUpDate(new Date());
            boardService.write(board);
        }
    }
}