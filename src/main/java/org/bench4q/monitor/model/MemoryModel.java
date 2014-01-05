package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.SigarException;
import org.hyperic.sigar.Swap;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.Mem;
import org.hyperic.sigar.CpuPerc;

@XmlRootElement(name="Memory")
public class MemoryModel {
	private long pagesPerSecond;
	private long pagesInputPerSecond;
	private long pagesOutputPerSecond;
	private long availableKiloBytes;
	private long totalKiloBytes;
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
		this.getPagesInputPerSecond();
		this.getPagesOutputPerSecond();
		this.getPagesPerSecond();
		this.getMemoryUsedPercent();
		this.getAvailableKiloBytes();
		this.getTotalKiloBytes();
	}
	
	@XmlElement
	public long getPagesPerSecond() {
		setPagesPerSecond(getPagesInputPerSecond() + getPagesOutputPerSecond());
		return pagesPerSecond;
	}
	public void setPagesPerSecond(long pagesPerSecond) {
		this.pagesPerSecond = pagesPerSecond;
	}
	
	@XmlElement
	public long getPagesInputPerSecond() {
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
	
	@XmlElement
	public long getPagesOutputPerSecond() {
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
	
	@XmlElement
	public long getAvailableKiloBytes() {
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setAvailableKiloBytes(mem.getFree()/1024L);
		return availableKiloBytes;
	}
	public void setAvailableKiloBytes(long availableKiloBytes) {
		this.availableKiloBytes = availableKiloBytes;
	}
	
	@XmlElement
	public long getTotalKiloBytes(){
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setTotalKiloBytes(mem.getTotal()/1024L);
		return totalKiloBytes;
	}
	public void setTotalKiloBytes(long totalKiloBytes){
		this.totalKiloBytes = totalKiloBytes;
	}
	
	@XmlElement
	public String getMemoryUsedPercent(){
		try {
			mem = sigar.getMem();
		} catch (SigarException e) {
			e.printStackTrace();
		}
		setMemoryUsedPercent(mem.getUsedPercent());
		return CpuPerc.format(memoryUsedPercent/100);
	}
	public void setMemoryUsedPercent(double memoryUsedPercent){
		this.memoryUsedPercent = memoryUsedPercent;
	}
}
