package org.bench4q.monitor.service;

import org.bench4q.monitor.model.ProcessModel;
import org.bench4q.monitor.model.ProcessModelChild;

public class ProcessServiceWindows {
	public ProcessServiceWindows() {
		this.processMonitor = new ProcessModel();
	}

	private ProcessModel processMonitor;

	public ProcessModel getProcessMonitor() {
		return processMonitor;
	}

	public void setProcessMonitor(ProcessModel processMonitor) {
		this.processMonitor = processMonitor;
	}

	public ProcessModel getProcessInfo(int idleTime) {

		ProcessModel processModel = new ProcessModel();
		/*String instances[] = processMonitor.getInstances();
		for (String elem : instances) {
			ProcessModelChild processModelChild = new ProcessModelChild();
			processModelChild.setInstanceString(elem);
			processModelChild.setPrivateBytes(this.getProcessMonitor()
					.getPrivateBytes(elem));
			processModelChild.setProcessId(this.getProcessMonitor().getProcessId(elem));
		 processModelChild.setProcessorTimePercent(this.getProcessMonitor().getProcessorTimePercent(elem, idleTime));
			
			processModelChild.setVirtualBytes(this.getProcessMonitor().getVirtualBytes(elem));
			processModel.getProcesModelList().add(processModelChild);
		}*/
		return processModel;

	}

}
