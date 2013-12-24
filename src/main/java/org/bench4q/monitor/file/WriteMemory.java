package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.LogicalDiskModel;
import org.bench4q.monitor.model.MemoryModel;
import org.bench4q.monitor.service.MemoryServiceWindows;
import org.bench4q.monitor.files.Write;

public class WriteMemory extends Write{

	private MemoryServiceWindows memoryServiceWindows;
	public WriteMemory(PrintWriter out,int idleTime){
		this.out=out;
		this.memoryServiceWindows=new MemoryServiceWindows();
		this.idleTime=idleTime;
	}
	public void run(){
		try{
			JAXBContext context = JAXBContext.newInstance(LogicalDiskModel.class);  
		     Marshaller marshaller = context.createMarshaller();  
		     MemoryModel memoryModel=memoryServiceWindows.getMemoryInfo(idleTime);
		     marshaller.marshal(memoryModel, out);  
		}
		catch(Exception e){
			System.out.println(e);
		}
		
	}

}

