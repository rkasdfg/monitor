package org.bench4q.monitor.model;

import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.ProcCpu;
import org.hyperic.sigar.ProcMem;
import org.hyperic.sigar.ProcState;
import org.hyperic.sigar.SigarException;

public class ProcessSigarReleatedModel {
	private ProcCpu procCpu;
	private ProcState procState;
	private ProcMem procMem;

	public ProcessSigarReleatedModel(long pid) throws SigarException {
		
		this.setProcCpu(GetSigar.getSigar().getProcCpu(pid));
		this.setProcMem(GetSigar.getSigar().getProcMem(pid));
		this.setProcState(GetSigar.getSigar().getProcState(pid));
	}

	public ProcCpu getProcCpu() {
		return procCpu;
	}

	private void setProcCpu(ProcCpu procCpu) {
		this.procCpu = procCpu;
	}

	public ProcState getProcState() {
		return procState;
	}

	private void setProcState(ProcState procState) {
		this.procState = procState;
	}

	public ProcMem getProcMem() {
		return procMem;
	}

	private void setProcMem(ProcMem procMem) {
		this.procMem = procMem;
	}

}
