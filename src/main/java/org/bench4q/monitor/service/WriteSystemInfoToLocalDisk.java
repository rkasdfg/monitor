package org.bench4q.monitor.service;

import java.util.Date;
import java.text.SimpleDateFormat;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import java.io.*;

import org.bench4q.monitor.model.*;

public class WriteSystemInfoToLocalDisk {
	private SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
	private String savePath;
	
	//test code
	public static void main(String[] args){
		WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
		testWrite.setSavaPath("D:\\sigartmp\\");		
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

	
}	