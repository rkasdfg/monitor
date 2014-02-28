package org.bench4q.monitor.model;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import org.apache.log4j.Logger;
import org.bench4q.monitor.service.DataFomat;
import org.bench4q.monitor.service.GetSigar;
import org.hyperic.sigar.SigarException;

@XmlRootElement(name = "NetworkInterface")
public class NetworkInterfaceModel {
	private Double kiloBytesTotalPerSecond;
	private Double kiloBytesReceivedPerSecond;
	private Double kiloBytesSentPerSecond;
	private long interval = 1000;
	private Logger logger = Logger.getLogger(NetworkInterfaceModel.class);

	public static void main(String[] args) {
		while (true) {
			long Time = System.currentTimeMillis();
			NetworkInterfaceModel test = new NetworkInterfaceModel();

			test.logger.info("ll");
			System.out.println("KiloBytesReceivedPerSecond:"
					+ test.getKiloBytesReceivedPerSecond() + "kb/s");
			System.out.println("KiloBytesSentPerSecond:"
					+ test.getKiloBytesSentPerSecond() + "kb/s");
			System.out.println("KiloBytesTotalPerSecond:"
					+ test.getKiloBytesTotalPerSecond() + "kb/s");
			System.out.println(System.currentTimeMillis() - Time);
		}
	}

	@SuppressWarnings("unchecked")
	public NetworkInterfaceModel() {
		logger.error("hello");
		// this can be used for all
		ExecutorService executorService = Executors.newFixedThreadPool(2);

		Future<Double> futureBytesReceivedPerSecond = executorService
				.submit(new CalculateBytesReceivedPerSecond(interval));

		Future<Double> futureBytesSentPerSecond = executorService
				.submit(new CalculateBytesSentPerSecond(interval));
		try {
			System.out.println(futureBytesReceivedPerSecond.get());

			this.setKiloBytesReceivedPerSecond(futureBytesReceivedPerSecond
					.get());
			this.setKiloBytesSentPerSecond(futureBytesSentPerSecond.get());
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (ExecutionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			executorService.shutdown();
		}
	}

	@XmlElement
	public Double getKiloBytesReceivedPerSecond() {
		return this.kiloBytesReceivedPerSecond;
	}

	public void setKiloBytesReceivedPerSecond(Double kiloBytesReceivedPerSecond) {
		this.kiloBytesReceivedPerSecond = kiloBytesReceivedPerSecond;
	}

	@XmlElement
	public Double getKiloBytesSentPerSecond() {
		return this.kiloBytesSentPerSecond;
	}

	public void setKiloBytesSentPerSecond(Double kiloBytesSentPerSecond) {
		this.kiloBytesSentPerSecond = kiloBytesSentPerSecond;
	}

	@XmlElement
	public Double getKiloBytesTotalPerSecond() {
		setKiloBytesTotalPerSecond(this.kiloBytesReceivedPerSecond
				+ this.kiloBytesSentPerSecond);
		return kiloBytesTotalPerSecond;
	}

	public void setKiloBytesTotalPerSecond(Double kiloBytesTotalPerSecond) {
		this.kiloBytesTotalPerSecond = kiloBytesTotalPerSecond;
	}
}

@SuppressWarnings("rawtypes")
abstract class CalculateBytesPerSecond implements Callable {
	private long interval;
	private Logger logger = Logger
			.getLogger(CalculateBytesReceivedPerSecond.class);
	private Double kiloBytesPerSecond;

	public CalculateBytesPerSecond(long interval) {
		this.interval = interval;
	}

	public double getKiloBytesPerSecond() {
		return kiloBytesPerSecond;
	}

	public Double call() {
		try {
			long startTime = System.nanoTime();
			long endTime;
			long preBytesSentSoFar = this.getBytesSoFar();
			long postBytesSentSoFar = 0;
			Thread.sleep(interval);
			endTime = System.nanoTime();
			postBytesSentSoFar = this.getBytesSoFar();
			this.kiloBytesPerSecond = (double) ((postBytesSentSoFar - preBytesSentSoFar)
					/ DataFomat.caculateTimeInterval(startTime, endTime) / 1024L);
			return this.kiloBytesPerSecond;
		} catch (SigarException e) {
			logger.error(e, e.fillInStackTrace());
			return new Double(0);
		} catch (InterruptedException e) {
			// TODO: handle exception
			logger.error(e, e.fillInStackTrace());
			return new Double(0);
		}

	}

	abstract long getBytesSoFar() throws SigarException;

}

class CalculateBytesSentPerSecond extends CalculateBytesPerSecond {
	public CalculateBytesSentPerSecond(long interval) {
		super(interval);
	}

	public double getKiloBytesSentPerSecond() {
		return this.getKiloBytesPerSecond();
	}

	long getBytesSoFar() throws SigarException {
		long bytesPostSoFar = 0;
		String[] netInterfaceList = GetSigar.getSigar().getNetInterfaceList();
		for (int i = 0; i < netInterfaceList.length; ++i)
			bytesPostSoFar += GetSigar.getSigar()
					.getNetInterfaceStat(netInterfaceList[i]).getTxBytes();
		return bytesPostSoFar;
	}
}

class CalculateBytesReceivedPerSecond extends CalculateBytesPerSecond {

	public CalculateBytesReceivedPerSecond(long interval) {
		super(interval);
	}

	public double getKiloBytesReceivedPerSecond() {
		return this.getKiloBytesPerSecond();
	}

	long getBytesSoFar() throws SigarException {
		long bytesReceivedSoFar = 0;
		String[] netInterfaceList = GetSigar.getSigar().getNetInterfaceList();
		for (int i = 0; i < netInterfaceList.length; ++i)
			bytesReceivedSoFar += GetSigar.getSigar()
					.getNetInterfaceStat(netInterfaceList[i]).getRxBytes();
		return bytesReceivedSoFar;

	}
}
