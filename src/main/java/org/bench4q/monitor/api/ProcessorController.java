package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.ProcessorModel;
import org.bench4q.monitor.service.ProcessorServiceWindows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class ProcessorController extends MonitorContorlEntity {

	@RequestMapping("/Processor")
	@ResponseBody
	public ProcessorModel getProcessorInfo() throws IOException, InterruptedException {


			ProcessorServiceWindows processorServiceWindows=new ProcessorServiceWindows();
			return processorServiceWindows.getProcessorInfo(
					this.getIdleTime());
	}

}
