package org.bench4q.monitor.files;

import java.util.UUID;

public class CreatFileName {

	public CreatFileName(String part, String time) {
		this.part = part;
		this.time = time;
	}

	private String part;
	private String time;

	public String getFileName() {
		String fileName;
		UUID uuid = UUID.randomUUID();
		fileName = uuid.toString() + "_" + part + "_" + time + ".xml";
		return fileName;
	}
}
