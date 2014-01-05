package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name="Process")
public class ProcessModel {
	private Sigar sigar = new Sigar();
	private List<ProcessModelChild>   processModelList;
	  @XmlElementWrapper 
      @XmlElement(name="Instance",type=ProcessModelChild.class)
	public List<ProcessModelChild> getProcesModelList() {
		return processModelList;
	}
	public void setProcesModelList(List<ProcessModelChild> procesModelList) {
		this.processModelList = procesModelList;
	}
	public ProcessModel(){
		this.processModelList = new ArrayList<ProcessModelChild>();
		try {
			long[] processIdList = sigar.getProcList();
			for(int i = 0; i < processIdList.length; ++i){
				ProcessModelChild processModelChild = new ProcessModelChild(processIdList[i]);
				processModelList.add(processModelChild);
			}
		} catch (SigarException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
