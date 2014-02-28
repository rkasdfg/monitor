package org.bench4q.monitor.api;

import org.bench4q.monitor.model.MemoryModel;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/monitor")
public class MemoryController {
	@RequestMapping("/memory")
	@ResponseBody
	MemoryModel getMemoryModel() throws SigarException
	{
		MemoryModel retModel = new MemoryModel();
		return retModel;
	}
}
