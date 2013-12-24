package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.SystemModel;
import org.bench4q.monitor.service.SystemServiceWindows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class SystemController extends MonitorContorlEntity {
	@ResponseBody
	@RequestMapping("/System")
	public SystemModel getSystemInfo() throws IOException, InterruptedException {
			SystemServiceWindows systemServiceWindows = new SystemServiceWindows();
			return systemServiceWindows.getSystemInfo(this.getIdleTime());

	}
}
