package org.bench4q.monitor.service;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class GetThreadPool {
	private static ExecutorService executorService = Executors
			.newFixedThreadPool(100);

	public static ExecutorService getExecutorService() {
		return executorService;
	}

	public static void shutDownExecutrorService() {
		executorService.shutdown();
	}
}
