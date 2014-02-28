package org.bench4q.monitor.service;

public class DataFomat {
	public static double fomatToPercent(double data) {
		long temp = Math.round(data * 10000);
		return temp / 100.0;
	}
	public static double caculateTimeInterval(long startTime, long endTime) {
		double temp=(endTime - startTime);
		return  temp/1000000000L;
	}
}
