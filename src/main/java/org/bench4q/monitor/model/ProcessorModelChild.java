package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.CpuPerc;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement
public class ProcessorModelChild {
	private String instance;
	private Double processorTimePercent;
	private Double userTimePercent;
	private Double privilegedTimePercent;
	private CpuPerc cpuPerc;
	private Sigar sigar = new Sigar();
	private int id;
	
	
	public ProcessorModelChild(int id){
		this.id = id;
		this.setInstance("Cpu"+id);
	}
	
	public String getInstance() {
		return instance;
	}
	public void setInstance(String instance) {
		this.instance = instance;
	}
	public Double getProcessorTimePercent() {
		try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}
		this.setProcessorTimePercent(this.cpuPerc.getCombined());
		return processorTimePercent;
	}
	public void setProcessorTimePercent(Double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}
	public Double getUserTimePercent() {
		try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}
		this.setUserTimePercent(cpuPerc.getUser());
		return userTimePercent;
	}
	public void setUserTimePercent(Double userTimePercent) {
		this.userTimePercent = userTimePercent;
	}
	public Double getPrivilegedTimePercent() {
		try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}
		this.setPrivilegedTimePercent(cpuPerc.getSys());
		return privilegedTimePercent;
	}
	public void setPrivilegedTimePercent(Double privilegedTimePercent) {
		this.privilegedTimePercent = privilegedTimePercent;
	}
}
