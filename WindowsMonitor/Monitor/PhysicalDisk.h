#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API PhysicalDisk
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetCurrentDiskQueueLength(const wchar_t * instanceName);
	static double GetDiskTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskTransferTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskTransfersPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWritesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerTransfer(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerRead(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerWrite(const wchar_t * instanceName, int idleTime);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetSplitIOPerSecond(const wchar_t * instanceName, int idleTime);
};