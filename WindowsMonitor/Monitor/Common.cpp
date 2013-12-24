#include "stdafx.h"
#include "Common.h"

string Common::WideStringToString(const wstring & str)
{
	int length = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	if (length<= 0)
	{
		return string("");
	}
	char* dest = new char[length];
	if (NULL == dest)
	{
		return string("");
	}
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, dest, length, NULL, NULL);
	dest[length -1] = 0;
	string ret(dest);
	delete [] dest;
	return ret;
}

wstring Common::StringToWideString(const string & str)
{
	int count=(int)str.size();
	int length = MultiByteToWideChar(CP_ACP, 0, str.c_str(), count, 0, 0);
	if(length <= 0)
	{
		return NULL;
	}
	wchar_t * dest = new wchar_t[length+1];
	if( NULL == dest)
	{
		return wstring(L"");
	}
	MultiByteToWideChar(CP_ACP, 0,str.c_str(), count, dest, length);
	dest[length] = 0;
	if( dest[0] == 0xFEFF)
	{
		int i=0;
		for(i = 0; i < length; i ++)
		{
			dest[i] = dest[i+1];
		}
	}
	wstring ret(dest);
	delete [] dest;
	return ret;
}

double Common::GetCounterValue(const wchar_t * fullCounterPath)
{
	HQUERY hquery;
	PDH_STATUS status;
	status=PdhOpenQuery(NULL,NULL,&hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	HCOUNTER counter=NULL;
	status=PdhAddCounter(hquery, fullCounterPath, NULL, &counter);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	status=PdhCollectQueryData(hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	PDH_FMT_COUNTERVALUE counterValue;
	status=PdhGetFormattedCounterValue(counter,PDH_FMT_DOUBLE|PDH_FMT_NOSCALE|PDH_FMT_NOCAP100,NULL,&counterValue);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	status=PdhCloseQuery(hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	return counterValue.doubleValue;
}

double Common::GetCounterValueWithIdle(const wchar_t * fullCounterPath,int idleTime)
{
	HQUERY hquery;
	PDH_STATUS status;
	status=PdhOpenQuery(NULL,NULL,&hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	HCOUNTER counter=NULL;
	status=PdhAddCounter(hquery, fullCounterPath, NULL, &counter);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	status=PdhCollectQueryData(hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}

	Sleep(idleTime);

	status=PdhCollectQueryData(hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	PDH_FMT_COUNTERVALUE counterValue;
	status=PdhGetFormattedCounterValue(counter,PDH_FMT_DOUBLE|PDH_FMT_NOSCALE|PDH_FMT_NOCAP100,NULL,&counterValue);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	status=PdhCloseQuery(hquery);
	if(status!=ERROR_SUCCESS)
	{
		return -1;
	}
	return counterValue.doubleValue;
}

list<wstring> Common::GetInstanceName(const wchar_t * objectName)
{
	list<wstring> ret;
	vector<wstring> tmp;
	wchar_t * counterListBuffer = NULL;
	wchar_t * instanceListBuffer = NULL;
	DWORD dwCounterListSize = 0;

	DWORD dwInstanceListSize = 0;  
	BOOL pass =FALSE;
	PDH_STATUS status = PdhEnumObjectItems(NULL,NULL,objectName,counterListBuffer,&dwCounterListSize,instanceListBuffer,&dwInstanceListSize,PERF_DETAIL_WIZARD, 0); 

	if(status == PDH_MORE_DATA)
	{
		counterListBuffer=(wchar_t *)malloc((dwCounterListSize*sizeof(wchar_t)));
		instanceListBuffer=(wchar_t *)malloc((dwInstanceListSize*sizeof(wchar_t)));
		status= PdhEnumObjectItems(NULL,NULL,objectName,counterListBuffer,&dwCounterListSize,instanceListBuffer,&dwInstanceListSize,PERF_DETAIL_WIZARD,0); 
		if(status == ERROR_SUCCESS) 
		{
			wchar_t * instance = instanceListBuffer;
			for(; *instance != 0; instance += lstrlen(instance) + 1) 
			{
				tmp.push_back(wstring(instance));
			}
			sort(tmp.begin(),tmp.end());
			int count=0;
			wstring last;
			vector<wstring>::iterator iter;
			for(iter=tmp.begin();iter!=tmp.end();iter++)
			{
				if(iter==tmp.begin())
				{
					last=wstring((*iter).c_str());
					ret.push_back(wstring((*iter).c_str()));
					count=0;
				}
				else
				{
					if(last==wstring((*iter).c_str()))
					{
						count++;
						wchar_t buffer[10];
						_itow_s(count,buffer,10);
						wstring toInsert((*iter).c_str());
						toInsert+=L"#";
						toInsert+=buffer;
						ret.push_back(toInsert);
					}
					else
					{
						last=wstring((*iter).c_str());
						ret.push_back(wstring((*iter).c_str()));
						count=0;
					}
				}
			}
		}
	}
	if(counterListBuffer != NULL) 
	{
		free(counterListBuffer);
	}
	if(instanceListBuffer != NULL) 
	{
		free(instanceListBuffer);
	}
	return ret;
}

list<wstring> Common::GetCounterList(const wchar_t * objectName)
{
	list<wstring> ret;
	wchar_t * counterListBuffer = NULL;
	wchar_t * instanceListBuffer = NULL;
	DWORD dwCounterListSize = 0;

	DWORD dwInstanceListSize = 0;  
	BOOL pass =FALSE;
	PDH_STATUS status = PdhEnumObjectItems(NULL,NULL,objectName,counterListBuffer,&dwCounterListSize,instanceListBuffer,&dwInstanceListSize,PERF_DETAIL_WIZARD, 0); 

	if(status == PDH_MORE_DATA)
	{
		counterListBuffer=(wchar_t *)malloc((dwCounterListSize*sizeof(wchar_t)));
		instanceListBuffer=(wchar_t *)malloc((dwInstanceListSize*sizeof(wchar_t)));
		status= PdhEnumObjectItems(NULL,NULL,objectName,counterListBuffer,&dwCounterListSize,instanceListBuffer,&dwInstanceListSize,PERF_DETAIL_WIZARD,0); 
		if(status == ERROR_SUCCESS) 
		{
			wchar_t * counterList = counterListBuffer;
			for(; *counterList != 0; counterList += lstrlen(counterList) + 1) 
			{
				ret.push_back(wstring(counterList));
			}
		}
	}
	if(counterListBuffer != NULL) 
	{
		free(counterListBuffer);
	}
	if(instanceListBuffer != NULL) 
	{
		free(instanceListBuffer);
	}
	return ret;
}