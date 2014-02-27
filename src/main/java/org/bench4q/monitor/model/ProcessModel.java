package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.ProcCpu;
import org.hyperic.sigar.ProcMem;
import org.hyperic.sigar.ProcState;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;
import org.hyperic.sigar.SigarPermissionDeniedException;

@XmlRootElement(name = "Process")
public class ProcessModel {
	private Sigar sigar = GetSigar.getSigar();
	private List<ProcessModelChild> processModelList;
	private long[] processPids;

	public static void main(String args[]) throws SigarException {
		long time = System.currentTimeMillis();
		ProcessModel processModel = new ProcessModel();

		System.out.println("total process:"+processModel.getProcessPids().length);
		for(int i=0;i<processModel.getProcessPids().length;i++){
			if(processModel.getProcesModelList().get(i)!=null){
				
				System.out.println("pid:"+processModel.getProcesModelList().get(i)
						.getInstanceString());
				System.out.println("name:"+processModel.getProcesModelList().get(i)
						.getProcessId());
				System.out.println("cpu percent:"+processModel.getProcesModelList().get(i)
						.getProcessorTimePercent());
				System.out.println("getResidentBytes:"+processModel.getProcesModelList().get(i)
						.getResidentKBytes());
				System.out.println("virtural bytes:"+processModel.getProcesModelList().get(i)
						.getVSize());
				System.out.println(" bytes:"+processModel.getProcesModelList().get(i)
						.getMemSize());
				break;
				
			}
			
		}
	
	
		System.out.println(System.currentTimeMillis() - time);

	}

	public ProcessModel() throws SigarException {
		this.setProcessPids();
		this.setProcesModelList();

	}

	@XmlElementWrapper
	@XmlElement(name = "Instance", type = ProcessModelChild.class)
	public List<ProcessModelChild> getProcesModelList() {
		return processModelList;
	}

	public void setProcesModelList() throws SigarException {
		this.processModelList = new ArrayList<ProcessModelChild>();
		for (int i = 0; i < this.processPids.length; ++i) {
			ProcessModelChild processModelChild;
			try {
				processModelChild = new ProcessModelChild(processPids[i],
						new ProcessSigarReleatedModel(processPids[i]));
			} catch (SigarPermissionDeniedException e) {
				processModelChild = null;
			}
			processModelList.add(processModelChild);
		}
	}

	public long[] getProcessPids() {
		return processPids;
	}

	private void setProcessPids() throws SigarException {
		this.processPids = sigar.getProcList();
	}

}

class ProcessSigarReleatedModel {
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
