package org.bench4q.monitor.service;

import org.hyperic.sigar.Sigar;

public class GetSigar{

	private static Sigar sigar = new Sigar();

	public static Sigar getSigar() {
		return sigar;
	}
}
