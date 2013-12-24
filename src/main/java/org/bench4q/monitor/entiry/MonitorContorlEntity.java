package org.bench4q.monitor.entiry;


public class MonitorContorlEntity {
		private String osNameString;
		private int idleTime;
		public MonitorContorlEntity(){
			this.osNameString=System.getProperty("os.name").toLowerCase();
			this.idleTime=3000;
		}
		public String getOsNameString() {
			return osNameString;
		}
		public void setOsNameString(String osNameString) {
			this.osNameString = osNameString;
		}
		public int getIdleTime() {
			return idleTime;
		}
		public void setIdleTime(int idleTime) {
			this.idleTime = idleTime;
		}
	}


