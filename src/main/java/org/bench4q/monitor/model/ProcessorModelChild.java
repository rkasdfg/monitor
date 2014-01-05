package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.CpuPerc;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement
public class ProcessorModelChild {
	private String instance;
	private double processorTimePercent;
	private double userTimePercent;
	private double privilegedTimePercent;
	
	private CpuPerc cpuPerc;
	private Sigar sigar = new Sigar();
	private int id;
	
	//test code
	public static void main(String[] agrs){
		ProcessorModelChild testModel = new ProcessorModelChild(0);
		System.out.println(testModel.getPrivilegedTimePercent());
		System.out.println(testModel.getUserTimePercent());
		System.out.println(testModel.getProcessorTimePercent());
	}
	
	public ProcessorModelChild(){
		
	}
	
	public ProcessorModelChild(int id){
		this.id = id;
		this.setInstance("Cpu"+id);
		try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}
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
	public String getProcessorTimePercent() {
		/*try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}*/
		this.setProcessorTimePercent(this.cpuPerc.getCombined());
		return CpuPerc.format(processorTimePercent);
	}
	public void setProcessorTimePercent(Double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}
	
	@XmlElement
	public String getUserTimePercent() {
		/*try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}*/
		this.setUserTimePercent(cpuPerc.getUser());
		return CpuPerc.format(userTimePercent);
	}
	public void setUserTimePercent(Double userTimePercent) {
		this.userTimePercent = userTimePercent;
	}
	
	@XmlElement
	public String getPrivilegedTimePercent() {
		/*try {
			cpuPerc = sigar.getCpuPercList()[id];
		} catch (SigarException e) {
			e.printStackTrace();
		}*/
		this.setPrivilegedTimePercent(cpuPerc.getSys());
		return CpuPerc.format(privilegedTimePercent);
	}
	public void setPrivilegedTimePercent(Double privilegedTimePercent) {
		this.privilegedTimePercent = privilegedTimePercent;
	}
}
