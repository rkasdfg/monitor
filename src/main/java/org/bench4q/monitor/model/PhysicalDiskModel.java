package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import java.util.Timer;
import java.util.TimerTask;
import java.util.ArrayList;
import java.util.List;

import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.FileSystem;
import org.hyperic.sigar.FileSystemUsage;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name="PhisicalDisk")
public class PhysicalDiskModel {
	private double diskReadRate;
	private double diskWriteRate;
	private double curDiskQueLength;
	private Sigar sigar = new Sigar();
	public List<FileSystemUsage> fileSystemUsageList;
	private FileSystem[] fileSystemList;
	
	public static void main(String[] args){
		PhysicalDiskModel physicalDiskModel = new PhysicalDiskModel();
		
		System.out.println(physicalDiskModel.getCurDiskQueLength());
		System.out.println("read rate: " + physicalDiskModel.getDiskReadRate());
		System.out.println("write rate: " + physicalDiskModel.getDiskWriteRate());
	}
	public PhysicalDiskModel(){
		this.fileSystemUsageList = new ArrayList<FileSystemUsage>();
		try {
			fileSystemList = sigar.getFileSystemList();
			for(int i = 0; i < fileSystemList.length; ++i){
				fileSystemUsageList.add(this.sigar.getFileSystemUsage(fileSystemList[i].getDirName()));
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
	}
	@XmlElement
	public double getDiskReadRate() {
		Timer timer = new Timer();
		long interval = 1000;
		timer.schedule(new CalculateDiskReadRate(this, timer, interval), interval);
		try {
			Thread.sleep(interval + 20);
			return diskReadRate;
		} catch (InterruptedException e) {
			e.printStackTrace();
			return diskReadRate;
		}
	}
	public void setDiskReadRate(double diskReadRate) {
		this.diskReadRate = diskReadRate;
	}
	@XmlElement
	public double getDiskWriteRate() {
		Timer timer = new Timer();
		long interval = 1000;
		timer.schedule(new CalculateDiskWriteRate(this, timer, interval), interval);
		try {
			Thread.sleep(interval + 20);
			return diskWriteRate;
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return diskWriteRate;
		}
	}
	public void setDiskWriteRate(double diskWriteRate) {
		this.diskWriteRate = diskWriteRate;
	}
	@XmlElement
	public double getCurDiskQueLength() {
		try {
			fileSystemList = sigar.getFileSystemList();
		} catch (SigarException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i = 0; i < fileSystemUsageList.size(); ++i){
			if(i == 0)
				this.curDiskQueLength = fileSystemUsageList.get(i).getDiskQueue();
			else
				this.curDiskQueLength += fileSystemUsageList.get(i).getDiskQueue();
			//System.out.println("Disk"+i+": "+fileSystemUsageList.get(i).getDiskQueue());
		}
		return curDiskQueLength;
	}
	public void setCurDiskQueLength(double curDiskQueLength) {
		this.curDiskQueLength = curDiskQueLength;
	}
}

class CalculateDiskWriteRate extends TimerTask{
	private PhysicalDiskModel physicalDiskModel;
	//private DiskUsage diskUsage;
	private long preDiskWriteBytes = 0;
	private long interval;
	private Timer timer;
	private Sigar sigar = new Sigar();
	
	public CalculateDiskWriteRate(PhysicalDiskModel physicalDiskModel, Timer timer, long interval){
		this.physicalDiskModel = physicalDiskModel;
		FileSystem[] fileSystemList;
		try {
			fileSystemList = sigar.getFileSystemList();
			for(int i = 0; i < fileSystemList.length; ++i){
				this.preDiskWriteBytes += sigar.getFileSystemUsage(fileSystemList[i].getDirName()).getDiskWriteBytes();
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
		this.timer = timer;
		this.interval = interval;
	}
	@Override
	public void run() {
		long postDiskWriteBytes = 0;
		FileSystem[] fileSystemList;
		try {
			fileSystemList = sigar.getFileSystemList();
			for(int i = 0; i < fileSystemList.length; ++i){
				postDiskWriteBytes += sigar.getFileSystemUsage(fileSystemList[i].getDirName()).getDiskWriteBytes();
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
		
		//the interval is ms
		//System.out.println("Disk Write Bytes: " + postDiskWriteBytes);
		this.physicalDiskModel.setDiskWriteRate((postDiskWriteBytes - preDiskWriteBytes)/((double)interval/1000)/1024);
		this.timer.cancel();
	}
}

class CalculateDiskReadRate extends TimerTask{
	private PhysicalDiskModel physicalDiskModel;
	//private DiskUsage diskUsage;
	private long preDiskReadBytes = 0;
	private long interval;
	private Timer timer;
	private Sigar sigar = new Sigar();
	
	public CalculateDiskReadRate(PhysicalDiskModel physicalDiskModel, Timer timer, long interval){
		this.physicalDiskModel = physicalDiskModel;
		FileSystem[] fileSystemList;
		try {
			fileSystemList = sigar.getFileSystemList();
			for(int i = 0; i < fileSystemList.length; ++i){
				this.preDiskReadBytes += sigar.getFileSystemUsage(fileSystemList[i].getDirName()).getDiskReadBytes();
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
		this.timer = timer;
		this.interval = interval;
	}
	@Override
	public void run() {
		long postDiskReadBytes = 0;
		FileSystem[] fileSystemList;
		try {
			fileSystemList = sigar.getFileSystemList();
			for(int i = 0; i < fileSystemList.length; ++i){
				postDiskReadBytes += sigar.getFileSystemUsage(fileSystemList[i].getDirName()).getDiskReadBytes();
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
		
		//the interval is ms
		//System.out.println("Disk Read Bytes: " + postDiskReadBytes);
		this.physicalDiskModel.setDiskReadRate((postDiskReadBytes - preDiskReadBytes)/((double)interval/1000)/1024);
		this.timer.cancel();
	}
}