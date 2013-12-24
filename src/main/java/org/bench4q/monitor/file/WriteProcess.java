package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.ProcessModel;
import org.bench4q.monitor.service.ProcessServiceWindows;
import org.bench4q.monitor.files.Write;

public class WriteProcess extends Write {
	private ProcessServiceWindows processServiceWindows;

	public WriteProcess(PrintWriter out, int idleTime) {
		this.out = out;
		this.processServiceWindows = new ProcessServiceWindows();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext.newInstance(ProcessModel.class);
			Marshaller marshaller = context.createMarshaller();
			ProcessModel processModel = processServiceWindows
					.getProcessInfo(idleTime);
			marshaller.marshal(processModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
