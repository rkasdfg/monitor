package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import java.util.Timer;
import java.util.TimerTask;
import org.hyperic.sigar.NetInterfaceStat;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement
public class NetworkInterfaceModelChild {
	private double kiloBytesTotalPerSecond;
	private double kiloBytesReceivedPerSecond;
	private double kiloBytesSentPerSecond;
	private String address;
	private String instance;
	private Sigar sigar = new Sigar();
	
	//test code
/*	public static void main(String[] args){
		Sigar sigar = new Sigar();
		try {
			String[] netInterfaceList;
			netInterfaceList = sigar.getNetInterfaceList();
			System.out.println("network list length:" + netInterfaceList.length);
			for(int i = 0; i < netInterfaceList.length; ++i){
				System.out.println(netInterfaceList[i] + ": " + sigar.getNetInterfaceConfig(netInterfaceList[i]).getAddress());
			}
			NetworkInterfaceModelChild child = new NetworkInterfaceModelChild(netInterfaceList[3]);
			System.out.println("network name: " + netInterfaceList[3]);
			System.out.println("IP address: " + sigar.getNetInterfaceConfig(netInterfaceList[3]).getAddress());
			System.out.println("network description: " + sigar.getNetInterfaceConfig(netInterfaceList[3]).getDescription());
			System.out.println("receive rate: " + child.getKiloBytesReceivedPerSecond());
			System.out.println("send rate: " + child.getKiloBytesSentPerSecond());
			System.out.println("total rate: " + child.getKiloBytesTotalPerSecond());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		
	}*/
	
	public NetworkInterfaceModelChild(){
		
	}
	public NetworkInterfaceModelChild(String instance){
		this.instance = instance;
	}
	
	@XmlElement
	public String getAddress(){
		try {
			setAddress(sigar.getNetInterfaceConfig(instance).getAddress());
		} catch (SigarException e) {
			e.printStackTrace();
		}
		return this.address;
	}
	public void setAddress(String address){
		this.address = address;
	}
	
	@XmlElement
	public double getKiloBytesReceivedPerSecond() {
		long interval = 500;
		Timer timer = new Timer();
		timer.schedule(new CalculateBytesReceivedPerSecond(this, timer, interval), interval);
		try {
			Thread.sleep(interval + 50);
			return kiloBytesReceivedPerSecond;
		} catch (InterruptedException e) {
			e.printStackTrace();
			return kiloBytesReceivedPerSecond;
		}
	}
	public void setKiloBytesReceivedPerSecond(double kiloBytesReceivedPerSecond) {
		this.kiloBytesReceivedPerSecond = kiloBytesReceivedPerSecond;
	}
	
	@XmlElement
	public double getKiloBytesSentPerSecond() {
		long interval = 500;
		Timer timer = new Timer();
		timer.schedule(new CalculateBytesSentPerSecond(this, timer, interval), interval);
		try {
			Thread.sleep(interval + 50);
			return kiloBytesSentPerSecond;
		} catch (InterruptedException e) {
			e.printStackTrace();
			return kiloBytesSentPerSecond;
		}
	}
	public void setKiloBytesSentPerSecond(double kiloBytesSentPerSecond) {
		this.kiloBytesSentPerSecond = kiloBytesSentPerSecond;
	}
	
	@XmlElement
	public String getInstance() {
		return instance;
	}
	public void setInstance(String instance) {
		this.instance = instance;
	}
	
	@XmlElement
	public double getKiloBytesTotalPerSecond() {
		setKiloBytesTotalPerSecond(kiloBytesReceivedPerSecond + kiloBytesSentPerSecond);
		return kiloBytesTotalPerSecond;
	}
	public void setKiloBytesTotalPerSecond(double kiloBytesTotalPerSecond) {
		this.kiloBytesTotalPerSecond = kiloBytesTotalPerSecond;
	}	
}

class CalculateBytesSentPerSecond extends TimerTask{
	private Sigar sigar = new Sigar();
	private Timer timer;
	private long interval = 0;
	private long preBytesSentSoFar = 0;
	private NetworkInterfaceModelChild networkInterfaceModelChild;
	
	public CalculateBytesSentPerSecond(NetworkInterfaceModelChild networkInterfaceModelChild, Timer timer, long interval){
		this.timer = timer;
		this.interval = interval;
		this.networkInterfaceModelChild = networkInterfaceModelChild;
		
		try{
			NetInterfaceStat netInterfaceStat = sigar.getNetInterfaceStat(networkInterfaceModelChild.getInstance());
			preBytesSentSoFar = netInterfaceStat.getTxBytes();
		} catch (SigarException e){
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		try {
			NetInterfaceStat netInterfaceStat = sigar.getNetInterfaceStat(networkInterfaceModelChild.getInstance());
			long postBytesSentSoFar = netInterfaceStat.getTxBytes();
//			System.out.println("post bytes sent: " + postBytesSentSoFar);
//			System.out.println("pre bytes sent: " + preBytesSentSoFar);
			networkInterfaceModelChild.setKiloBytesSentPerSecond((double)(postBytesSentSoFar - preBytesSentSoFar)/interval);
		} catch (SigarException e) {
			e.printStackTrace();
		}
		timer.cancel();
	}
	
}

class CalculateBytesReceivedPerSecond extends TimerTask{
	private Sigar sigar = new Sigar();
	private Timer timer;
	private long interval = 0;
	private long preBytesReceivedSoFar = 0;
	private NetworkInterfaceModelChild networkInterfaceModelChild;
	
	public CalculateBytesReceivedPerSecond(NetworkInterfaceModelChild networkInterfaceModelChild, Timer timer, long interval){
		this.timer = timer;
		this.interval = interval;
		this.networkInterfaceModelChild = networkInterfaceModelChild;
		
		try{
			NetInterfaceStat netInterfaceStat = sigar.getNetInterfaceStat(networkInterfaceModelChild.getInstance());
			preBytesReceivedSoFar = netInterfaceStat.getRxBytes();
		} catch (SigarException e){
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		try {
			NetInterfaceStat netInterfaceStat = sigar.getNetInterfaceStat(networkInterfaceModelChild.getInstance());
			long postBytesReceivedSoFar = netInterfaceStat.getRxBytes();
			networkInterfaceModelChild.setKiloBytesReceivedPerSecond((double)(postBytesReceivedSoFar - preBytesReceivedSoFar)/interval);
		} catch (SigarException e) {
			e.printStackTrace();
		}
		timer.cancel();
	}
	
}