package org.bench4q.monitor.api;

import java.io.IOException;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.model.NetworkInterfaceModel;
import org.bench4q.monitor.service.NetworkInterfaceService;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/Monitor")
public class NetworkInterfaceController extends MonitorContorlEntity {

	@RequestMapping("/NetworkInterface")
	@ResponseBody
	public NetworkInterfaceModel getNetworkInterfaceInfo() throws IOException,
			InterruptedException {
			NetworkInterfaceService networkInterfaceServiceWindows = new NetworkInterfaceService();
			return networkInterfaceServiceWindows.getNetworkInterfaceInfo(this
					.getIdleTime());
	
	}

}
