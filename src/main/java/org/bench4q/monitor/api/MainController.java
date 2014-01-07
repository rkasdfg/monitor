package org.bench4q.monitor.api;

import java.util.Date;

import org.bench4q.monitor.model.MainModel;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


@Controller
@RequestMapping("/Monitor")
public class MainController {
	@RequestMapping("/All")
	@ResponseBody MainModel getMainModel(){
		Date date = new Date();
		MainModel retModel = new MainModel(date);
		return retModel;
	}

}
