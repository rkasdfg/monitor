package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class ProcessorModelChild {
	private String instance;
	private Double processorTimePercent;
	private Double  userTimePercent;
	private Double privilegedTimePercent;
	
	public String getInstance() {
		return instance;
	}
	public void setInstance(String instance) {
		this.instance = instance;
	}
	public Double getProcessorTimePercent() {
		return processorTimePercent;
	}
	public void setProcessorTimePercent(Double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}
	public Double getUserTimePercent() {
		return userTimePercent;
	}
	public void setUserTimePercent(Double userTimePercent) {
		this.userTimePercent = userTimePercent;
	}
	public Double getPrivilegedTimePercent() {
		return privilegedTimePercent;
	}
	public void setPrivilegedTimePercent(Double privilegedTimePercent) {
		this.privilegedTimePercent = privilegedTimePercent;
	}
	
}
