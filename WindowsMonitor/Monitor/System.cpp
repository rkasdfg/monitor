#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "System.h"

list<wstring> System::GetCounterList()
{
	return Common::GetCounterList(L"System");
}

// File Read Operations/sec
double System::GetFileReadOperationsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Read Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Write Operations/sec
double System::GetFileWriteOperationsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Write Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Control Operations/sec
double System::GetFileControlOperationsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Control Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Read Bytes/sec
double System::GetFileReadBytesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Read Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Write Bytes/sec
double System::GetFileWriteBytesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Write Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Control Bytes/sec
double System::GetFileControlBytesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Control Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Context Switches/sec
double System::GetContextSwitchesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Context Switches/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// System Calls/sec
double System::GetSystemCallsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\System Calls/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// File Data Operations/sec
double System::GetFileDataOperationsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\File Data Operations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// System Up Time
double System::GetSystemUpTime()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\System Up Time";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
	}


// Processor Queue Length
double System::GetProcessorQueueLength()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Processor Queue Length";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Processes
double System::GetProcessesCount()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Processes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Threads
double System::GetThreadsCount()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Threads";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Alignment Fixups/sec
double System::GetAlignmentFixupsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Alignment Fixups/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Exception Dispatches/sec
double System::GetExceptionDispatchesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Exception Dispatches/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Floating Emulations/sec
double System::GetFloatingEmulationsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\Floating Emulations/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Registry Quota In Use
double System::GetRegistryQuotaInUsePercent()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\System\\% Registry Quota In Use";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}
