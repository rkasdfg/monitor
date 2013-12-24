#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "LogicalDisk.h"

list<wstring> LogicalDisk::GetInstances()
{
	return Common::GetInstanceName(L"LogicalDisk");
}

list<wstring> LogicalDisk::GetCounterList()
{
	return Common::GetCounterList(L"LogicalDisk");
}

// % Free Space
double LogicalDisk::GetFreeSpacePercent(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Free Space";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Free Megabytes
double LogicalDisk::GetFreeMegabytes(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Free Megabytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Current Disk Queue Length
double LogicalDisk::GetCurrentDiskQueueLength(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Current Disk Queue Length";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Disk Time
double LogicalDisk::GetDiskTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Queue Length
double LogicalDisk::GetAverageDiskQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Disk Read Time
double LogicalDisk::GetDiskReadTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Read Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Read Queue Length
double LogicalDisk::GetAverageDiskReadQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Read Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Disk Write Time
double LogicalDisk::GetDiskWriteTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Disk Write Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Write Queue Length
double LogicalDisk::GetAverageDiskWriteQueueLength(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Write Queue Length";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Transfer
double LogicalDisk::GetAverageDiskTransferTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Transfer";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Read
double LogicalDisk::GetAverageDiskReadTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Read";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk sec/Write
double LogicalDisk::GetAverageDiskWriteTimeInSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk sec/Write";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Transfers/sec
double LogicalDisk::GetDiskTransfersPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Transfers/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Reads/sec
double LogicalDisk::GetDiskReadsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Reads/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Writes/sec
double LogicalDisk::GetDiskWritesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Writes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Bytes/sec
double LogicalDisk::GetDiskBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Read Bytes/sec
double LogicalDisk::GetDiskReadBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Read Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Disk Write Bytes/sec
double LogicalDisk::GetDiskWriteBytesPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Disk Write Bytes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Transfer
double LogicalDisk::GetAverageDiskBytesPerTransfer(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Transfer";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Read
double LogicalDisk::GetAverageDiskBytesPerRead(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Read";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Avg. Disk Bytes/Write
double LogicalDisk::GetAverageDiskBytesPerWrite(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Avg. Disk Bytes/Write";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Idle Time
double LogicalDisk::GetIdleTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Idle Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Split IO/Sec
double LogicalDisk::GetSplitIOPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\LogicalDisk(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Split IO/Sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}