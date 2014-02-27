package org.bench4q.monitor.api;

import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import javax.xml.bind.annotation.XmlElement;

import org.bench4q.monitor.model.MainModel;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


@Controller
@RequestMapping("/Monitor")
public class MainController {
	@RequestMapping("/All")
	@ResponseBody MainModel getMainModel() throws SigarException{
		Date date = new Date();
		MainModel retModel = new MainModel(date);
		return retModel;
	}

}
