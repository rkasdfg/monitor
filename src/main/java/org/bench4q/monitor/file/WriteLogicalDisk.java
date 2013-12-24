package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.files.Write;
import org.bench4q.monitor.model.LogicalDiskModel;
import org.bench4q.monitor.service.LogicalDiskServiceWindows;

public class WriteLogicalDisk extends Write {

	private LogicalDiskServiceWindows logicalDiskServiceWindows;

	public WriteLogicalDisk(PrintWriter out, int idleTime) {
		this.out = out;
		this.logicalDiskServiceWindows = new LogicalDiskServiceWindows();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext
					.newInstance(LogicalDiskModel.class);
			Marshaller marshaller = context.createMarshaller();
			LogicalDiskModel logicalDiskModel = logicalDiskServiceWindows
					.getLogicalDiskInfo(idleTime);
			marshaller.marshal(logicalDiskModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
