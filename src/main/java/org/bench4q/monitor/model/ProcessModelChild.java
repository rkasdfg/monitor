package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class ProcessModelChild {
	private String instanceString;
	private double privateBytes;
	private double processorTimePercent;
private double  processId;
private double virtualBytes;
	public double getProcessorTimePercent() {
	return processorTimePercent;
}
public void setProcessorTimePercent(double processorTimePercent) {
	this.processorTimePercent = processorTimePercent;
}
public double getProcessId() {
	return processId;
}
public void setProcessId(double processId) {
	this.processId = processId;
}
public double getVirtualBytes() {
	return virtualBytes;
}
public void setVirtualBytes(double virtualBytes) {
	this.virtualBytes = virtualBytes;
}
	public String getInstanceString() {
		return instanceString;
	}
	public void setInstanceString(String instanceString) {
		this.instanceString = instanceString;
	}
	public double getPrivateBytes() {
		return privateBytes;
	}
	public void setPrivateBytes(double privateBytes) {
		this.privateBytes = privateBytes;
	}
	
}
