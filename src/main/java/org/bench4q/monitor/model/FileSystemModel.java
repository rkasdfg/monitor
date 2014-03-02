package org.bench4q.monitor.model;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.DataFomat;
import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.FileSystemUsage;
import org.hyperic.sigar.SigarException;
@XmlRootElement(name="fileSystem")
public class FileSystemModel {
	private String fileDir;
	private Double diskReadKBytesRate;
	private Double diskWriteKBytesRate;
	private double curDiskQueLength;
	private double totalGB;
	private double usedGB;
	private double freeGB;
	private double usedPercent;
	private FileSystemUsage fileSystemUsage;

	public static void main(String args[]) throws SigarException,
			InterruptedException, ExecutionException {
		FileSystemUsage fileSystemUsage = GetSigar
				.getSigar()
				.getFileSystemUsage(
						GetSigar.getSigar().getFileSystemList()[0].getDirName());
		FileSystemModel fileSystemModel = new FileSystemModel(fileSystemUsage,
				GetSigar.getSigar().getFileSystemList()[0].getDirName(), 500);
		System.out.println(fileSystemModel.getFreeGB());
		System.out.println(fileSystemModel.getTotalGB());
		System.out.println(fileSystemModel.getDiskReadKBytesRate());
		

	}
public FileSystemModel(){
	
}
	public FileSystemModel(FileSystemUsage fileSystemUsage, String fileDir,
			int interval) throws InterruptedException, ExecutionException {

		this.fileDir = fileDir;
		this.fileSystemUsage = fileSystemUsage;
		ExecutorService executorService = Executors.newFixedThreadPool(2);
		Future<Double> caculateReadRateFuture = executorService
				.submit(new CalculateDiskReadRate(interval, fileSystemUsage));

		Future<Double> caculateWriteRateFuture = executorService
				.submit(new CalculateDiskWriteRate(interval, fileSystemUsage));

		this.setCurDiskQueLength();
		this.setFreeGB();
		this.setTotalGB();
		this.setUsedGB();
		this.setUsedPercent();

		this.setDiskReadKBytesRate(caculateReadRateFuture.get());
		this.setDiskWriteKBytesRate(caculateWriteRateFuture.get());
		this.setCurDiskQueLength();

		executorService.shutdown();

	}

	@XmlElement
	public String getFileDir() {
		return fileDir;
	}

	@XmlElement
	public Double getDiskReadKBytesRate() {
		return diskReadKBytesRate;
	}

	private void setDiskReadKBytesRate(Double diskReadKBytesRate) {
		this.diskReadKBytesRate = diskReadKBytesRate;
	}

	@XmlElement
	public Double getDiskWriteKBytesRate() {
		return diskWriteKBytesRate;
	}

	private void setDiskWriteKBytesRate(Double diskWriteKBytesRate) {
		this.diskWriteKBytesRate = diskWriteKBytesRate;
	}

	@XmlElement
	public double getCurDiskQueLength() {
		return curDiskQueLength;
	}

	private void setCurDiskQueLength() {
		this.curDiskQueLength = this.fileSystemUsage.getDiskQueue();
	}

	@XmlElement
	public double getTotalGB() {
		return totalGB;
	}

	private void setTotalGB() {
		this.totalGB = changeBytesToGB(this.fileSystemUsage.getTotal());
	}

	@XmlElement
	public double getUsedGB() {
		return usedGB;
	}

	private void setUsedGB() {
		this.usedGB = changeBytesToGB(this.fileSystemUsage.getUsed());
	}

	@XmlElement
	public double getFreeGB() {
		return freeGB;
	}

	private void setFreeGB() {
		this.freeGB = changeBytesToGB(this.fileSystemUsage.getFree());
	}

	@XmlElement
	public double getUsedPercent() {
		return usedPercent;
	}

	private void setUsedPercent() {
		this.usedPercent = DataFomat.fomatToPercent(fileSystemUsage
				.getUsePercent());
	}

	private double changeBytesToGB(long bytes) {
		return (double) Math.round(((double) bytes / 1024 / 1024) * 100) / 100;
	}
}

abstract class CalculateDiskRate implements Callable<Double> {
	private long interval;
	private Double KBytesRate;
	protected FileSystemUsage fileSystemUsage;

	public CalculateDiskRate(long interval, FileSystemUsage fileSystemUsage) {
		this.interval = interval;
		this.fileSystemUsage = fileSystemUsage;
	}

	public Double call() throws InterruptedException, SigarException {
		long preDiskKBytes = getFileKBytes();
		long postDiskKBytes = 0;
		long startTime = System.nanoTime();
		long endTime = 0;
		Thread.sleep(this.interval);
		postDiskKBytes = getFileKBytes();
		endTime = System.nanoTime();
		this.KBytesRate = new Double(
				Math.round((postDiskKBytes - preDiskKBytes)
						/ DataFomat.caculateTimeInterval(startTime, endTime)
						* 10000) / 10000);
		return this.KBytesRate;
	}

	abstract long getFileKBytes() throws SigarException;
}

class CalculateDiskWriteRate extends CalculateDiskRate {

	public CalculateDiskWriteRate(long interval, FileSystemUsage fileSystemUsage) {
		super(interval, fileSystemUsage);
	}

	long getFileKBytes() throws SigarException {
		return fileSystemUsage.getDiskWriteBytes() / 1024L;
	}
}

class CalculateDiskReadRate extends CalculateDiskRate {

	public CalculateDiskReadRate(long interval,
			FileSystemUsage feFileSystemUsage) {
		super(interval, feFileSystemUsage);
	}

	long getFileKBytes() throws SigarException {

		return fileSystemUsage.getDiskReadBytes() / 1024L;
	}
}
