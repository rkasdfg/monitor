package org.bench4q.monitor.model;



import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;


@XmlRootElement(name = "LogicalDisk")
public class LogicalDiskModel {
	
	

	private  List<LogicalDiskModelChild> logicalDiskList;
	  public LogicalDiskModel(){
		  this.logicalDiskList=new ArrayList<LogicalDiskModelChild>();
	  }
	
	  @XmlElementWrapper
      @XmlElement(name="Instance",type=LogicalDiskModelChild.class)          
      
	public List<LogicalDiskModelChild> getLogicalDiskList() {
		return logicalDiskList;
	}
	public void setLogicalDiskList ( ArrayList<LogicalDiskModelChild>  logicalDiskList) {
		this.logicalDiskList = logicalDiskList;
	}
}