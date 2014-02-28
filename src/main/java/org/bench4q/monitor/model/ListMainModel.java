package org.bench4q.monitor.model;

import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name="historylist")
public class ListMainModel {
	private List<MainModel> historylist;
	
	@XmlElementWrapper(name="histories")
	@XmlElement(name="history",type=MainModel.class) 
	public List<MainModel> getHistorylist() {
		return historylist;
	}
	public void setHistorylist(List<MainModel> historylist) {
		this.historylist = historylist;
	}

}
