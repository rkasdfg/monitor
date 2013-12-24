package org.bench4q.monitor.file;

import java.io.PrintWriter;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;

import org.bench4q.monitor.model.NetworkInterfaceModel;
import org.bench4q.monitor.service.NetworkInterfaceService;
import org.bench4q.monitor.files.Write;

public class WriteNetworkInterface extends Write {
	private NetworkInterfaceService networkInterfaceServiceWindows;

	public WriteNetworkInterface(PrintWriter out, int idleTime) {
		this.out = out;
		this.networkInterfaceServiceWindows = new NetworkInterfaceService();
		this.idleTime = idleTime;
	}

	public void run() {
		try {
			JAXBContext context = JAXBContext
					.newInstance(NetworkInterfaceModel.class);
			Marshaller marshaller = context.createMarshaller();
			NetworkInterfaceModel networkInterfaceModel = networkInterfaceServiceWindows
					.getNetworkInterfaceInfo(idleTime);
			marshaller.marshal(networkInterfaceModel, out);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

}
