package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name="Process")
public class ProcessModel {
	
	private List<ProcessModelChild>   procesModelList;
	  @XmlElementWrapper 
      @XmlElement(name="Instance",type=ProcessModelChild.class)
	public List<ProcessModelChild> getProcesModelList() {
		return procesModelList;
	}
	public void setProcesModelList(List<ProcessModelChild> procesModelList) {
		this.procesModelList = procesModelList;
	}
	public ProcessModel(){
		this.procesModelList=new ArrayList<ProcessModelChild>();
	}
	
  
	
}
