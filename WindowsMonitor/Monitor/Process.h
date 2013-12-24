#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API Process
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetProcessorTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetUserTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetVirtualBytesPeak(const wchar_t * instanceName);
	static double GetVirtualBytes(const wchar_t * instanceName);
	static double GetPageFaultsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetWorkingSetPeak(const wchar_t * instanceName);
	static double GetWorkingSet(const wchar_t * instanceName);
	static double GetPageFileBytesPeak(const wchar_t * instanceName);
	static double GetPageFileBytes(const wchar_t * instanceName);
	static double GetPrivateBytes(const wchar_t * instanceName);
	static double GetThreadCount(const wchar_t * instanceName);
	static double GetPriorityBase(const wchar_t * instanceName);
	static double GetElapsedTime(const wchar_t * instanceName);
	static double GetProcessId(const wchar_t * instanceName);
	static double GetCreatingProcessId(const wchar_t * instanceName);
	static double GetPoolPagedBytes(const wchar_t * instanceName);
	static double GetPoolNonpagedBytes(const wchar_t * instanceName);
	static double GetHandleCount(const wchar_t * instanceName);
	static double GetIOReadOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOWriteOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIODataOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOOtherOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOReadBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOWriteBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIODataBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOOtherBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPrivateWorkingSet(const wchar_t * instanceName);
};