package org.bench4q.monitor.api;

import java.util.concurrent.ExecutionException;

import org.bench4q.monitor.model.PhysicalDiskModel;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")

public class PhysicalDiskController {
	@RequestMapping("PhysicalDisk")
	@ResponseBody PhysicalDiskModel getPhysicalDiskModel() throws SigarException, InterruptedException, ExecutionException{
		PhysicalDiskModel retModel = new PhysicalDiskModel();
		return retModel;
	}

}
