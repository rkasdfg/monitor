package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.DataFomat;
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
		this.setProcessId(processId);
		this.setInstanceString();
		this.setProcessorTimePercent();
		this.setMemSize();
		this.setResidentKBytes();
		this.setVSize();

	}

	@XmlElement
	public double getProcessorTimePercent() throws SigarException {
		return processorTimePercent;
	}

	private void setProcessorTimePercent() {
		ProcCpu procCpu = this.processSigarReleatedModel.getProcCpu();
		this.processorTimePercent = DataFomat.fomatToPercent(procCpu
				.getPercent());
	}

	@XmlElement
	public String getInstanceString() throws SigarException {
		return instanceString;
	}

	private void setInstanceString() {
		ProcState procState = this.processSigarReleatedModel.getProcState();
		this.instanceString = procState.getName();

	}

	@XmlElement
	public long getProcessId() {
		return processId;
	}

	private void setProcessId(long processId) {
		this.processId = processId;
	}

	@XmlElement
	public long getVSize() throws SigarException {

		return vSize;
	}

	private void setVSize() {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();

		this.vSize = procMem.getSize() / 1024L;
	}

	@XmlElement
	public long getResidentKBytes() throws SigarException {

		return residentKBytes;
	}

	private void setResidentKBytes() {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();
		this.residentKBytes = procMem.getResident() / 1024L;
	}

	@XmlElement
	public long getMemSize() {
		return memSize;
	}

	private void setMemSize() {
		ProcMem procMem = this.processSigarReleatedModel.getProcMem();
		this.memSize = procMem.getSize();
	}

}
