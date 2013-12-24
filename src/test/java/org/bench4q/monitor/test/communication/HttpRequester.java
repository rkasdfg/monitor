package org.bench4q.monitor.test.communication;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.Charset;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import org.springframework.stereotype.Component;

@Component
public class HttpRequester {
	private String defaultContentEncoding;

	public HttpRequester()
	{
		this.setDefaultContentEncoding(Charset.defaultCharset().name());
	}
	
	public String getDefaultContentEncoding() {
		return defaultContentEncoding;
	}

	public void setDefaultContentEncoding(String defaultContentEncoding) {
		this.defaultContentEncoding = defaultContentEncoding;
	}
	
	public HttpResponse sendPost(String urlString, Map<String, String> params)
			throws IOException {
		return this.send(urlString, "POST", params, "", null);
	}
	
	public HttpResponse sendPostXml(String urlString, String contentString) throws IOException
	{
		HashMap<String, String> hashMap = new HashMap<String, String>();
		hashMap.put("Content-Type", "application/xml");
		return this.send(urlString, "POST", null, contentString, hashMap);
	}
	
	public HttpResponse sendGet(String urlString, Map<String, String> params,
			Map<String, String> properties) throws IOException {
		return this.send(urlString, "GET", params, "", properties);
	}

	private HttpResponse send(String urlString, String method,
			Map<String, String> parameters, String Content, Map<String, String> propertys)
			throws IOException {
		HttpURLConnection urlConnection = null;

		if (method.equalsIgnoreCase("GET") && parameters != null) {
			StringBuffer param = new StringBuffer();
			int i = 0;
			for (String key : parameters.keySet()) {
				if (i == 0)
					param.append("?");
				else
					param.append("&");
				param.append(key).append("=").append(parameters.get(key));
				i++;
			}
			urlString += param;
		}

		if (!urlString.startsWith("http://")) {
			urlString = "http://" + urlString;
		}
		//urlString = URLEncoder.encode(urlString, "UTF-8");
		URL url = new URL(urlString);
		urlConnection = (HttpURLConnection) url.openConnection();

		urlConnection.setRequestMethod(method);
		urlConnection.setDoOutput(true);
		urlConnection.setDoInput(true);
		urlConnection.setUseCaches(false);

		if (propertys != null)
			for (String key : propertys.keySet()) {
				urlConnection.addRequestProperty(key, propertys.get(key));
			}

		if (method.equalsIgnoreCase("POST") && parameters != null) {
			StringBuffer param = new StringBuffer();
			for (String key : parameters.keySet()) {
				param.append("&");
				param.append(key).append("=").append(parameters.get(key));
			}
			urlConnection.getOutputStream().write(param.toString().getBytes());
			urlConnection.getOutputStream().flush();
			urlConnection.getOutputStream().close();
		}
		else if (method.equalsIgnoreCase("POST") && !Content.isEmpty()) {
			urlConnection.getOutputStream().write(Content.getBytes());
			urlConnection.getOutputStream().flush();
			urlConnection.getOutputStream().close();
		}

		return this.makeContent(urlString, urlConnection);
	}

	private HttpResponse makeContent(String urlString,
			HttpURLConnection urlConnection) {
		// TODO Auto-generated method stub
		HttpResponse httpResponser = new HttpResponse();
		try {
			InputStream in = urlConnection.getInputStream();
			BufferedReader bufferedReader = new BufferedReader(
					new InputStreamReader(in));
			httpResponser.contentCollection = new Vector<String>();
			StringBuffer temp = new StringBuffer();
			String line = bufferedReader.readLine();
			while (line != null) {
				httpResponser.contentCollection.add(line);
				temp.append(line).append("\r\n");
				line = bufferedReader.readLine();
			}
			bufferedReader.close();

			String ecod = urlConnection.getContentEncoding();
			if (ecod == null)
				ecod = this.defaultContentEncoding;

			httpResponser.setUrlString(urlString);
			httpResponser.setDefaultPort(urlConnection.getURL()
					.getDefaultPort());
			httpResponser.setPort(urlConnection.getURL().getPort());
			httpResponser.setProtocol(urlConnection.getURL().getProtocol());

			httpResponser.setContent(new String(temp.toString().getBytes(),
					ecod));
			httpResponser.setContentEncoding(ecod);
			httpResponser.setCode(urlConnection.getResponseCode());
			httpResponser.setMessage(urlConnection.getResponseMessage());
			httpResponser.setContentType(urlConnection.getContentType());
			httpResponser.setConnectTimeout(urlConnection.getConnectTimeout());
			httpResponser.setReadTimeout(urlConnection.getReadTimeout());

			return httpResponser;
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (urlConnection != null)
				urlConnection.disconnect();
		}
		return null;
	}

	public class HttpResponse {

		String urlString;

		int defaultPort;

		int port;

		String protocol;

		String contentEncoding;

		String content;

		String contentType;

		int code;

		String message;

		int connectTimeout;

		int readTimeout;

		Vector<String> contentCollection;

		public String getUrlString() {
			return urlString;
		}

		public void setUrlString(String urlString) {
			this.urlString = urlString;
		}

		public int getDefaultPort() {
			return defaultPort;
		}

		public void setDefaultPort(int defaultPort) {
			this.defaultPort = defaultPort;
		}

		public int getPort() {
			return port;
		}

		public void setPort(int port) {
			this.port = port;
		}

		public String getProtocol() {
			return protocol;
		}

		public void setProtocol(String protocol) {
			this.protocol = protocol;
		}

		public String getContentEncoding() {
			return contentEncoding;
		}

		public void setContentEncoding(String contentEncoding) {
			this.contentEncoding = contentEncoding;
		}

		public String getContent() {
			return content;
		}

		public void setContent(String content) {
			this.content = content;
		}

		public String getContentType() {
			return contentType;
		}

		public void setContentType(String contentType) {
			this.contentType = contentType;
		}

		public int getCode() {
			return code;
		}

		public void setCode(int code) {
			this.code = code;
		}

		public String getMessage() {
			return message;
		}

		public void setMessage(String message) {
			this.message = message;
		}

		public int getConnectTimeout() {
			return connectTimeout;
		}

		public void setConnectTimeout(int connectTimeout) {
			this.connectTimeout = connectTimeout;
		}

		public int getReadTimeout() {
			return readTimeout;
		}

		public void setReadTimeout(int readTimeout) {
			this.readTimeout = readTimeout;
		}

		public Vector<String> getContentCollection() {
			return contentCollection;
		}

		public void setContentCollection(Vector<String> contentCollection) {
			this.contentCollection = contentCollection;
		}

	}
}
