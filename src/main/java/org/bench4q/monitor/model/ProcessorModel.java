package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.CpuPerc;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name="Processor")
public class ProcessorModel {
	private  List<ProcessorModelChild> processorModelList;
	private Sigar sigar = new Sigar();
	
	public ProcessorModel(){
		processorModelList = new ArrayList<ProcessorModelChild>();
		try {
			CpuPerc[] cpuPercList = sigar.getCpuPercList();
			for(int i = 0; i < cpuPercList.length; ++i){
				ProcessorModelChild processorModelChild = new ProcessorModelChild(i);
				processorModelList.add(processorModelChild);
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
		 
	}
	 @XmlElementWrapper
	 @XmlElement(name="processorModelChild",type=ProcessorModelChild.class)            
	public List<ProcessorModelChild> getProcessorModelList() {
		return processorModelList;
	}
	public void setProcessorModelList(List<ProcessorModelChild> processorModelList) {
		this.processorModelList = processorModelList;
	}
}
