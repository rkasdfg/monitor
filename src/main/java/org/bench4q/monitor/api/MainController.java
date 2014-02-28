package org.bench4q.monitor.api;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.concurrent.ExecutionException;

import org.bench4q.monitor.model.MainModel;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class MainController {
	@RequestMapping("/All")
	@ResponseBody
	MainModel getMainModel() throws SigarException, InterruptedException, ExecutionException {
		Date date = new Date();
		MainModel retModel = new MainModel(date);
		return retModel;
	}

	@RequestMapping("/test")
	@ResponseBody
	List<String> set() throws SigarException {
		List<String> testList = new ArrayList<String>();
		testList.add("hello");
		testList.add("pp");
		return testList;
	}

}
