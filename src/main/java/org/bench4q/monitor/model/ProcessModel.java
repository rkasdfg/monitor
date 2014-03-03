package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.bench4q.monitor.service.GetSigar;
import org.bench4q.monitor.service.GetThreadPool;
import org.hyperic.sigar.ProcState;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "Process")
public class ProcessModel {
	private Sigar sigar = GetSigar.getSigar();
	private List<ProcessModelChild> processModelList;
	private long[] processPids;
	private List<String> processNameList;
	private int size;

	public static void main(String args[]) throws SigarException,
			InterruptedException, ExecutionException {
		long time = System.currentTimeMillis();
		ProcessModel processModel = new ProcessModel();
		System.out.println("total process:"
				+ processModel.getProcessPids().length);
		for (int i = 0; i < processModel.getProcessPids().length; i++) {
			if (processModel.getProcesModelList().get(i) != null) {

				System.out.println("pid:"
						+ processModel.getProcesModelList().get(i)
								.getInstanceString());
				System.out.println("name:"
						+ processModel.getProcesModelList().get(i)
								.getProcessId());
				System.out.println("cpu percent:"
						+ processModel.getProcesModelList().get(i)
								.getProcessorTimePercent());
				System.out.println("getResidentKBytes:"
						+ processModel.getProcesModelList().get(i)
								.getResidentKBytes());
				System.out.println("virtural Kbytes:"
						+ processModel.getProcesModelList().get(i).getVSize());
				System.out
						.println(" Kbytes:"
								+ processModel.getProcesModelList().get(i)
										.getMemSize());
				break;

			}

		}

		System.out.println(System.currentTimeMillis() - time);

	}

	public ProcessModel() throws SigarException, InterruptedException,
			ExecutionException {
		this.setProcessPids();
		this.setProcesModelList();
		this.setProcessNameList();
		this.setSize();
	}

	@XmlElement
	public int getSize() {
		return this.size;
	}

	private void setSize() throws SigarException {
		this.size = sigar.getProcList().length;
	}

	@XmlElementWrapper
	@XmlElement(name = "Instance", type = ProcessModelChild.class)
	public List<ProcessModelChild> getProcesModelList() {
		return processModelList;
	}

	public void setProcesModelList() throws SigarException,
			InterruptedException, ExecutionException {
		this.processModelList = new ArrayList<ProcessModelChild>();
		List<Future<ProcessModelChild>> futures = new ArrayList<Future<ProcessModelChild>>();
		for (int i = 0; i < this.processPids.length; ++i) {
			try {
				futures.add(GetThreadPool.getExecutorService().submit(
						new NewProcessChild(processPids[i],
								new ProcessSigarReleatedModel(processPids[i]))));
			} catch (SigarException e) {
				processModelList.add(new ProcessModelChild(processPids[i]));
			}
		}
		for (Future<ProcessModelChild> future : futures) {
			processModelList.add(future.get());
		}

	}

	public long[] getProcessPids() {
		return processPids;
	}

	private void setProcessPids() throws SigarException {
		this.processPids = sigar.getProcList();
	}

	@XmlElementWrapper(name = "processNameList")
	@XmlElement(name = "processName", type = String.class)
	public List<String> getProcessNameList() {
		return processNameList;
	}

	private void setProcessNameList() throws SigarException {
		this.processNameList = new ArrayList<String>();
		for (long pid : this.getProcessPids()) {
			ProcState procState = sigar.getProcState(pid);
			processNameList.add(procState.getName());
		}
	}

}

class NewProcessChild implements Callable<ProcessModelChild> {
	private long pid;
	private ProcessSigarReleatedModel processSigarReleatedModel;

	public NewProcessChild(long pid,
			ProcessSigarReleatedModel processSigarReleatedModel) {
		this.pid = pid;
		this.processSigarReleatedModel = processSigarReleatedModel;
	}

	public ProcessModelChild call() {
		try {
			return new ProcessModelChild(pid, processSigarReleatedModel);
		} catch (SigarException e) {
			return new ProcessModelChild(pid);
		}
	}
}