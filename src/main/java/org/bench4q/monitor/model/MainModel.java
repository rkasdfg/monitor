package org.bench4q.monitor.model;

import org.bench4q.monitor.model.*;

import java.util.Date;
import java.text.SimpleDateFormat;

import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

@XmlRootElement(name="history")
@XmlType
public class MainModel {
	@XmlElement
	private String date;
	@XmlElement(name="process_info")
	private ProcessorModel processorModel;
	@XmlElement(name="memory_info")
	private MemoryModel memoryModel;
	@XmlElement(name="disk_info")
	private PhysicalDiskModel physicalDiskModel;
	@XmlElement(name="network_info")
	private NetworkInterfaceModel networkInterfaceModel;
	
	private SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
	
	public MainModel(){
		
	}
	
	public MainModel(Date date){
		this.date = dateFormat.format(date);
		processorModel = new ProcessorModel();
		memoryModel = new MemoryModel();
		physicalDiskModel = new PhysicalDiskModel();
		networkInterfaceModel = new NetworkInterfaceModel();
	}
}