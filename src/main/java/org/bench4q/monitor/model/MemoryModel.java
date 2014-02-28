package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.apache.log4j.Logger;
import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.SigarException;
import org.hyperic.sigar.Swap;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.Mem;

@XmlRootElement(name = "Memory")
public class MemoryModel {
	private long pagesPerSecond;
	private long pagesInputPerSecond;
	private long pagesOutputPerSecond;
	private long availableKiloBytes;
	private long totalKiloBytes;
	private double memoryUsedPercent;
	private Sigar sigar = GetSigar.getSigar();
	private Swap swap;
	private Mem mem;
	private Logger logger = Logger.getLogger(MemoryModel.class);

	// test code
	public static void main(String[] args) throws SigarException {
		MemoryModel model = new MemoryModel();
		System.out.println(model.logger.getLoggerRepository());
		System.out.println("PagesRate: " + model.getPagesPerSecond());
		System.out.println("PagesIn: " + model.getPagesInputPerSecond());
		System.out.println("PagesIn: " + model.getPagesOutputPerSecond());
		System.out.println("UsedPerc: " + model.getMemoryUsedPercent()+"%");
		System.out.println("Total: " + model.getTotalKiloBytes()+"kb");
		System.out.println("Aval: " + model.getAvailableKiloBytes()+"kb");
	}

	public MemoryModel() throws SigarException {
		this.getPagesInputPerSecond();
		this.getPagesOutputPerSecond();
		this.getPagesPerSecond();
		this.getMemoryUsedPercent();
		this.getAvailableKiloBytes();
		this.getTotalKiloBytes();
	}

	@XmlElement
	public long getPagesPerSecond() throws SigarException {
		setPagesPerSecond(getPagesInputPerSecond() + getPagesOutputPerSecond());
		return pagesPerSecond;
	}

	private void setPagesPerSecond(long pagesPerSecond) {
		this.pagesPerSecond = pagesPerSecond;
	}

	@XmlElement
	public long getPagesInputPerSecond() throws SigarException {
			swap = sigar.getSwap();
		setPagesInputPerSecond(swap.getPageIn());
		return pagesInputPerSecond;
	}

	private void setPagesInputPerSecond(long pagesInputPerSecond) {
		this.pagesInputPerSecond = pagesInputPerSecond;
	}

	@XmlElement
	public long getPagesOutputPerSecond() throws SigarException {
			swap = sigar.getSwap();
		setPagesOutputPerSecond(swap.getPageOut());
		return pagesOutputPerSecond;
	}

	private void setPagesOutputPerSecond(long pagesOutputPerSecond) {
		this.pagesOutputPerSecond = pagesOutputPerSecond;
	}

	@XmlElement
	public long getAvailableKiloBytes() throws SigarException {
			mem = sigar.getMem();
		setAvailableKiloBytes(mem.getFree() / 1024L);
		return availableKiloBytes;
	}

	private void setAvailableKiloBytes(long availableKiloBytes) {
		this.availableKiloBytes = availableKiloBytes;
	}

	@XmlElement
	public long getTotalKiloBytes() throws SigarException {
			mem = sigar.getMem();
		setTotalKiloBytes(mem.getTotal() / 1024L);
		return totalKiloBytes;
	}

	private void setTotalKiloBytes(long totalKiloBytes) {
		this.totalKiloBytes = totalKiloBytes;
	}

	@XmlElement
	public double getMemoryUsedPercent() throws SigarException {
			mem = sigar.getMem();
		long temp = Math.round(mem.getUsedPercent() * 100);
		setMemoryUsedPercent(temp / 100.0);
		return this.memoryUsedPercent;
	}

	private void setMemoryUsedPercent(double memoryUsedPercent) {
		this.memoryUsedPercent = memoryUsedPercent;
	}
}
