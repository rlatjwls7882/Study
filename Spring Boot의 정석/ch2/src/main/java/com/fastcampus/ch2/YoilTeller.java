package com.fastcampus.ch2;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

// 년월일을 입력하면 요일을 알려주는 원격 프로그램
@Controller
public class YoilTeller {
    @RequestMapping("/getYoil")
    public String main(@ModelAttribute MyDate myDate, Model model) throws IOException {

        // 2. 작업 - 요일을 계산
        char yoil = getYoil(myDate);

        // 작업한 결과를 Model에 저장(DS가 Model을 View로 전달)
//        model.addAttribute("myDate", myDate);
//        model.addAttribute("year", myDate.getYear());
//        model.addAttribute("month", myDate.getMonth());
//        model.addAttribute("day", myDate.getDay());
//        model.addAttribute("yoil", yoil);

        return "yoil"; // yoil.html - 뷰의 이름을 반환
    }

    @ModelAttribute("yoil")
    private static char getYoil(MyDate myDate) {
        Calendar cal = Calendar.getInstance(); // 현재 날짜와 시간을 갖는 cal
        cal.clear(); // cal의 모든 필드를 초기화
        cal.set(myDate.getYear(), myDate.getMonth()-1, myDate.getDay()); // 월(m)은 0~11이기 때문에 1을 뺴줘야함.

        int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK); // 1~7을 반환. 1: 일요일, 2: 월요일
        char yoil = "일월화수목금토일".charAt(dayOfWeek-1); // 1~7 -> 0~6
        return yoil;
    }
}
