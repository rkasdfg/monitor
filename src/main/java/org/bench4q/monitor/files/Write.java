package org.bench4q.monitor.files;

import java.io.PrintWriter;

public abstract class  Write implements Runnable{
	 public PrintWriter out;
	 public int idleTime;
	 public void setOut(PrintWriter out){
		 this.out=out;
	 }
}
