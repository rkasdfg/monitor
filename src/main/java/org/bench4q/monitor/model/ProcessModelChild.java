package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.ProcTime;
import org.hyperic.sigar.ProcCpu;
import org.hyperic.sigar.ProcMem;
import org.hyperic.sigar.ProcState;
import org.hyperic.sigar.SigarException;
import org.hyperic.sigar.cmd.SigarCommandBase;
import org.hyperic.sigar.cmd.Shell;

@XmlRootElement
public class ProcessModelChild extends SigarCommandBase{
	private String instanceString;
	private long residentBytes;
	private double processorTimePercent;
	private long processId;
	private long virtualBytes;
	private Sigar sigar = new Sigar();
	
	//test code
	//using process xiami to test
	public static void main(String[] args) throws SigarException{
		ProcessModelChild child = new ProcessModelChild(3206);
//		System.out.println(child.getInstanceString());
//		System.out.println(child.getProcessorTimePercent());
//		child.getResidentMemory();
		String[] arg = null;
		child.output(arg);
	}
	
	public ProcessModelChild(long processId){
		this.processId = processId;
	}
	
	public ProcessModelChild(Shell shell){
		super(shell);
	}
	
	public double getProcessorTimePercent() {
		try {
			ProcCpu procCpu = sigar.getProcCpu(processId);
			setProcessorTimePercent(procCpu.getPercent());
			System.out.println("GET PERC: " + procCpu.getPercent());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		return processorTimePercent;
	}
	public void setProcessorTimePercent(double processorTimePercent) {
		this.processorTimePercent = processorTimePercent;
	}
	
	public String getInstanceString() {
		try {
			ProcState procState = sigar.getProcState(processId);
			setInstanceString(procState.getName());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		return instanceString;
	}
	public void setInstanceString(String instanceString) {
		this.instanceString = instanceString;
	}
	
	public long getProcessId() {
		return processId;
	}
	public void setProcessId(long processId) {
		this.processId = processId;
	}
	
	public long getVirtualBytes() {
		try {
			ProcMem procMem = sigar.getProcMem(processId);
			setVirtualBytes(procMem.getSize());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		return virtualBytes;
	}
	public void setVirtualBytes(long virtualBytes) {
		this.virtualBytes = virtualBytes;
	}

	public long getResidentBytes() {
		try {
			ProcMem procMem = sigar.getProcMem(processId);
			setPrivateBytes(procMem.getResident());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		return residentBytes;
	}
	public void setPrivateBytes(long residentBytes) {
		this.residentBytes = residentBytes;
	}

	@Override
	public void output(String[] arg0) throws SigarException {
		ProcMem procMem = sigar.getProcMem(2477);
		System.out.println("redisent mem: " + procMem.getResident());
		System.out.println("shared mem: " + procMem.getShare());
		System.out.println("virtual mem: " + procMem.getSize());
	}
	
}
