package org.bench4q.monitor.entiry;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;

public class LinuxFileRead {
	private BufferedReader bufferedReader;

	public BufferedReader getBufferedReader() {
		return bufferedReader;
	}
	public void setBufferedReader(BufferedReader bufferedReader) {
		this.bufferedReader = bufferedReader;
	
	}
	public LinuxFileRead(String fileName) throws FileNotFoundException{
	   File file = new File(fileName);
    this.bufferedReader= new BufferedReader(new InputStreamReader(new FileInputStream(file)));
	}
}
