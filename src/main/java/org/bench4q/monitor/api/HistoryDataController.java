package org.bench4q.monitor.api;

import java.util.List;

import org.bench4q.monitor.model.MainModel;
import org.bench4q.monitor.service.ReadSystemInfoFromLocalDisk;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class HistoryDataController {
	@RequestMapping("history")
	@ResponseBody List<MainModel> getHistory()
	{
		ReadSystemInfoFromLocalDisk historyservice = new ReadSystemInfoFromLocalDisk();
		return historyservice.ReadSystemInfoByDate(null, null);
	}

}
