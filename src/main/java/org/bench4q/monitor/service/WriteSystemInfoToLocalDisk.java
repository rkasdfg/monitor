package org.bench4q.monitor.service;

import java.util.List;
import java.util.Date;
import java.text.SimpleDateFormat;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.XMLWriter;
import org.dom4j.io.OutputFormat;

import java.io.*;

import org.bench4q.monitor.model.*;

public class WriteSystemInfoToLocalDisk {
	private SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
//	private ProcessorModel processorModel = new ProcessorModel();
//	private MemoryModel memoryModel = new MemoryModel();
//	private PhysicalDiskModel physicalDiskModel = new PhysicalDiskModel();
//	private NetworkInterfaceModel networkInterfaceModel = new NetworkInterfaceModel();
//	private ProcessModel processModel;
	private String savePath;
	
	//test code
	public static void main(String[] args){
		WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
		testWrite.setSavaPath("/Users/apple/Desktop/tmp/");		
		testWrite.writeCurrentSystemInfoToLocalDisk();
	}
	
	public void setSavaPath(String savePath){
		this.savePath = savePath;
	}
	
	public void writeCurrentSystemInfoToLocalDisk(){
		Date date = new Date();
		MainModel mainModel = new MainModel(date);   
		FileWriter writer = null;
    
        try {
        		JAXBContext context = JAXBContext.newInstance(MainModel.class);
            Marshaller marshal = context.createMarshaller();
            marshal.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            marshal.marshal(mainModel, System.out);
            
            writer = new FileWriter(savePath + dateFormat.format(date) + ".xml");
            marshal.marshal(mainModel, writer);
        } catch (Exception e) {
            e.printStackTrace();
        }
	}
	
//	public void writeCurrentSystemInfoToLocalDisk(){
//		Document document = DocumentHelper.createDocument();
//		Element historyElement = document.addElement("history");
//		Element dateElement = historyElement.addElement("date");
//		Element cpuElement = historyElement.addElement("cpu_info");
//		Element memElement = historyElement.addElement("memory_info");
//		Element diskElement = historyElement.addElement("disk_info");
//		Element networkElement = historyElement.addElement("network_info");
//		Element processElement = historyElement.addElement("process_info");
//		
//		//add cpu info into xml
//		List<ProcessorModelChild> processorModelList = processorModel.getProcessorModelList();
//		for(int i = 0; i < processorModelList.size(); ++i){
//			Element instanceElement = cpuElement.addElement(processorModelList.get(i).getInstance());
//			Element utilizationElement = instanceElement.addElement("utilization");
//			Element privilegedTimePercentElement = instanceElement.addElement("privileged_time_percent");
//			Element userTimePercentElement = instanceElement.addElement("user_time_percent");
//			
//			utilizationElement.setText(processorModelList.get(i).getProcessorTimePercent());
//			privilegedTimePercentElement.setText(processorModelList.get(i).getPrivilegedTimePercent());
//			userTimePercentElement.setText(processorModelList.get(i).getUserTimePercent());
//		}
//		
//		//add mem info into xml
//		Element pageInRateElement = memElement.addElement("page_in_rate");
//		Element pageOutRateElement = memElement.addElement("page_out_rate");
//		Element pagingRateElement = memElement.addElement("paging_rate");
//		Element memUtilizationElement = memElement.addElement("memory_utilization");
//		Element avalMemElement = memElement.addElement("available_memory");
//		Element totalMemElement = memElement.addElement("total_memory");
//		
//		pageInRateElement.setText(Double.toString(memoryModel.getPagesInputPerSecond()));
//		pageOutRateElement.setText(Double.toString(memoryModel.getPagesOutputPerSecond()));
//		pagingRateElement.setText(Double.toString(memoryModel.getPagesPerSecond()));
//		memUtilizationElement.setText(memoryModel.getMemoryUsedPercent());
//		avalMemElement.setText(Long.toString(memoryModel.getAvailableKiloBytes()) + "KB");
//		totalMemElement.setText(Long.toString(memoryModel.getTotalKiloBytes()) + "KB");
//		
//		//add disk info into xml
//		Element diskReadRateElement = diskElement.addElement("read_rate");
//		Element diskWriteRateElement = diskElement.addElement("write_rate");
//		Element diskQueueElement = diskElement.addElement("disk_queue");
//		
//		diskReadRateElement.setText(Double.toString(physicalDiskModel.getDiskReadRate()) + "KB/S");
//		diskWriteRateElement.setText(Double.toString(physicalDiskModel.getDiskWriteRate()) + "KB/S");
//		diskQueueElement.setText(Double.toString(physicalDiskModel.getCurDiskQueLength()));
//		
//		//add network info into xml
//		List<NetworkInterfaceModelChild> networkInterfaceModelList = networkInterfaceModel.getNetworkList();
//		for(int i = 0; i < networkInterfaceModelList.size(); ++i){
//			Element instanceElement = networkElement.addElement(networkInterfaceModelList.get(i).getInstance());
//			Element addressElement = instanceElement.addElement("address");
//			Element receiveRateElement = instanceElement.addElement("receive_rate");
//			Element sendRateElement = instanceElement.addElement("send_rate");
//			Element totalRateElement = instanceElement.addElement("total_rate");
//			
//			addressElement.setText(networkInterfaceModelList.get(i).getAddress());
//			receiveRateElement.setText(Double.toString(networkInterfaceModelList.get(i).getKiloBytesReceivedPerSecond()) + "KB/s");
//			sendRateElement.setText(Double.toString(networkInterfaceModelList.get(i).getKiloBytesSentPerSecond()) + "KB/s");
//			totalRateElement.setText(Double.toString(networkInterfaceModelList.get(i).getKiloBytesTotalPerSecond()) + "KB/s");
//		}
//		
//		
//		//write to disk
//		String fileName = dateFormat.format(new Date());
//		dateElement.setText(fileName);
//		fileName += ".xml";
//		
//		try {
//			OutputFormat format = OutputFormat.createPrettyPrint();
//			XMLWriter writer = new XMLWriter(new FileWriter(new File(savePath + fileName)), format);
//			writer.write(document);
//			writer.close();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//	}
	
}	