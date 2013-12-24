package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class SystemModel {

	private double fileDataOperationsPerSecond;

	public double getFileDataOperationsPerSecond() {
		return fileDataOperationsPerSecond;
	}

	public void setFileDataOperationsPerSecond(
			double fileDataOperationsPerSecond) {
		this.fileDataOperationsPerSecond = fileDataOperationsPerSecond;
	}

	public double getProcessorQueueLength() {
		return processorQueueLength;
	}

	public void setProcessorQueueLength(double processorQueueLength) {
		this.processorQueueLength = processorQueueLength;
	}

	private double processorQueueLength;
	double totalProceesorTimePercent;

	public double getTotalProceesorTimePercent() {
		return totalProceesorTimePercent;
	}

	public void setTotalProceesorTimePercent(double totalProceesorTimePercent2) {
		// TODO Auto-generated method stub
		this.totalProceesorTimePercent = totalProceesorTimePercent2;
	}

}
