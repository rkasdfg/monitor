package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.ProcessorModel;
import org.bench4q.monitor.service.ProcessorServiceWindows;
import org.bench4q.monitor.files.Write;

public class WriteProcessor extends Write {
	private ProcessorServiceWindows processorServiceWindows;

	public WriteProcessor(PrintWriter out, int idleTime) {
		this.out = out;
		this.processorServiceWindows = new ProcessorServiceWindows();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext.newInstance(ProcessorModel.class);
			Marshaller marshaller = context.createMarshaller();
			ProcessorModel processorModel = processorServiceWindows
					.getProcessorInfo(idleTime);
			marshaller.marshal(processorModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
