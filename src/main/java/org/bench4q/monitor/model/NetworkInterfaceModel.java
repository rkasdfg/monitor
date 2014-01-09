package org.bench4q.monitor.model;


import java.util.Timer;
import java.util.TimerTask;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import org.hyperic.sigar.Sigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "NetworkInterface")
public class NetworkInterfaceModel {
	private double kiloBytesTotalPerSecond;
	private double kiloBytesReceivedPerSecond;
	private double kiloBytesSentPerSecond;
	
	public static void main(String[] args){
		NetworkInterfaceModel test = new NetworkInterfaceModel();
		System.out.println(test.getKiloBytesReceivedPerSecond());
		System.out.println(test.getKiloBytesSentPerSecond());
		System.out.println(test.getKiloBytesTotalPerSecond());
	}
	
	public NetworkInterfaceModel(){
		
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
	private NetworkInterfaceModel networkInterfaceModel;
	
	public CalculateBytesSentPerSecond(NetworkInterfaceModel networkInterfaceModel, Timer timer, long interval){
		this.timer = timer;
		this.interval = interval;
		this.networkInterfaceModel = networkInterfaceModel;
		
		try{
			String[] netInterfaceList = sigar.getNetInterfaceList();
			for(int i = 0; i < netInterfaceList.length; ++i)
				preBytesSentSoFar += sigar.getNetInterfaceStat(netInterfaceList[i]).getTxBytes();
		} catch (SigarException e){
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		try {
			long postBytesSentSoFar = 0;
			String[] netInterfaceList = sigar.getNetInterfaceList();
			for(int i = 0; i < netInterfaceList.length; ++i)
				postBytesSentSoFar += sigar.getNetInterfaceStat(netInterfaceList[i]).getTxBytes();
//			System.out.println("post bytes sent: " + postBytesSentSoFar);
//			System.out.println("pre bytes sent: " + preBytesSentSoFar);
			networkInterfaceModel.setKiloBytesSentPerSecond((double)(postBytesSentSoFar - preBytesSentSoFar)/interval);
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
	private NetworkInterfaceModel networkInterfaceModel;
	
	public CalculateBytesReceivedPerSecond(NetworkInterfaceModel networkInterfaceModel, Timer timer, long interval){
		this.timer = timer;
		this.interval = interval;
		this.networkInterfaceModel = networkInterfaceModel;
		
		try{
			String[] netInterfaceList = sigar.getNetInterfaceList();
			for(int i = 0; i < netInterfaceList.length; ++i)
				preBytesReceivedSoFar += sigar.getNetInterfaceStat(netInterfaceList[i]).getRxBytes();
		} catch (SigarException e){
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		try {
			long postBytesReceivedSoFar = 0;
			String[] netInterfaceList = sigar.getNetInterfaceList();
			for(int i = 0; i < netInterfaceList.length; ++i)
				postBytesReceivedSoFar += sigar.getNetInterfaceStat(netInterfaceList[i]).getRxBytes();
			networkInterfaceModel.setKiloBytesReceivedPerSecond((double)(postBytesReceivedSoFar - preBytesReceivedSoFar)/interval);
		} catch (SigarException e) {
			e.printStackTrace();
		}
		timer.cancel();
	}
}
