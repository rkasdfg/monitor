package org.bench4q.monitor.test;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.Iterator;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;

import org.bench4q.monitor.model.ProcessorModel;
import org.bench4q.monitor.model.ProcessorModelChild;
import org.bench4q.monitor.test.communication.HttpRequester;
import org.bench4q.monitor.test.communication.HttpRequester.HttpResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.stereotype.Component;

@Component 
public class ProcessorTest {
	private HttpRequester httpRequester;
	private static ApplicationContext atx;

	public HttpRequester getHttpRequester() {
		return httpRequester;
	}
	@Autowired
	public void setHttpRequester(HttpRequester httpRequester) {
		this.httpRequester = httpRequester;
	}

	public static void main(String[] args) {

		String urlString = "http://localhost:5556/Monitor/Processor";
		atx = new ClassPathXmlApplicationContext("org/Bench4Q/Monitor/Config/application-context.xml");
		
		ProcessorTest ProcessorTest =(ProcessorTest)atx.getBean("processorTest");
	
		try {
			
			HttpResponse httpResponse = ProcessorTest.getHttpRequester()
					.sendGet(urlString, null, null);
	
			ProcessorModel ProcessorModel = ProcessorTest
					.extractLogicalDiskModel(httpResponse.getContent());
			
			ProcessorTest.result(ProcessorModel);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (JAXBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public void result(ProcessorModel ProcessorModel) {
		
		Iterator<ProcessorModelChild> iterator=ProcessorModel.getProcessorModelList().iterator();
		while(iterator.hasNext()){
			ProcessorModelChild processorModelChild=iterator.next();
			System.out.println("instance"+processorModelChild.getInstance());

			System.out.println("privilegedTimePercent"+processorModelChild.getPrivilegedTimePercent());
			System.out.println("processorTimePercent"+processorModelChild.getProcessorTimePercent());
			System.out.println("userTimePercent"+processorModelChild.getUserTimePercent());
		}
	
		
		

	}

	public ProcessorModel extractLogicalDiskModel(String content)
			throws JAXBException {

		ProcessorModel resultModel = new ProcessorModel();
		Unmarshaller ummarshaller = JAXBContext.newInstance(
				resultModel.getClass()).createUnmarshaller();
		resultModel = (ProcessorModel) ummarshaller
				.unmarshal(new ByteArrayInputStream(content.getBytes()));
		return resultModel;
	}


}
