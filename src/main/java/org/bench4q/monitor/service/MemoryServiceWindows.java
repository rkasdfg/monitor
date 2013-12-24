package org.bench4q.monitor.service;

import org.bench4q.monitor.model.MemoryModel;

public class MemoryServiceWindows {

	public MemoryServiceWindows() {
		// TODO Auto-generated constructor stub
		this.memoryMonitor = new MemoryModel();
	}

	private MemoryModel memoryMonitor;

	public MemoryModel getMemoryMonitor() {
		return memoryMonitor;
	}

	public void setMemoryMonitor(MemoryModel memoryMonitor) {
		this.memoryMonitor = memoryMonitor;
	}

	public MemoryModel getMemoryInfo(int idleTime) {
		// double
		// getPageFaultsPerSecond=memoryMonitor.getPageFaultsPerSecond(idleTime);//锟斤拷锟斤拷锟斤拷硬缺页
		/*
		
		double getPagesPerSecond = memoryMonitor.getPagesPerSecond(idleTime);
		double getPagesInputPerSecond = memoryMonitor
				.getPagesInputPerSecond(idleTime);
		double getPageOuputPerSecond = memoryMonitor
				.getPagesOutputPerSecond(idleTime);
		double getCacheBytes = memoryMonitor.getCacheBytes();
		double getCommittedBytes = memoryMonitor.getCommittedBytes();// 占锟矫碉拷锟斤拷锟斤拷锟节达拷锟斤拷纸锟�?
		double getAvailableKiloBytes = memoryMonitor.getAvailableKiloBytes();
		MemoryModel memoryModel = new MemoryModel();
		memoryModel.setAvailableKiloBytes(getAvailableKiloBytes);
		memoryModel.setCacheBytes(getCacheBytes);
		memoryModel.setCommittedBytes(getCommittedBytes);
		memoryModel.setPagesOutputPerSecond(getPageOuputPerSecond);
		memoryModel.setPagesInputPerSecond(getPagesInputPerSecond);
		memoryModel.setPagesPerSecond(getPagesPerSecond);*/
		return this.memoryMonitor;

	}

}
