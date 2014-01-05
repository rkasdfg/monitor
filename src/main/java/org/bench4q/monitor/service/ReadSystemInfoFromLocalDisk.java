package org.bench4q.monitor.service;

import java.util.Arrays;
import java.util.Date;
import java.util.Calendar;
import java.util.List;
import java.text.SimpleDateFormat;
import java.util.ArrayList;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

import org.bench4q.monitor.model.MainModel;


import java.io.*;

class XmlFileFilter implements FilenameFilter{

	public boolean accept(File dir, String name) {
		return name.endsWith(".xml");
	}
}

public class ReadSystemInfoFromLocalDisk {
	private String savePath;
	private SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
	
	//test code
	public static void main(String[] args){
		ReadSystemInfoFromLocalDisk test = new ReadSystemInfoFromLocalDisk();
		test.setSavePath("D:\\sigartmp\\");
		Calendar lowerCalendal = Calendar.getInstance();
		lowerCalendal.clear();
		lowerCalendal.set(2014, 0, 3, 20, 0, 0);
		Calendar upperCalendar = Calendar.getInstance();
		upperCalendar.clear();
		upperCalendar.set(2014, 0, 3, 22, 0, 0);
		
		List<MainModel> mainModelList = test.ReadSystemInfoByDate(lowerCalendal.getTime(), upperCalendar.getTime());
		FileWriter writer = null;	
        try {
        		JAXBContext context = JAXBContext.newInstance(MainModel.class);
            Marshaller marshal = context.createMarshaller();
            marshal.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            
            for(int i = 0; i < mainModelList.size(); ++i){
	            marshal.marshal(mainModelList.get(i), System.out);
	            writer = new FileWriter("/Users/apple/Desktop/tmp/" + i + "xml");
	            marshal.marshal(mainModelList.get(i), writer);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
	}
	
	public void setSavePath(String savePath){
		this.savePath = savePath;
	}
	
	
	public List<MainModel> ReadSystemInfoByDate(Date lowerDate, Date upperDate){
		String lowerDateString = dateFormat.format(lowerDate);
		String upperDateString = dateFormat.format(upperDate);
		
		if(lowerDateString.compareTo(upperDateString) > 0){
			System.out.println("return");
			return null;
		}
		
		File path = new File(savePath);
		XmlFileFilter xmlFileFilter = new XmlFileFilter();
		String[] xmlFiles = path.list(xmlFileFilter);
		Arrays.sort(xmlFiles);
		
		List<MainModel> mainModelList = new ArrayList<MainModel>();
		JAXBContext context;
		Unmarshaller unmarshal = null;
		try {
			context = JAXBContext.newInstance(MainModel.class);
			unmarshal = context.createUnmarshaller();
		} catch (JAXBException e) {
			e.printStackTrace();
		}
		
		for(int i = 0; i < xmlFiles.length; ++i){
			if(xmlFiles[i].compareTo(lowerDateString) >= 0 && xmlFiles[i].compareTo(upperDateString) <= 0){
				FileReader reader;
				try {
					reader = new FileReader(savePath + xmlFiles[i]);
					try {
						mainModelList.add((MainModel)unmarshal.unmarshal(reader));
					} catch (JAXBException e) {
						e.printStackTrace();
					}
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				System.out.println(xmlFiles[i]);
			}
		}
		return mainModelList;
	}
}
