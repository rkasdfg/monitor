package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.PhysicalDiskModel;
import org.bench4q.monitor.service.PhysicalDiskService;
import org.bench4q.monitor.files.Write;

public class WritePhysicalDisk extends Write {

	private PhysicalDiskService physicalDiskService;

	public WritePhysicalDisk(PrintWriter out, int idleTime) {
		this.out = out;
		this.physicalDiskService = new PhysicalDiskService();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext
					.newInstance(PhysicalDiskModel.class);
			Marshaller marshaller = context.createMarshaller();
			PhysicalDiskModel physicalDiskModel = physicalDiskService
					.getPhysicalDiskInfo(idleTime);
			marshaller.marshal(physicalDiskModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
