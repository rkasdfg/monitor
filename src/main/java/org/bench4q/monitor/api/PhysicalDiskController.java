package org.bench4q.monitor.api;

import org.bench4q.monitor.model.PhysicalDiskModel;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")

public class PhysicalDiskController {
	@RequestMapping("PhysicalDisk")
	@ResponseBody PhysicalDiskModel getPhysicalDiskModel(){
		PhysicalDiskModel retModel = new PhysicalDiskModel();
		return retModel;
	}

}
