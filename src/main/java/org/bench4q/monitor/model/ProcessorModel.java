package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;
import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.CpuPerc;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "Processors")
public class ProcessorModel {
	private List<ProcessorModelChild> processorModelList;
	private Sigar sigar = GetSigar.getSigar();
	private CpuPerc cpuPerc;
	private double processorTimePercent;
	private double privilegedTimePercent;
	private double userTimePercent;

	 
	public static void main(String args[]) {
		try {
			long time = System.currentTimeMillis();
			ProcessorModel processorModel = new ProcessorModel();
			System.out.println(processorModel.getProcessorModelList().size()
					+ " instances");
			System.out.println("system time percent"
					+ processorModel.getPrivilegedTimePercent());
			System.out.println("user time percent"
					+ processorModel.getUserTimePercent());
			System.out.println("time percent:"
					+ processorModel.getProcessorTimePercent());
			System.out.println(System.currentTimeMillis() - time);

		} catch (SigarException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

	
	/*public List<String> getProcessNameList(){
		List<String> processNameList=new ArrayList<String>();
		if(this.getProcessorModelList()!=null){
			for(ProcessModelChild pro)
		}
		
	}*/
	public ProcessorModel() throws SigarException {

		cpuPerc = sigar.getCpuPerc();
		this.setPorcessorModelList();
		this.setPrivilegedTimePercent();
		this.setProcessorTimePercent();
		this.setUserTimePercent();
	}

	@XmlElementWrapper(name = "processors")
	@XmlElement(name = "processor", type = ProcessorModelChild.class)
	public List<ProcessorModelChild> getProcessorModelList() {
		return processorModelList;
	}

	private void setPorcessorModelList() throws SigarException {
		this.processorModelList = new ArrayList<ProcessorModelChild>();
		CpuPerc[] cpuPercList = sigar.getCpuPercList();
		for (int i = 0; i < cpuPercList.length; ++i) {
			ProcessorModelChild processorModelChild = new ProcessorModelChild(
					i, cpuPercList[i]);
			processorModelList.add(processorModelChild);
		}

	}

	@XmlElement(name = "processorTimePercent")
	public double getProcessorTimePercent() throws SigarException {
		return this.processorTimePercent;
	}

	private void setProcessorTimePercent() throws SigarException {

		this.processorTimePercent = Math.round(cpuPerc.getCombined() * 10000) / 100.0;
	}

	@XmlElement(name = "privilegedTimePercent")
	public double getPrivilegedTimePercent() {
		return this.privilegedTimePercent;
	}

	private void setPrivilegedTimePercent() {
		this.privilegedTimePercent = Math.round(cpuPerc.getSys() * 10000) / 100.0;
	}

	@XmlElement(name = "userTimePercent")
	public double getUserTimePercent() throws SigarException {
		return this.userTimePercent;
	}

	private void setUserTimePercent() throws SigarException {
		this.userTimePercent = Math.round(cpuPerc.getUser() * 10000) / 100.0;
	}

}
