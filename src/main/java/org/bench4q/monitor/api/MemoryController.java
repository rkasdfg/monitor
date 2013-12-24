package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.MemoryModel;
import org.bench4q.monitor.service.MemoryServiceWindows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class MemoryController extends MonitorContorlEntity {

	@RequestMapping(value = "/Memory", method = { RequestMethod.GET,
			RequestMethod.POST })
	@ResponseBody
	public MemoryModel getMemoryInfo() throws NumberFormatException,
			IOException {

			MemoryServiceWindows memoryServiceWindows = new MemoryServiceWindows();

			return memoryServiceWindows.getMemoryInfo(this.getIdleTime());

	}
}
