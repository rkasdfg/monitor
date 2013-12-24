#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API System
{
public:
	static list<wstring> GetCounterList();
	static double GetFileReadOperationsPerSecond(int idleTime);
	static double GetFileWriteOperationsPerSecond(int idleTime);
	static double GetFileControlOperationsPerSecond(int idleTime);
	static double GetFileReadBytesPerSecond(int idleTime);
	static double GetFileWriteBytesPerSecond(int idleTime);
	static double GetFileControlBytesPerSecond(int idleTime);
	static double GetContextSwitchesPerSecond(int idleTime);
	static double GetSystemCallsPerSecond(int idleTime);
	static double GetFileDataOperationsPerSecond(int idleTime);
	static double GetSystemUpTime();
	static double GetProcessorQueueLength();
	static double GetProcessesCount();
	static double GetThreadsCount();
	static double GetAlignmentFixupsPerSecond(int idleTime);
	static double GetExceptionDispatchesPerSecond(int idleTime);
	static double GetFloatingEmulationsPerSecond(int idleTime);
	static double GetRegistryQuotaInUsePercent();
};
