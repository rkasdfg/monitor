package org.bench4q.monitor.model;

import java.util.Date;
import java.util.TimeZone;
import java.util.concurrent.ExecutionException;
import java.text.SimpleDateFormat;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "history")
@XmlType
public class MainModel {
	@XmlElement
	private String date;
	@XmlElement(name = "processor_info")
	private ProcessorModel processorModel;
	@XmlElement(name = "memory_info")
	private MemoryModel memoryModel;
	@XmlElement(name = "disk_info")
	private PhysicalDiskModel physicalDiskModel;
	@XmlElement(name = "network_info")
	private NetworkInterfaceModel networkInterfaceModel;
	@XmlElement(name = "process_info")
	private ProcessModel processModel;
	private SimpleDateFormat dateFormat = new SimpleDateFormat(
			"yyyy-MM-dd-HH-mm-ss");

	public MainModel() {

	}

	public MainModel(Date date) throws SigarException, InterruptedException,
			ExecutionException {
		dateFormat.setTimeZone(TimeZone.getTimeZone("Asia/Shanghai"));
		this.date = dateFormat.format(date);
		long start=System.currentTimeMillis();
		
		processorModel = new ProcessorModel();
		long end=System.currentTimeMillis();
		System.out.println("processor"+(end-start));
		start=end;
		memoryModel = new MemoryModel();
		 end=System.currentTimeMillis();
		System.out.println("mem"+(end-start));
		start=end;
		physicalDiskModel = new PhysicalDiskModel();
		 end=System.currentTimeMillis();
			System.out.println("phy"+(end-start));
			start=end;
		networkInterfaceModel = new NetworkInterfaceModel();
		 end=System.currentTimeMillis();
			System.out.println("net"+(end-start));
			start=end;
		processModel=new ProcessModel();
		 end=System.currentTimeMillis();
			System.out.println("proc"+(end-start));
			start=end;
	}
}
