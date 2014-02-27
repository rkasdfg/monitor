package org.bench4q.monitor.api;

import java.util.ArrayList;
import java.util.List;

import org.bench4q.monitor.model.ProcessorModel;
import org.bench4q.monitor.model.ProcessorModelChild;
import org.hyperic.sigar.SigarException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/monitor")
public class ProcessorController {

	@RequestMapping("/processor")
	@ResponseBody
	ProcessorModel getResposeModel() throws SigarException {
		ProcessorModel retModel = new ProcessorModel();
		return retModel;
	}

	@RequestMapping("/processorList")
	@ResponseBody
	List<String> getProcessorList() throws SigarException {
		List<String> processorList = new ArrayList<String>();
		ProcessorModel processorModel = new ProcessorModel();
		if (processorModel.getProcessorModelList() != null) {
			for (ProcessorModelChild processorModelChild : processorModel
					.getProcessorModelList()) {
				processorList.add(processorModelChild.getInstance());
			}
		}
		return processorList;
	}

	@RequestMapping("/processor/{instanceName}")
	@ResponseBody
	ProcessorModelChild getProcessorModelChild(
			@PathVariable("instanceName") String instanceName) throws SigarException {
		ProcessorModel processorModel = new ProcessorModel();
		if (processorModel.getProcessorModelList() == null)
			throw new IllegalArgumentException(instanceName
					+ " not exsist,cpu instance is empty");
		for (ProcessorModelChild processorModelChild : processorModel
				.getProcessorModelList()) {
			if (processorModelChild.getInstance().equals(instanceName))
				return processorModelChild;
		}
		throw new IllegalArgumentException(instanceName + " not exsist");
	}
}
