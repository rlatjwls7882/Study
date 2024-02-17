package com.fastcampus.ch2;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

// ������� �Է��ϸ� ������ �˷��ִ� ���α׷�
@Controller
public class YoilTeller {
//	public static void main(String[] args) {
		@RequestMapping("/getYoil")
		public void main(HttpServletRequest request, HttpServletResponse response) throws IOException {
		
		// 1. �Է�
		int yy = Integer.valueOf(request.getParameter("year"));
		int mm = Integer.valueOf(request.getParameter("month"));
		int dd = Integer.valueOf(request.getParameter("day"));
		
		// 2. �۾�
		Calendar cal = Calendar.getInstance();
		cal.set(yy, mm-1, dd);
		
		int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK)-1; // 1:�Ͽ���, 2:������ ...
		char yoil = "�Ͽ�ȭ�������".charAt(dayOfWeek);
		
		// 3. ���
		response.setContentType("text/html");
		response.setCharacterEncoding("utf-8");
		PrintWriter out = response.getWriter(); // response��ü���� ���������� ��� ��Ʈ���� ��´�.
		out.println("<html>");
		out.println("<head>");
		out.println("</head>");
		out.println("<body>");
		out.println(yy+"�� "+mm+"�� "+dd+"���� ");
		out.println(yoil+"�����Դϴ�.");
		out.println("</body>");
		out.println("</html>");
	}
}
