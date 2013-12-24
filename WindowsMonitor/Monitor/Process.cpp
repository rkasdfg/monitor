#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "Process.h"

list<wstring> Process::GetInstances()
{
	return Common::GetInstanceName(L"Process");
}

list<wstring> Process::GetCounterList()
{
	return Common::GetCounterList(L"Process");
}

// % Processor Time
double Process::GetProcessorTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Processor Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % User Time
double Process::GetUserTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% User Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Privileged Time
double Process::GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Privileged Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Virtual Bytes Peak
double Process::GetVirtualBytesPeak(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Virtual Bytes Peak";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Virtual Bytes
double Process::GetVirtualBytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Virtual Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Page Faults/sec
double Process::GetPageFaultsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Page Faults/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Working Set Peak
double Process::GetWorkingSetPeak(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Working Set Peak";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Working Set
double Process::GetWorkingSet(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Working Set";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Page File Bytes Peak
double Process::GetPageFileBytesPeak(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Page File Bytes Peak";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Page File Bytes
double Process::GetPageFileBytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Page File Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Private Bytes
double Process::GetPrivateBytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Private Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Thread Count
double Process::GetThreadCount(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Thread Count";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Priority Base
double Process::GetPriorityBase(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Priority Base";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Elapsed Time
double Process::GetElapsedTime(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Elapsed Time";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// ID Process
double Process::GetProcessId(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\ID Process";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Creating Process ID
double Process::GetCreatingProcessId(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Creating Process ID";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Pool Paged Bytes
double Process::GetPoolPagedBytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Pool Paged Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Pool Nonpaged Bytes
double Process::GetPoolNonpagedBytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Pool Nonpaged Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Handle Count
double Process::GetHandleCount(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Handle Count";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// IO Read Operations/sec
double Process::GetIOReadOperationsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Read Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Write Operations/sec
double Process::GetIOWriteOperationsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Write Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Data Operations/sec
double Process::GetIODataOperationsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Data Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Other Operations/sec
double Process::GetIOOtherOperationsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Other Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Read Bytes/sec
double Process::GetIOReadBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Read Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Write Bytes/sec
double Process::GetIOWriteBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Write Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Data Bytes/sec
double Process::GetIODataBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Data Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// IO Other Bytes/sec
double Process::GetIOOtherBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\IO Other Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Working Set - Private
double Process::GetPrivateWorkingSet(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Process(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Working Set - Private";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}
