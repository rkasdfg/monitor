package org.bench4q.monitor.test;

import java.io.ByteArrayInputStream;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;

import org.bench4q.monitor.model.MemoryModel;
import org.bench4q.monitor.test.communication.HttpRequester;
import org.bench4q.monitor.test.communication.HttpRequester.HttpResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.stereotype.Component;

@Component
public class MemoryTest {
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

		String urlString = "http://localhost:5556/Mon/File";
		atx = new ClassPathXmlApplicationContext(
				"org/Bench4Q/Monitor/Config/application-context.xml");
		atx.getClass();

		MemoryTest memoryTest = new MemoryTest();
		memoryTest.httpRequester = new HttpRequester();
		try {
			HttpResponse httpResponse = memoryTest.getHttpRequester().sendGet(
					urlString, null, null);
			System.out.println(httpResponse.getContent());
			System.out.println("ok");

		} catch (Exception e) {
			System.out.println(e);
		}
	}

	/*
	 * try {
	 * 
	 * HttpResponse httpResponse = memoryTest.getHttpRequester()
	 * .sendGet(urlString, null, null);
	 * 
	 * MemoryModel memoryModel = memoryTest
	 * .extractLogicalDiskModel(httpResponse.getContent());
	 * 
	 * memoryTest.result(memoryModel); } catch (IOException e) {
	 * e.printStackTrace(); } catch (JAXBException e) { // TODO Auto-generated
	 * catch block e.printStackTrace(); }
	 * 
	 * }
	 */

	public MemoryModel extractLogicalDiskModel(String content)
			throws JAXBException {

		MemoryModel resultModel = new MemoryModel();
		Unmarshaller ummarshaller = JAXBContext.newInstance(
				resultModel.getClass()).createUnmarshaller();
		resultModel = (MemoryModel) ummarshaller
				.unmarshal(new ByteArrayInputStream(content.getBytes()));
		return resultModel;
	}

}
