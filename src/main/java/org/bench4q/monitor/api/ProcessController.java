package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.ProcessModel;
import org.bench4q.monitor.service.ProcessServiceWindows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class ProcessController extends MonitorContorlEntity {

	@RequestMapping("/Process")
	@ResponseBody
	public ProcessModel getProcessInfo() throws IOException,
			InterruptedException {


			ProcessServiceWindows processServiceWindows = new ProcessServiceWindows();
			return processServiceWindows.getProcessInfo(this.getIdleTime());
	
	}

}
