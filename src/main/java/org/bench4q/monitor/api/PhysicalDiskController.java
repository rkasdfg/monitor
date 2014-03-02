package org.bench4q.monitor.api;

import java.util.concurrent.ExecutionException;

import org.bench4q.monitor.model.FileSystemModel;
import org.bench4q.monitor.model.PhysicalDiskModel;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/monitor")
public class PhysicalDiskController {
	@RequestMapping("pshysicalDisk")
	@ResponseBody
	PhysicalDiskModel getPhysicalDiskModel() throws SigarException,
			InterruptedException, ExecutionException {
		PhysicalDiskModel retModel = new PhysicalDiskModel();
		return retModel;
	}

	@RequestMapping("/pshysicalDisk/{dir}")
	@ResponseBody
	public FileSystemModel getFileSystemModel(@PathVariable("dir") String dir)
			throws SigarException, InterruptedException, ExecutionException {
		PhysicalDiskModel physicalDiskModel = new PhysicalDiskModel();
		if (physicalDiskModel.getFieFileSystemModels() != null) {
			for (FileSystemModel fileSystemModel : physicalDiskModel
					.getFieFileSystemModels()) {
				if (fileSystemModel.getFileDir().equals(dir))
					return fileSystemModel;
			}
		}
		throw new IllegalArgumentException("dir:" + dir + " not exit!");
	}
}
