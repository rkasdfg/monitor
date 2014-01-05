package org.bench4q.monitor.model;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import javax.xml.bind.annotation.XmlRootElement;

import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "NetworkInterface")
public class NetworkInterfaceModel {
	private List<NetworkInterfaceModelChild> networkList;
	private Sigar sigar = new Sigar();  
	  
	@XmlElementWrapper(name="network_interfaces")
	@XmlElement(name="network_interface",type=NetworkInterfaceModelChild.class) 
	public List<NetworkInterfaceModelChild> getNetworkList() {
		return networkList;
	}
	public void setNetworkList(List<NetworkInterfaceModelChild> networkList) {
		this.networkList = networkList;
	}
	public NetworkInterfaceModel(){
		this.networkList = new ArrayList<NetworkInterfaceModelChild>();
		try {
			String[] netInterfaceList = sigar.getNetInterfaceList();
			for(int i = 0; i < netInterfaceList.length; ++i){
				NetworkInterfaceModelChild networkInterfaceModelChild = new NetworkInterfaceModelChild(netInterfaceList[i]);
				this.networkList.add(networkInterfaceModelChild);
			}
		} catch (SigarException e) {
			e.printStackTrace();
		}
	}
}
