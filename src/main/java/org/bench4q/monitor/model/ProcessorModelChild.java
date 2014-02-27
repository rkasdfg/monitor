package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.CpuPerc;
import org.hyperic.sigar.SigarException;

@XmlRootElement
public class ProcessorModelChild {
	private String instance;
	private double processorTimePercent;
	private double userTimePercent;
	private double privilegedTimePercent;
	private CpuPerc cpuPerc;
	public static void main(String[] agrs) throws SigarException {
		long time = System.currentTimeMillis();
		ProcessorModelChild testModel = new ProcessorModelChild(0, GetSigar
				.getSigar().getCpuPercList()[0]);
		System.out.println(testModel.getPrivilegedTimePercent());
		System.out.println(testModel.getUserTimePercent());
		System.out.println(testModel.getProcessorTimePercent());
		System.out.println(System.currentTimeMillis() - time);
	}

	public ProcessorModelChild() {

	}

	public ProcessorModelChild(int id, CpuPerc cpuPerc) throws SigarException {
		this.setInstance("Cpu" + id);
		this.cpuPerc = cpuPerc;
		this.getPrivilegedTimePercent();
		this.getProcessorTimePercent();
		this.getUserTimePercent();
	}

	@XmlElement
	public String getInstance() {
		return this.instance;
	}

	public void setInstance(String instance) {
		this.instance = instance;
	}

	@XmlElement
	public double getProcessorTimePercent() {
		long temp = Math.round(cpuPerc.getCombined() * 10000);
		this.setProcessorTimePercent(temp / 100.0);
		return processorTimePercent;
	}

	public void setProcessorTimePercent(double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}

	@XmlElement
	public double getUserTimePercent() throws SigarException {
		long temp = Math.round(cpuPerc.getUser() * 10000);
		this.setUserTimePercent(temp / 100.0);
		return this.userTimePercent;
	}

	public void setUserTimePercent(double userTimePercent) {
		this.userTimePercent = userTimePercent;
	}

	@XmlElement
	public double getPrivilegedTimePercent() throws SigarException {
		long temp = Math.round(cpuPerc.getSys() * 10000);
		this.setPrivilegedTimePercent(temp / 100.0);
		return this.privilegedTimePercent;
	}

	public void setPrivilegedTimePercent(double privilegedTimePercent) {
		this.privilegedTimePercent = privilegedTimePercent;
	}
}
