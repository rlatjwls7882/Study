package com.fastcampus.ch2;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

// 년월일을 입력하면 요일을 알려주는 프로그램
@Controller
public class YoilTeller {
//	public static void main(String[] args) {
		@RequestMapping("/getYoil")
		public void main(HttpServletRequest request, HttpServletResponse response) throws IOException {
		
		// 1. 입력
		int yy = Integer.valueOf(request.getParameter("year"));
		int mm = Integer.valueOf(request.getParameter("month"));
		int dd = Integer.valueOf(request.getParameter("day"));
		
		// 2. 작업
		Calendar cal = Calendar.getInstance();
		cal.set(yy, mm-1, dd);
		
		int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK)-1; // 1:일요일, 2:월요일 ...
		char yoil = "일월화수목금토".charAt(dayOfWeek);
		
		// 3. 출력
		response.setContentType("text/html");
		response.setCharacterEncoding("utf-8");
		PrintWriter out = response.getWriter(); // response객체에서 브라우저로의 출력 스트림을 얻는다.
		out.println("<html>");
		out.println("<head>");
		out.println("</head>");
		out.println("<body>");
		out.println(yy+"년 "+mm+"월 "+dd+"일은 ");
		out.println(yoil+"요일입니다.");
		out.println("</body>");
		out.println("</html>");
	}
}
