package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name="Processor")
public class ProcessorModel {
	private  List<ProcessorModelChild> processorModelList;
	 public ProcessorModel(){
		 processorModelList=new ArrayList<ProcessorModelChild>();
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
