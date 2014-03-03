package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

import org.bench4q.monitor.service.GetSigar;
import org.bench4q.monitor.service.GetThreadPool;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.FileSystem;
import org.hyperic.sigar.FileSystemUsage;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "PhysicalDisk")
public class PhysicalDiskModel {
	private Double diskReadKBytesRate;
	private Double diskWriteKBytesRate;
	private double curDiskQueLength;
	private double totalGB;
	private double usedGB;
	private double freeGB;
	private double usedPercent;
	private List<FileSystemModel> fieFileSystemModels;
	private Sigar sigar = GetSigar.getSigar();
	private FileSystem[] fileSystemList;
	private final int interval = 500;

	// private Logger logger = Logger.getLogger(PhysicalDiskModel.class);

	public static void main(String[] args) throws SigarException,
			InterruptedException, ExecutionException {
		PhysicalDiskModel physicalDiskModel = new PhysicalDiskModel();
		System.out.println("queue length:"
				+ physicalDiskModel.getCurDiskQueLength());
		System.out.println("read rate: "
				+ physicalDiskModel.getDiskReadKBytesRate());

		System.out.println("write rate: "
				+ physicalDiskModel.getDiskWriteKBytesRate());
		System.out
				.println("used percent:" + physicalDiskModel.getUsedPercent());
		System.out.println("total:" + physicalDiskModel.getTotalGB());

	}

	public PhysicalDiskModel() throws SigarException, InterruptedException,
			ExecutionException {

		this.setFileSystemList();
		this.setFieFileSystemModels();
		this.setCurDiskQueLength();
		this.setDiskReadKBytesRate();
		this.setDiskWriteKBytesRate();
		this.setFreeGB();
		this.setTotalGB();
		this.setUsedGB();
		this.setUsedPercent();

	}

	@XmlElementWrapper
	@XmlElement(name = "FileSystem", type = FileSystemModel.class)
	public List<FileSystemModel> getFieFileSystemModels() {
		return fieFileSystemModels;
	}

	private void setFieFileSystemModels() throws SigarException,
			InterruptedException, ExecutionException {
		this.fieFileSystemModels = new ArrayList<FileSystemModel>();

		Map<String, FileSystemUsage> fileSysUsageMap = this
				.getFileSystemUsages();
		if (fileSysUsageMap.keySet() != null) {
			List<Future<FileSystemModel>> futures = new ArrayList<Future<FileSystemModel>>();

			for (String fileDir : fileSysUsageMap.keySet()) {
				futures.add(GetThreadPool.getExecutorService().submit(
						new NewFileSystemModel(fileSysUsageMap.get(fileDir),
								fileDir, interval)));

			}
			for (Future<FileSystemModel> future : futures) {
				fieFileSystemModels.add(future.get());
			}
		}

	}

	@XmlElement
	public double getDiskReadKBytesRate() {
		return diskReadKBytesRate;
	}

	private void setDiskReadKBytesRate() {

		diskReadKBytesRate = new Double(0);

		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			diskReadKBytesRate += fileSystemModel.getDiskReadKBytesRate();
		}
	}

	@XmlElement
	public double getDiskWriteKBytesRate() {
		return this.diskWriteKBytesRate;
	}

	private void setDiskWriteKBytesRate() {
		this.diskWriteKBytesRate = new Double(0);
		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			this.diskWriteKBytesRate += fileSystemModel
					.getDiskWriteKBytesRate();
		}
	}

	@XmlElement
	public double getCurDiskQueLength() {

		return this.curDiskQueLength;
	}

	private void setCurDiskQueLength() throws SigarException {
		this.curDiskQueLength = new Double(0);
		for (FileSystemModel fileSystemModel : this.getFieFileSystemModels()) {
			this.curDiskQueLength += fileSystemModel.getCurDiskQueLength();
		}
	}

	@XmlElement
	public FileSystem[] getFileSystemList() {
		return fileSystemList;
	}

	private void setFileSystemList() throws SigarException {
		this.fileSystemList = this.sigar.getFileSystemList();
	}

	@XmlElement
	public double getTotalGB() {
		return this.totalGB;
	}

	private void setTotalGB() {
		this.totalGB = 0;
		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			this.totalGB += fileSystemModel.getTotalGB();
		}
	}

	@XmlElement
	public double getUsedGB() {
		return usedGB;
	}

	private void setUsedGB() {
		this.usedGB = 0;
		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			this.usedGB += fileSystemModel.getUsedGB();
		}
	}

	@XmlElement
	public double getFreeGB() {
		return freeGB;
	}

	private void setFreeGB() {
		this.freeGB = 0;
		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			this.freeGB += fileSystemModel.getFreeGB();
		}
	}

	@XmlElement
	public double getUsedPercent() {

		return usedPercent;
	}

	private void setUsedPercent() {
		this.usedPercent = 0;
		for (FileSystemModel fileSystemModel : this.fieFileSystemModels) {
			this.usedPercent += fileSystemModel.getUsedPercent();
		}
	}

	public Map<String, FileSystemUsage> getFileSystemUsages()
			throws SigarException {
		Map<String, FileSystemUsage> fileSystemUsages = new HashMap<String, FileSystemUsage>();
		if (this.getFileSystemList() == null)
			this.setFileSystemList();
		for (FileSystem fileSystem : this.getFileSystemList()) {
			if (fileSystem.getType() == 2)
				fileSystemUsages.put(fileSystem.getDirName(),
						sigar.getFileSystemUsage(fileSystem.getDirName()));
		}
		return fileSystemUsages;

	}
}

class NewFileSystemModel implements Callable<FileSystemModel> {
	private FileSystemUsage fileSystemUsage;
	private String fileDir;
	private int interval;

	public NewFileSystemModel(FileSystemUsage fileSystemUsage, String fileDir,
			int interval) {
		this.fileDir = fileDir;
		this.fileSystemUsage = fileSystemUsage;
		this.interval = interval;

	}

	public FileSystemModel call() throws InterruptedException,
			ExecutionException {
		return new FileSystemModel(this.fileSystemUsage, fileDir, interval);
	}

	public FileSystemUsage getFileSystemUsage() {
		return fileSystemUsage;
	}

	public String getFileDir() {
		return fileDir;
	}

	public long getInterval() {
		return interval;
	}

}
