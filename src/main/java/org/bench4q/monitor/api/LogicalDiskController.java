package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.LogicalDiskModel;
import org.bench4q.monitor.service.LogicalDiskServiceWindows;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping(value = "/Monitor", method = { RequestMethod.GET,
		RequestMethod.POST })
public class LogicalDiskController extends MonitorContorlEntity {// �Ժ�ʵ��linux��Ҫ����linux��dervice
	@RequestMapping("/LogicalDisk")
	@ResponseBody
	public LogicalDiskModel getLogicalDiskInfo() throws IOException,
			InterruptedException {

			LogicalDiskServiceWindows logicalDiskServiceWindows = new LogicalDiskServiceWindows();
			return logicalDiskServiceWindows.getLogicalDiskInfo(this
					.getIdleTime());
		

	}

}
