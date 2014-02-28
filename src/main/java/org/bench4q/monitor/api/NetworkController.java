package org.bench4q.monitor.api;

import org.bench4q.monitor.model.NetworkInterfaceModel;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/monitor")
public class NetworkController {
	
	@RequestMapping("/network")
	@ResponseBody NetworkInterfaceModel getNetworkInterfaceModel(){
		NetworkInterfaceModel retModel = new NetworkInterfaceModel();
		return retModel;
	}

}
