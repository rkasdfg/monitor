package org.bench4q.monitor.service;

import org.bench4q.monitor.model.PhysicalDiskModel;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PhysicalDiskService {
	private PhysicalDiskModel physicalDiskMonitor;

	public PhysicalDiskModel getPhysicalDiskrMonitor() {
		return physicalDiskMonitor;
	}
	@Autowired
	public void setPhysicalDiskrMonitor(PhysicalDiskModel physicalDiskrMonitor) {
		this.physicalDiskMonitor = physicalDiskrMonitor;
	}

	public PhysicalDiskModel getPhysicalDiskInfo(int idleTime) {

		return this.physicalDiskMonitor;
	}

}
