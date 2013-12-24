package org.bench4q.monitor.file;

import java.io.PrintWriter;

import org.bench4q.monitor.service.SystemServiceWindows;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.SystemModel;
import org.bench4q.monitor.files.Write;

public class WriteSystem extends Write {
	private SystemServiceWindows SystemServiceWindows;

	public WriteSystem(PrintWriter out, int idleTime) {
		this.out = out;
		this.SystemServiceWindows = new SystemServiceWindows();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext.newInstance(SystemModel.class);
			Marshaller marshaller = context.createMarshaller();
			SystemModel SystemModel = SystemServiceWindows
					.getSystemInfo(idleTime);
			marshaller.marshal(SystemModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
