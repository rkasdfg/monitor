package org.bench4q.monitor.service;

import org.bench4q.monitor.model.ProcessModel;
import org.bench4q.monitor.model.SystemModel;

public class SystemServiceWindows {
	
	public SystemServiceWindows(){
		this.systemMonitor=new SystemModel();
		this.processorMonitor=new ProcessModel();
	}
	private SystemModel systemMonitor;
	private ProcessModel processorMonitor;
	public SystemModel getSystemMonitor() {
		return systemMonitor;
	}
	public void setSystemMonitor(SystemModel systemMonitor) {
		this.systemMonitor = systemMonitor;
	}
	public ProcessModel getProcessorMonitor() {
		return processorMonitor;
	}
	public void setProcessorMonitor(ProcessModel processorMonitor) {
		this.processorMonitor = processorMonitor;
	}
	
	public SystemModel getSystemInfo(int idleTime){

		return this.systemMonitor;
	}
}
