package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.DataFomat;
import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.CpuInfo;
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
	private double speed;
	private List<String> cpuInstanceList;
	private int size;

	public static void main(String args[]) {
		try {
			long time = System.currentTimeMillis();
			ProcessorModel processorModel = new ProcessorModel();
			System.out.println(processorModel.getProcessorModelList().size()
					+ " instances");
			System.out.println("privileged time percent"
					+ processorModel.getPrivilegedTimePercent());
			System.out.println("user time percent"
					+ processorModel.getUserTimePercent());
			System.out.println("total time percent:"
					+ processorModel.getProcessorTimePercent());
			System.out.println("speed:" + processorModel.getSpeed());
			System.out.println(System.currentTimeMillis() - time);
		} catch (SigarException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

	public ProcessorModel() throws SigarException {

		cpuPerc = sigar.getCpuPerc();
		this.setPorcessorModelList();
		this.setPrivilegedTimePercent();
		this.setProcessorTimePercent();
		this.setUserTimePercent();
		this.setSpeed();
		this.setCpuInstanceList();
		this.setSize();
	}
	@XmlElement
	public int getSize() {
		return size;
	}

	private void setSize() {
		this.size = this.getProcessorModelList().size();
	}
	

	@XmlElement(name = "processorTimePercent")
	public double getProcessorTimePercent() throws SigarException {
		return this.processorTimePercent;
	}

	private void setProcessorTimePercent() throws SigarException {

		this.processorTimePercent = DataFomat.fomatToPercent(1 - cpuPerc
				.getIdle());
	}

	@XmlElement(name = "privilegedTimePercent")
	public double getPrivilegedTimePercent() {
		return this.privilegedTimePercent;
	}

	private void setPrivilegedTimePercent() {
		this.privilegedTimePercent = DataFomat.fomatToPercent(cpuPerc.getSys());
	}

	@XmlElement(name = "userTimePercent")
	public double getUserTimePercent() throws SigarException {
		return this.userTimePercent;
	}

	private void setUserTimePercent() throws SigarException {
		this.userTimePercent = DataFomat.fomatToPercent(cpuPerc.getUser());
	}

	public double getSpeed() {
		return this.speed;
	}

	private void setSpeed() throws SigarException {
		this.speed = 0;
		CpuInfo[] cpuInfos = GetSigar.getSigar().getCpuInfoList();
		if (cpuInfos != null) {

			this.speed += cpuInfos[0].getMhz();
		}
		long temp = Math.round(this.speed * 100);
		this.speed = temp / 1024L / 100;
	}
@XmlElementWrapper(name="instanceNameList")
	@XmlElement(name="instanceName",type=String.class)
	public List<String> getCpuInstanceList() {
		return cpuInstanceList;
	}

	private void setCpuInstanceList() {
		this.cpuInstanceList = new ArrayList<String>();

		if (this.getProcessorModelList() != null) {
			for (ProcessorModelChild processModelChild : this
					.getProcessorModelList()) {
				this.cpuInstanceList.add(processModelChild.getInstance());
			}
		}

	}
	@XmlElementWrapper(name = "processorlist")
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
}
