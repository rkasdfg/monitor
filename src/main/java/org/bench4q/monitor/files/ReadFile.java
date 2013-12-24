package org.bench4q.monitor.files;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;

import org.springframework.stereotype.Component;
import org.springframework.util.FileCopyUtils;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Component
@RequestMapping("/Mon")
public class ReadFile {
	private String fileNameFile = "E:/wxr.xml";

	@RequestMapping("/File")
	@ResponseBody
	public void getFile(OutputStream os) throws IOException {
		FileInputStream fileInputStream = new FileInputStream(new File(
				fileNameFile));
		// File file = new File(fileNameFile);
		// Resource resource=new ClassPathResource(fileNameFile);//;
		FileCopyUtils.copy(fileInputStream, os);//

	}
}
