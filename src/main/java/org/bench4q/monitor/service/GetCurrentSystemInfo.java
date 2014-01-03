package org.bench4q.monitor.service;

import java.util.List;
import java.util.Date;
import java.text.SimpleDateFormat;

import org.bench4q.monitor.model.*;

public class GetCurrentSystemInfo {
	
	public MainModel getCurrentSystemInfo(){
		Date date = new Date();
		MainModel mainModel = new MainModel(date);   
		return mainModel;
	}
}
