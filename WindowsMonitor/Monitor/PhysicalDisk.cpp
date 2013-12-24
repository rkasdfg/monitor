#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "PhysicalDisk.h"

list<wstring> PhysicalDisk::GetInstances()
{
	return Common::GetInstanceName(L"PhysicalDisk");
}

list<wstring> PhysicalDisk::GetCounterList()
{
	return Common::GetCounterList(L"PhysicalDisk");
}

// Current Disk Queue Length
double PhysicalDisk::GetCurrentDiskQueueLength(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Current Disk Queue Length";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Disk Time
double PhysicalDisk::GetDiskTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Queue Length
double PhysicalDisk::GetAverageDiskQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Disk Read Time
double PhysicalDisk::GetDiskReadTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Read Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Read Queue Length
double PhysicalDisk::GetAverageDiskReadQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Read Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Disk Write Time
double PhysicalDisk::GetDiskWriteTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Write Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Write Queue Length
double PhysicalDisk::GetAverageDiskWriteQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Write Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Transfer
double PhysicalDisk::GetAverageDiskTransferTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Transfer";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Read
double PhysicalDisk::GetAverageDiskReadTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Read";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Write
double PhysicalDisk::GetAverageDiskWriteTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Write";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Transfers/sec
double PhysicalDisk::GetDiskTransfersPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Transfers/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Reads/sec
double PhysicalDisk::GetDiskReadsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Reads/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Writes/sec
double PhysicalDisk::GetDiskWritesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Writes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Bytes/sec
double PhysicalDisk::GetDiskBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Read Bytes/sec
double PhysicalDisk::GetDiskReadBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Read Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Write Bytes/sec
double PhysicalDisk::GetDiskWriteBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Write Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Transfer
double PhysicalDisk::GetAverageDiskBytesPerTransfer(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Transfer";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Read
double PhysicalDisk::GetAverageDiskBytesPerRead(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Read";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Write
double PhysicalDisk::GetAverageDiskBytesPerWrite(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Write";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Idle Time
double PhysicalDisk::GetIdleTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Idle Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Split IO/Sec
double PhysicalDisk::GetSplitIOPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\PhysicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Split IO/Sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}