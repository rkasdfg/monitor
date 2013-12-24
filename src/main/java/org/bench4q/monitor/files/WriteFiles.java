package org.bench4q.monitor.files;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import org.bench4q.monitor.entiry.MonitorContorlEntity;
import org.bench4q.monitor.file.WriteLogicalDisk;
import org.bench4q.monitor.file.WriteMemory;
import org.bench4q.monitor.file.WriteNetworkInterface;
import org.bench4q.monitor.file.WritePhysicalDisk;
import org.bench4q.monitor.file.WriteProcess;
import org.bench4q.monitor.file.WriteProcessor;
import org.bench4q.monitor.file.WriteSystem;


public class WriteFiles extends MonitorContorlEntity {
	public static boolean flag = true;
	private int threadCount;
	private int saveCount;
	private ExecutorService service;
	WriteLogicalDisk logicalDiskWindows;
	WriteMemory memoryWindows;
	WriteNetworkInterface networkInterfaceWindows;
	WritePhysicalDisk physicalDiskWindows;
	WriteProcessor processorWindows;
	WriteSystem systemWindows;
	WriteProcess processWindows;


	public WriteFiles() throws FileNotFoundException {
		this.threadCount = 7;
		this.saveCount = 150;
		service = null;
		PrintWriter out = null;

		logicalDiskWindows = new WriteLogicalDisk(out,
				this.getIdleTime());
		memoryWindows = new WriteMemory(out, this.getIdleTime());
		networkInterfaceWindows = new WriteNetworkInterface(out,
				this.getIdleTime());
		physicalDiskWindows = new WritePhysicalDisk(out,
				this.getIdleTime());
		processorWindows = new WriteProcessor(out,
				this.getIdleTime());
		systemWindows = new WriteSystem(out, this.getIdleTime());
		processWindows = new WriteProcess(out, this.getIdleTime());



	}

	public void start() throws FileNotFoundException {

		Executors.newFixedThreadPool(threadCount);
		int time_count = 0;
		SimpleDateFormat df = new SimpleDateFormat("yyyyMMddHH:mm:ss");
		String filePath;
		PrintWriter netPt = null, logicalPt = null, /* processPt = null, */processorPt = null, physicalPt = null, memoryPt = null, systemPt = null;

		while (flag) {

			if ((time_count % saveCount) == 0) {
				time_count = 0;
				df.format(new Date());
				filePath = new CreatFileName("NetworkInterface",
						df.toString()).getFileName();
				netPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				networkInterfaceWindows.setOut(netPt);

				filePath = new CreatFileName("LogicalDisk", df.toString())
						.getFileName();
				logicalPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				logicalDiskWindows.setOut(logicalPt);

				filePath = new CreatFileName("Process", df.toString())
						.getFileName();
				// processPt = new PrintWriter(new BufferedWriter(
				// new OutputStreamWriter(new FileOutputStream(
				// new File(filePath)))));
				physicalDiskWindows.setOut(physicalPt);

				filePath = new CreatFileName("Processor", df.toString())
						.getFileName();
				processorPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				processorWindows.setOut(processorPt);

				filePath = new CreatFileName("PhysicalDisk", df.toString())
						.getFileName();
				physicalPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				physicalDiskWindows.setOut(physicalPt);

				filePath = new CreatFileName("Memory", df.toString())
						.getFileName();
				memoryPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				memoryWindows.setOut(memoryPt);

				filePath = new CreatFileName("System", df.toString())
						.getFileName();
				systemPt = new PrintWriter(new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(
								new File(filePath)))));
				systemWindows.setOut(systemPt);
			}
			service.execute(systemWindows);
			service.execute(physicalDiskWindows);
			service.execute(memoryWindows);
			service.execute(logicalDiskWindows);
			service.execute(processWindows);
			service.execute(networkInterfaceWindows);
			time_count++;
		}

		

	}

	public void stop() throws InterruptedException {
		flag = false;
		service.shutdown();
		service.awaitTermination(Long.MAX_VALUE, TimeUnit.DAYS);
		flag = false;

	}

}
