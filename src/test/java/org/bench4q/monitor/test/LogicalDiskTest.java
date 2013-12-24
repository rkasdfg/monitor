package org.bench4q.monitor.test;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;

import org.bench4q.monitor.model.LogicalDiskModelChild;
import org.bench4q.monitor.model.LogicalDiskModel;
import org.bench4q.monitor.test.communication.HttpRequester;
import org.bench4q.monitor.test.communication.HttpRequester.HttpResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.stereotype.Component;

@Component
public class LogicalDiskTest {
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

		String urlString = "http://localhost:5556/Monitor/LogicalDisk";
		atx = new ClassPathXmlApplicationContext(
				"classpath*:org/Bench4Q/Monitor/Config/application-context.xml");
		atx.getClass();
		LogicalDiskTest monitorServiceTest = new LogicalDiskTest();
		monitorServiceTest.setHttpRequester(new HttpRequester());
		try {

			HttpResponse httpResponse = monitorServiceTest.getHttpRequester()
					.sendGet(urlString, null, null);

			LogicalDiskModel logicalDiskModel = monitorServiceTest
					.extractLogicalDiskModel(httpResponse.getContent());
			monitorServiceTest.result(logicalDiskModel);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (JAXBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public void result(LogicalDiskModel logicalDiskModel) {

		List<LogicalDiskModelChild> list = logicalDiskModel
				.getLogicalDiskList();
		Iterator<LogicalDiskModelChild> iterator = list.iterator();
		while (iterator.hasNext()) {
			LogicalDiskModelChild logicalDiskModelChild = iterator.next();
			System.out.println(logicalDiskModelChild.getInstance());
			System.out.println(logicalDiskModelChild.getFreeMegabytes());

		}

	}

	public LogicalDiskModel extractLogicalDiskModel(String content)
			throws JAXBException {

		LogicalDiskModel resultModel = new LogicalDiskModel();
		Unmarshaller ummarshaller = JAXBContext.newInstance(
				resultModel.getClass()).createUnmarshaller();
		resultModel = (LogicalDiskModel) ummarshaller
				.unmarshal(new ByteArrayInputStream(content.getBytes()));
		return resultModel;
	}
}
