package org.bench4q.monitor;

import org.bench4q.monitor.service.WriteSystemInfoToLocalDisk;
import org.eclipse.jetty.server.Connector;
import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.server.bio.SocketConnector;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.springframework.web.servlet.DispatcherServlet;

public class MonitorServer {
	private Server server;
	private int port;

	private Server getServer() {
		return server;
	}

	private void setServer(Server server) {
		this.server = server;
	}

	private int getPort() {
		return port;
	}

	private void setPort(int port) {
		this.port = port;
	}

	public MonitorServer(int port) {
		this.setPort(port);
	}

	public boolean start() {
		try {
			
			System.out.println(this.getPort());
			this.setServer(new Server());
			Connector connector = new SocketConnector();
			connector.setPort(this.getPort());
			this.getServer().addConnector(connector);
			
			ServletContextHandler servletContextHandler = new ServletContextHandler();
			ServletHolder servletHolder = servletContextHandler.addServlet(
					DispatcherServlet.class, "/");
			servletHolder
					.setInitParameter("contextConfigLocation",
							"classpath*:org/bench4q/monitor/config/application-context.xml");
			this.getServer().setHandler(servletContextHandler);
			this.getServer().start();
			WriteSystemInfoToLocalDisk testWrite = new WriteSystemInfoToLocalDisk();
			testWrite.setSavaPath("D:\\sigartmp\\");		
			testWrite.writeCurrentSystemInfoToLocalDisk();
			return true;
		} catch (Exception e) {
			e.printStackTrace();
			return false;
		}
	}

	public boolean stop() {
		try {
			if (this.getServer() != null) {
				this.getServer().stop();
			}
			return true;
		} catch (Exception e) {
			e.printStackTrace();
			return false;
		} finally {
			this.setServer(null);
		}
	}
	public static void main(String[] args) {

		MonitorServer monitorServer = new MonitorServer(5556);
		monitorServer.start();
	}
}
