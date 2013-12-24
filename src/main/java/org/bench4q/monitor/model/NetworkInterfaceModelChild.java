package org.bench4q.monitor.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class NetworkInterfaceModelChild {
private double bytesTotalPerSecond;
private double  bytesReceivedPerSecond;
private double bytesSentPerSecond;
private String instance;
public double getBytesReceivedPerSecond() {
	return bytesReceivedPerSecond;
}

public void setBytesReceivedPerSecond(double bytesReceivedPerSecond) {
	this.bytesReceivedPerSecond = bytesReceivedPerSecond;
}

public double getBytesSentPerSecond() {
	return bytesSentPerSecond;
}

public void setBytesSentPerSecond(double bytesSentPerSecond) {
	this.bytesSentPerSecond = bytesSentPerSecond;
}


public String getInstance() {
	return instance;
}

public void setInstance(String instance) {
	this.instance = instance;
}

public double getBytesTotalPerSecond() {
	return bytesTotalPerSecond;
}

public void setBytesTotalPerSecond(double bytesTotalPerSecond) {
	this.bytesTotalPerSecond = bytesTotalPerSecond;
}
		
}
