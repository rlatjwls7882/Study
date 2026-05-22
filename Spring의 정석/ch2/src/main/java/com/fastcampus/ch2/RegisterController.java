package com.fastcampus.ch2;

import java.io.IOException;
import java.util.List;

import javax.validation.Valid;

import org.springframework.beans.propertyeditors.StringArrayPropertyEditor;
import org.springframework.core.convert.ConversionService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.Validator;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping("/register")
public class RegisterController {
	@InitBinder
	public void toDate(WebDataBinder binder) {
		ConversionService conversionService = binder.getConversionService();
//		System.out.println("conversionService="+conversionService);
//		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd");
//		binder.registerCustomEditor(Date.class, new CustomDateEditor(df, false));
		binder.registerCustomEditor(String[].class, "hobby", new StringArrayPropertyEditor("#"));
//		binder.setValidator(new UserValidator()); // UserValidator   WebDataBinder        validator      
//		binder.addValidators(new UserValidator()); // UserValidator   WebDataBinder        validator      
		
		List<Validator> validatorList = binder.getValidators();
		System.out.println("validatorList="+validatorList);
	}
	
	@RequestMapping(value="/add", method={RequestMethod.GET, RequestMethod.POST})
	public String register() {
		return "registerForm"; // WEB/INF/views/registerForm.jsp
	}
	
//	@RequestMapping(value="/register/save", method=RequestMethod.POST)
	@PostMapping("/save")  // 4.3부터 
	public String save(@Valid User user, BindingResult result, Model m) throws IOException {
		System.out.println("result="+result);
		System.out.println("user"+user);
		
		//           - Validator             ϰ , validate()        ȣ  
//		UserValidator userValidator = new UserValidator();
//		userValidator.validate(user, result); // BindingResult   Errors    ڼ 
//		
		// User  ü                           , registerForm    ̿  ؼ                  .
		if(result.hasErrors()) {
			return "registerForm";
		}
		
//		// 1.   ȿ    ˻ 
//		if(!isValid(user)) {
//			String msg = URLEncoder.encode("id를 잘못입력하셨습니다.", "utf-8");
//			m.addAttribute("msg", msg);
//			return "forward:/register/add";
////			return "redirect:/register/add?msg="+msg; // URL재작성(rewriting)
//		}
		
		// 2. DB에 신규회원 정보를 저장 
		return "registerInfo";
	}

	private boolean isValid(User user) {
		return true;
	}
}
