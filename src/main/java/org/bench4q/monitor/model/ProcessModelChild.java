package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import org.hyperic.sigar.ProcCpu;
import org.hyperic.sigar.ProcMem;
import org.hyperic.sigar.ProcState;
import org.hyperic.sigar.SigarException;

@XmlRootElement
public class ProcessModelChild {
	private String instanceString;
	private long residentKBytes;
	private double processorTimePercent;
	private long memSize;
	private long processId;
	private long vSize;
	private ProcessSigarReleatedModel processSigarReleatedModel;

	public ProcessModelChild(long processId,
			ProcessSigarReleatedModel processSigarReleatedModel)
			throws SigarException {
		this.processSigarReleatedModel = processSigarReleatedModel;
		this.processId = processId;
		this.getProcessorTimePercent();
		this.getInstanceString();
		this.getResidentKBytes();
		this.getVSize();
	}

	@XmlElement
	public double getProcessorTimePercent() throws SigarException {
		ProcCpu procCpu = this.processSigarReleatedModel.getProcCpu();
		setProcessorTimePercent(procCpu.getPercent());
		return processorTimePercent;
	}

	public void setProcessorTimePercent(double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}

	@XmlElement
	public String getInstanceString() throws SigarException {
		ProcState procState = this.processSigarReleatedModel.getProcState();
		setInstanceString(procState.getName());

		return instanceString;
	}

	public void setInstanceString(String instanceString) {
		this.instanceString = instanceString;
	}

	@XmlElement
	public long getProcessId() {
		return processId;
	}

	public void setProcessId(long processId) {
		this.processId = processId;
	}

	@XmlElement
	public long getVSize() throws SigarException {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();
		
		setVSize(procMem.getSize()/1024L);
		return vSize;
	}

	public void setVSize(long virtualBytes) {
		this.vSize = virtualBytes;
	}

	@XmlElement
	public long getResidentKBytes() throws SigarException {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();
		setResidentKBytes(procMem.getResident()/1024L);
		return residentKBytes;
	}

	public void setResidentKBytes(long residentBytes) {
		this.residentKBytes = residentBytes;
	}

	@XmlElement
	public long getMemSize() {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();
		setMemSize(procMem.getSize());
		return memSize;
	}

	private void setMemSize(long memSize) {
		this.memSize = memSize;
	}
	
}
