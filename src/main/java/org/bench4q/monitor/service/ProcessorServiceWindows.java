package org.bench4q.monitor.service;

import org.bench4q.monitor.model.ProcessorModel;
import org.bench4q.monitor.model.ProcessorModelChild;
import org.springframework.beans.factory.annotation.Autowired;

public class ProcessorServiceWindows {
	public ProcessorServiceWindows() {
		// TODO Auto-generated constructor stub
		this.processorMonitor = new ProcessorModel();
	}

	private ProcessorModel processorMonitor;

	public ProcessorModel getProcessorMonitor() {
		return processorMonitor;
	}

	@Autowired
	public void setProcessorMonitor(ProcessorModel processorMonitor) {
		this.processorMonitor = processorMonitor;
	}

	public ProcessorModel getProcessorInfo(int idleTime) {
		
		ProcessorModel processorModel = new ProcessorModel();
		/*String instances[] = this.getProcessorMonitor().getInstances();
		for (String elem : instances) {
			ProcessorModelChild processorModelChild = new ProcessorModelChild();
			processorModelChild.setInstance(elem);
			processorModelChild.setPrivilegedTimePercent(this
					.getProcessorMonitor().getPrivilegedTimePercent(elem,
							idleTime));
			processorModelChild.setProcessorTimePercent(this
					.getProcessorMonitor().getProcessorTimePercent(elem,
							idleTime));
			processorModelChild.setUserTimePercent(this.getProcessorMonitor()
					.getUserTimePercent(elem, idleTime));
			processorModel.getProcessorModelList().add(processorModelChild);
		}*/
		return processorModel;
	}

}
