package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name="Memory")
public class MemoryModel {
	
//	private double pageFaultsPerSecond;//������Ӳȱҳ
	private double pagesPerSecond;
	private double pagesInputPerSecond;
	private double pagesOutputPerSecond;
	private double cacheBytes;
	private double committedBytes;//ռ�õ������ڴ���ֽ�
	private double availableKiloBytes;
	
	
	public double getPagesPerSecond() {
		return pagesPerSecond;
	}
	public void setPagesPerSecond(double pagesPerSecond) {
		this.pagesPerSecond = pagesPerSecond;
	}
	public double getPagesInputPerSecond() {
		return pagesInputPerSecond;
	}
	public void setPagesInputPerSecond(double pagesInputPerSecond) {
		this.pagesInputPerSecond = pagesInputPerSecond;
	}

	public double getCacheBytes() {
		return cacheBytes;
	}
	public void setCacheBytes(double cacheBytes) {
		this.cacheBytes = cacheBytes;
	}
	
	
		public double getCommittedBytes() {
		return committedBytes;
	}
	public void setCommittedBytes(double committedBytes) {
		this.committedBytes = committedBytes;
	}
	public double getPagesOutputPerSecond() {
		return pagesOutputPerSecond;
	}
	public void setPagesOutputPerSecond(double pagesOutputPerSecond) {
		this.pagesOutputPerSecond = pagesOutputPerSecond;
	}
	public double getAvailableKiloBytes() {
		return availableKiloBytes;
	}
	public void setAvailableKiloBytes(double availableKiloBytes) {
		this.availableKiloBytes = availableKiloBytes;
	}
}
