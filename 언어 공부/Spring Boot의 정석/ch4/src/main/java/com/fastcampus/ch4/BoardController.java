package com.fastcampus.ch4;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Controller
@RequestMapping("/board")
public class BoardController {
    @Autowired
    BoardService boardService;

    @Value("${uploadPath}")
    private String uploadPath;

    @GetMapping("/uploadForm")
    public String showUploadForm() {
        return "board/uploadFile";
    }

//    @PostMapping("/uploadFile")
//    public void uploadFile(MultipartFile[] files) throws IOException {
//        for(MultipartFile file : files) {
//            System.out.println("file.getOriginalFilename() = " + file.getOriginalFilename());
//            System.out.println("file.getSize() = " + file.getSize());
//
//            File upFile = new File(uploadPath, file.getOriginalFilename());
//            file.transferTo(upFile); // 업로드된 파일을 C:/upload에 저장
//        }
//    }

    @PostMapping("/uploadAjax")
    @ResponseBody
    public ResponseEntity<List<String>> uploadFile(MultipartFile[] files) throws IOException {
        List<String> list = new ArrayList<>();

        for(MultipartFile file : files) {
            System.out.println("file.getOriginalFilename() = " + file.getOriginalFilename());
            System.out.println("file.getSize() = " + file.getSize());

            File upFile = new File(uploadPath, file.getOriginalFilename());
            file.transferTo(upFile); // 업로드된 파일을 C:/upload에 저장
            list.add(file.getOriginalFilename());
        }
        return new ResponseEntity<>(list, HttpStatus.OK);
    }

    @GetMapping(value = "/download", produces = MediaType.APPLICATION_OCTET_STREAM_VALUE)
    @ResponseBody
    public ResponseEntity<Resource> downbloadFile(String fileName) {
        System.out.println("fileName = " + fileName);
        Resource resource = new FileSystemResource(uploadPath+fileName);

        return new ResponseEntity<>(resource, HttpStatus.OK);
    }

    @PostMapping("/deleteFile")
    public ResponseEntity<String> deleteFile(String fileName) {
        System.out.println("fileName = " + fileName);
        File file = new File(uploadPath+fileName);
        if(file.delete()==true) {
            return new ResponseEntity<>("삭제 성공", HttpStatus.OK);
        } else {
            return new ResponseEntity<>("삭제 실패", HttpStatus.NOT_FOUND);
        }
    }

    @GetMapping("/modify")
    public String modify(Long bno, Model model) {
        Board board = boardService.read(bno);
        model.addAttribute("board", board);
        return "board/write";
    }

    @PostMapping("/modify")
    public String modify(Board board) {
        boardService.modify(board);
        return "redirect:/board/list";
    }

    @GetMapping("/write")
    public String showWriteForm(Model model) {
        Board board = new Board();
        User user = new User();
        user.setId("bbb");
        board.setUser(user);

        model.addAttribute("board", board);
        return "board/write";
    }

    @PostMapping("/write")
    public String write(Board board) {
        board.setBno(11L); // 자동 증가 기능 사용하는게 바람직.
        User user = new User();
        user.setId("bbb");
        board.setUser(user);
        board.setViewCnt(0L);
        board.setInDate(new Date());
        board.setUpDate(new Date());
        boardService.write(board);
        return "redirect:/board/list"; // 글을 삭제한 다음에는 게시물 목록으로 이동
    }

    @PostMapping("/remove")
    public String remove(long bno) {
        boardService.remove(bno);
        return "redirect:/board/list"; // 게시물 삭제후에 게시물 목록으로 이동
    }

    @GetMapping("/read")
    public String read(Long bno, Model model) {
        Board board = boardService.read(bno);
        model.addAttribute("board", board);
        return "board/read";
    }

    @GetMapping("/list")
    public String getList(Model model) {
        List<Board> list = boardService.getList();
        model.addAttribute("list", list);
        return "board/list";
    }
}
