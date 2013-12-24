package org.bench4q.monitor.model;



import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;
@XmlRootElement(name = "NetworkInterface")
public class NetworkInterfaceModel {
	private List<NetworkInterfaceModelChild> networkList;
	  @XmlElementWrapper
      @XmlElement(name="Instance",type=NetworkInterfaceModelChild.class)      
	public List<NetworkInterfaceModelChild> getNetworkList() {
		return networkList;
	}

	public void setNetworkList(List<NetworkInterfaceModelChild> networkList) {
		this.networkList = networkList;
	}
	public NetworkInterfaceModel(){
		this.networkList=new ArrayList<NetworkInterfaceModelChild>();
	}
}
