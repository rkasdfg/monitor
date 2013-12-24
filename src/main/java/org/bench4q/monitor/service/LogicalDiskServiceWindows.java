package org.bench4q.monitor.service;

import org.bench4q.monitor.model.LogicalDiskModel;
import org.bench4q.monitor.model.LogicalDiskModelChild;

public class LogicalDiskServiceWindows {
	private LogicalDiskModel logicalDiskMonitor;

	public LogicalDiskServiceWindows() {
		this.setLogicalDiskMonitor(new LogicalDiskModel());
	}

	public LogicalDiskModel getLogicalDiskMonitor() {
		return logicalDiskMonitor;
	}

	public void setLogicalDiskMonitor(LogicalDiskModel logicalDiskMonitor) {
		this.logicalDiskMonitor = logicalDiskMonitor;
	}

	public LogicalDiskModel getLogicalDiskInfo(int idleTime) {
		LogicalDiskModel logicalDiskModel = new LogicalDiskModel();
		/*String[] instances = this.getLogicalDiskMonitor().getInstances();
		

		for (String elem : instances) {

			LogicalDiskModelChild logicalDiskModelChild = new LogicalDiskModelChild();
			logicalDiskModelChild.setInstance(elem);
			logicalDiskModelChild.setDiskBytesPerSecond(this
					.getLogicalDiskMonitor().getDiskBytesPerSecond(elem,
							idleTime));
			logicalDiskModelChild.setDiskWriteBytesPerSecond(this
					.getLogicalDiskMonitor().getDiskWriteBytesPerSecond(elem,
							idleTime));
			logicalDiskModelChild.setDiskReadBytesPerSecond(this
					.getLogicalDiskMonitor().getDiskReadsPerSecond(elem,
							idleTime));
			logicalDiskModelChild.setAverageDiskQueueLength(this
					.getLogicalDiskMonitor().getAverageDiskQueueLength(elem,
							idleTime));
			logicalDiskModelChild.setAverageDiskReadTimeInSecond(this
					.getLogicalDiskMonitor().getAverageDiskReadQueueLength(
							elem, idleTime));

			logicalDiskModelChild.setAverageDiskTransferTimeInSecond(this
					.getLogicalDiskMonitor()
					.getAverageDiskTransferTimeInSecond(elem, idleTime));
			logicalDiskModelChild.setCurrentDiskQueueLength(this
					.getLogicalDiskMonitor().getCurrentDiskQueueLength(elem));
			logicalDiskModelChild.setAverageDiskWriteTimeInSecond(this
					.getLogicalDiskMonitor().getAverageDiskWriteTimeInSecond(
							elem, idleTime));

			logicalDiskModelChild.setDiskReadTimePercent(this
					.getLogicalDiskMonitor().getDiskReadTimePercent(elem,
							idleTime));
			logicalDiskModelChild
					.setDiskTimePercent(this.getLogicalDiskMonitor()
							.getDiskTimePercent(elem, idleTime));
			logicalDiskModelChild.setDiskWriteTimePercent(this
					.getLogicalDiskMonitor().getDiskWriteTimePercent(elem,
							idleTime));

			logicalDiskModelChild.setFreeMegabytes(this.getLogicalDiskMonitor()
					.getFreeMegabytes(elem));
			logicalDiskModelChild.setFreeSpacePercent(this
					.getLogicalDiskMonitor().getFreeSpacePercent(elem));
			logicalDiskModelChild
					.setIdleTimePercent(this.getLogicalDiskMonitor()
							.getIdleTimePercent(elem, idleTime));

			logicalDiskModel.getLogicalDiskList().add(logicalDiskModelChild);
		}*/
		return logicalDiskModel;
	}

}
