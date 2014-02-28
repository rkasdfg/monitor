package org.bench4q.monitor.service;

import java.io.File;
import java.util.TimerTask;
import java.util.concurrent.ExecutionException;

import org.hyperic.sigar.SigarException;

public class TimerService extends TimerTask {
	@Override
	public void run(){
		WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
		String filePath = System.getProperty("user.dir")+"/sigartmp";
		new File(filePath).mkdirs(); 
		testWrite.setSavaPath("sigartmp/");		
		try {
			try {
				testWrite.writeCurrentSystemInfoToLocalDisk();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ExecutionException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (SigarException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
