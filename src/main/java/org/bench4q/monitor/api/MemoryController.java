package org.bench4q.monitor.api;

import org.bench4q.monitor.model.MemoryModel;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class MemoryController {
	@RequestMapping("/Memory")
	@ResponseBody
	MemoryModel getMemoryModel()
	{
		MemoryModel retModel = new MemoryModel();
		return retModel;
	}

}
