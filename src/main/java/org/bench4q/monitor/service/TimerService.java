package org.bench4q.monitor.service;

import java.io.File;
import java.util.TimerTask;

import org.hyperic.sigar.SigarException;

public class TimerService extends TimerTask {
	@Override
	public void run(){
		WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
		String filePath = System.getProperty("user.dir")+"/sigartmp";
		new File(filePath).mkdirs(); 
		testWrite.setSavaPath("sigartmp/");		
		try {
			testWrite.writeCurrentSystemInfoToLocalDisk();
		} catch (SigarException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
