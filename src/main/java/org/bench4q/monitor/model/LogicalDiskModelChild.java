package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class LogicalDiskModelChild{
	private String instance;
	private double freeSpacePercent;
	private double freeMegabytes;

	// ���̻�ٷֱ�
	private double diskTimePercent;
	private double diskReadTimePercent;
	private double diskWriteTimePercent;

	// ����ƽ��ʱ��
	private double averageDiskTransferTimeInSecond;
	private double averageDiskReadTimeInSecond;
	private double averageDiskWriteTimeInSecond;
	// ����ƽ������ֽ�
	
	
	private double diskBytesPerSecond;

	private double  diskReadBytesPerSecond;
	private double diskWriteBytesPerSecond;

	// ���аٷֱ�
	private double idleTimePercent;
	// ƽ����г���
	private double averageDiskQueueLength;
	// ��ǰ���г���
	private double currentDiskQueueLength;
	public String getInstance() {
		return instance;
	}
	public void setInstance(String instance) {
		this.instance = instance;
	}
	public double getFreeSpacePercent() {
		return freeSpacePercent;
	}
	public void setFreeSpacePercent(double freeSpacePercent) {
		this.freeSpacePercent = freeSpacePercent;
	}
	public double getFreeMegabytes() {
		return freeMegabytes;
	}
	public void setFreeMegabytes(double freeMegabytes) {
		this.freeMegabytes = freeMegabytes;
	}
	public double getDiskTimePercent() {
		return diskTimePercent;
	}
	public void setDiskTimePercent(double diskTimePercent) {
		this.diskTimePercent = diskTimePercent;
	}
	public double getDiskReadTimePercent() {
		return diskReadTimePercent;
	}
	public void setDiskReadTimePercent(double diskReadTimePercent) {
		this.diskReadTimePercent = diskReadTimePercent;
	}
	public double getDiskWriteTimePercent() {
		return diskWriteTimePercent;
	}
	public void setDiskWriteTimePercent(double diskWriteTimePercent) {
		this.diskWriteTimePercent = diskWriteTimePercent;
	}
	public double getAverageDiskTransferTimeInSecond() {
		return averageDiskTransferTimeInSecond;
	}
	public void setAverageDiskTransferTimeInSecond(
			double averageDiskTransferTimeInSecond) {
		this.averageDiskTransferTimeInSecond = averageDiskTransferTimeInSecond;
	}
	public double getAverageDiskReadTimeInSecond() {
		return averageDiskReadTimeInSecond;
	}
	public void setAverageDiskReadTimeInSecond(double averageDiskReadTimeInSecond) {
		this.averageDiskReadTimeInSecond = averageDiskReadTimeInSecond;
	}
	public double getAverageDiskWriteTimeInSecond() {
		return averageDiskWriteTimeInSecond;
	}
	public void setAverageDiskWriteTimeInSecond(double averageDiskWriteTimeInSecond) {
		this.averageDiskWriteTimeInSecond = averageDiskWriteTimeInSecond;
	}
	
	public double getDiskBytesPerSecond() {
		return diskBytesPerSecond;
	}
	public void setDiskBytesPerSecond(double diskBytesPerSecond) {
		this.diskBytesPerSecond = diskBytesPerSecond;
	}
	public double getDiskReadBytesPerSecond() {
		return diskReadBytesPerSecond;
	}
	public void setDiskReadBytesPerSecond(double diskReadBytesPerSecond) {
		this.diskReadBytesPerSecond = diskReadBytesPerSecond;
	}
	public double getDiskWriteBytesPerSecond() {
		return diskWriteBytesPerSecond;
	}
	public void setDiskWriteBytesPerSecond(double diskkWriteBytesPerSecond) {
		this.diskWriteBytesPerSecond = diskkWriteBytesPerSecond;
	}
	public double getIdleTimePercent() {
		return idleTimePercent;
	}
	public void setIdleTimePercent(double idleTimePercent) {
		this.idleTimePercent = idleTimePercent;
	}
	public double getAverageDiskQueueLength() {
		return averageDiskQueueLength;
	}
	public void setAverageDiskQueueLength(double averageDiskQueueLength) {
		this.averageDiskQueueLength = averageDiskQueueLength;
	}
	public double getCurrentDiskQueueLength() {
		return currentDiskQueueLength;
	}
	public void setCurrentDiskQueueLength(double currentDiskQueueLength) {
		this.currentDiskQueueLength = currentDiskQueueLength;
	}
	
	

}
