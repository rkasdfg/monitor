package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
@XmlRootElement(name="PhisicalDisk")
public class PhysicalDiskModel {
	private double diskReadRate;
	private double diskWriteRate;
	private double curDiskQueLength;
	
	@XmlElement
	public double getDiskReadRate() {
		return diskReadRate;
	}
	public void setDiskReadRate(double diskReadRate) {
		this.diskReadRate = diskReadRate;
	}
	@XmlElement
	public double getDiskWriteRate() {
		return diskWriteRate;
	}
	public void setDiskWriteRate(double diskWriteRate) {
		this.diskWriteRate = diskWriteRate;
	}
	@XmlElement
	public double getCurDiskQueLength() {
		return curDiskQueLength;
	}
	public void setCurDiskQueLength(double curDiskQueLength) {
		this.curDiskQueLength = curDiskQueLength;
	}

}
