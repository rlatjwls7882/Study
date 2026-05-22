package com.fastcampus.ch2;

import jakarta.servlet.http.HttpServletRequest;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.net.URLEncoder;

@Controller
@RequestMapping("/login")
public class LoginController {
//    @RequestMapping(value = "/login/login", method = RequestMethod.GET)
    @GetMapping("/login")
    public String login() {
        return "login"; // login.html
    }

//    @RequestMapping(value = "/login/login", method = {RequestMethod.POST, RequestMethod.GET})
//    @RequestMapping(value = "/login/login", method = RequestMethod.POST)
    @PostMapping("/login")
    public String login(HttpServletRequest request, String id, String pwd, RedirectAttributes model) throws Exception {
        // 1. id, pwd를 확인
        if(loginCheck(id, pwd)) {
            model.addAttribute("id", id);
            model.addAttribute("pwd", pwd);
            return "userInfo"; // userInfo.html
        } else {
            model.addAttribute("msg", "id 또는 pwd가 일치하지 않습니다.");
            model.addFlashAttribute("msg", "일회용 메세지");
            request.setAttribute("msg", "request에 저장된 메세지");

            return "redirect:/login/login";
//            return "forward:/"; // /login/login POST
//            String msg = URLEncoder.encode("id 또는 pwd가 일치하지 않습니다.", "utf-8");
//            return "redirect:/login/login?msg="+msg; // GET - URL재삭성
        }
    }

    private boolean loginCheck(String id, String pwd) {
        return id.equals("asdf") && pwd.equals("1234");
    }
}
