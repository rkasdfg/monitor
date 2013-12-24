package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.PhysicalDiskModel;
import org.bench4q.monitor.service.PhysicalDiskService;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class PhysicalDiskController extends MonitorContorlEntity {

	@RequestMapping("/PhysicalDisk")
	@ResponseBody
	public PhysicalDiskModel getPhysicalDislInfo() throws IOException,
			InterruptedException {
			PhysicalDiskService physicalDiskService = new PhysicalDiskService();
			return physicalDiskService.getPhysicalDiskInfo(this
					.getIdleTime());


	}
}
