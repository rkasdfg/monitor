package org.bench4q.monitor.service;

import java.util.TimerTask;

public class TimerService extends TimerTask {
	@Override
	public void run(){
		WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
		testWrite.setSavaPath("D:/sigartmp/");		
		testWrite.writeCurrentSystemInfoToLocalDisk();
	}

}
