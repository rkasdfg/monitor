package org.bench4q.monitor.service;

import org.bench4q.monitor.model.NetworkInterfaceModel;
import org.bench4q.monitor.model.NetworkInterfaceModelChild;


public class NetworkInterfaceService {
	private NetworkInterfaceModel networkInterfaceMonitor;

	public NetworkInterfaceModel getNetworkInterfaceMonitor() {
		return networkInterfaceMonitor;
	}

	public void setNetworkInterfaceMonitor(
			NetworkInterfaceModel networkInterfaceMonitor) {
		this.networkInterfaceMonitor = networkInterfaceMonitor;
	}

	public NetworkInterfaceService() {
		this.setNetworkInterfaceMonitor(new NetworkInterfaceModel());
	}

	public NetworkInterfaceModel getNetworkInterfaceInfo(int idleTime) {

		return this.networkInterfaceMonitor;
	}
}
