#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API ProcessorInformation
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetPerformanceLimitFlags(const wchar_t * instanceName);
	static double GetPerformanceLimitPercent(const wchar_t * instanceName);
	static double GetPrivilegedUtilityPercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorUtilityPercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorPerformancePercent(const wchar_t * instanceName, int idleTime);
	static double GetIdleBreakEventsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageIdleTime(const wchar_t * instanceName, int idleTime);
	static double GetClockInterruptsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetProcessorStateFlags(const wchar_t * instanceName);
	static double GetPercentageOfMaximumFrequency(const wchar_t * instanceName);
	static double GetProcessorFrequency(const wchar_t * instanceName);
	static double GetParkingStatus(const wchar_t * instanceName);
	static double GetPriorityTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC3TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC2TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC1TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC3TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC2TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC1TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetDpcRate(const wchar_t * instanceName);
	static double GetDpcsQueuedPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetInterruptTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetDpcTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetInterruptsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetUserTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorTimePercent(const wchar_t * instanceName, int idleTime);
};