package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.SigarException;
import org.hyperic.sigar.Swap;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.Mem;

@XmlRootElement(name="Memory")
public class MemoryModel {
	
//	private double pageFaultsPerSecond;
	private double pagesPerSecond;
	private long pagesInputPerSecond;
	private long pagesOutputPerSecond;
	private double cacheBytes;
	private double committedBytes;
	private double availableKiloBytes;
	private double totalKiloBytes;
	private double memoryUsedPercent;
	private Sigar sigar = new Sigar();
	private Swap swap;
	private Mem mem;
	
	//test code
	public static void main(String[] args){
		MemoryModel model = new MemoryModel();
		System.out.println("PagesRate: "+model.getPagesPerSecond());
		System.out.println("PagesIn: "+model.getPagesInputPerSecond());
		System.out.println("PagesIn: "+model.getPagesOutputPerSecond());
		System.out.println("UsedPerc: "+model.getMemoryUsedPercent());
		System.out.println("Total: "+model.getTotalKiloBytes());
		System.out.println("Aval: "+model.getAvailableKiloBytes());
	}
	
	public MemoryModel(){
		try {
			swap = sigar.getSwap();
			mem = sigar.getMem();
		} catch (SigarException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public double getPagesPerSecond() {
		setPagesPerSecond(getPagesInputPerSecond() + getPagesOutputPerSecond());
		return pagesPerSecond;
	}
	public void setPagesPerSecond(double pagesPerSecond) {
		this.pagesPerSecond = pagesPerSecond;
	}
	public double getPagesInputPerSecond() {
		try {
			swap = sigar.getSwap();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setPagesInputPerSecond(swap.getPageIn());
		return pagesInputPerSecond;
	}
	public void setPagesInputPerSecond(long pagesInputPerSecond) {
		this.pagesInputPerSecond = pagesInputPerSecond;
	}
	public double getPagesOutputPerSecond() {
		try {
			swap = sigar.getSwap();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setPagesOutputPerSecond(swap.getPageOut());
		return pagesOutputPerSecond;
	}
	public void setPagesOutputPerSecond(long pagesOutputPerSecond) {
		this.pagesOutputPerSecond = pagesOutputPerSecond;
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
	public double getAvailableKiloBytes() {
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setAvailableKiloBytes(mem.getFree());
		return availableKiloBytes;
	}
	public void setAvailableKiloBytes(double availableKiloBytes) {
		this.availableKiloBytes = availableKiloBytes;
	}
	public double getTotalKiloBytes(){
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setTotalKiloBytes(mem.getTotal());
		return totalKiloBytes;
	}
	public void setTotalKiloBytes(double totalKiloBytes){
		this.totalKiloBytes = totalKiloBytes;
	}
	public double getMemoryUsedPercent(){
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setMemoryUsedPercent(mem.getUsedPercent());
		return memoryUsedPercent;
	}
	public void setMemoryUsedPercent(double memoryUsedPercent){
		this.memoryUsedPercent = memoryUsedPercent;
	}
}
