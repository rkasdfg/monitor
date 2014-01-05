package org.bench4q.monitor.api;

import org.bench4q.monitor.model.ProcessorModel;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")

public class ProcessorController {
	
	@RequestMapping("/Processor")
	@ResponseBody
	ProcessorModel getResposeModel(){
		ProcessorModel retModel = new ProcessorModel();
		return retModel;
	}

}
