package org.bench4q.monitor.api;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import org.bench4q.monitor.model.ListMainModel;
import org.bench4q.monitor.model.MainModel;
import org.bench4q.monitor.service.ReadSystemInfoFromLocalDisk;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class HistoryDataController {
	@RequestMapping("history")
	@ResponseBody List<MainModel> getHistory(@RequestParam String starttime, @RequestParam String endtime) throws ParseException
	{
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
		Date startDate = dateFormat.parse(starttime);
		Date endDate = dateFormat.parse(endtime);
		ReadSystemInfoFromLocalDisk historyservice = new ReadSystemInfoFromLocalDisk();
		ListMainModel retModel = new ListMainModel();
		//retModel.setHistorylist(historyservice.ReadSystemInfoByDate(startDate, endDate));
		return historyservice.ReadSystemInfoByDate(startDate, endDate);
	}

}
