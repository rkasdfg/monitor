#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "ProcessorInformation.h"

list<wstring> ProcessorInformation::GetInstances()
{
	return Common::GetInstanceName(L"Processor Information");
}

list<wstring> ProcessorInformation::GetCounterList()
{
	return Common::GetCounterList(L"Processor Information");
}

// Performance Limit Flags
double ProcessorInformation::GetPerformanceLimitFlags(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Performance Limit Flags";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Performance Limit
double ProcessorInformation::GetPerformanceLimitPercent(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Performance Limit";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Privileged Utility
double ProcessorInformation::GetPrivilegedUtilityPercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Privileged Utility";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Processor Utility
double ProcessorInformation::GetProcessorUtilityPercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Processor Utility";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Processor Performance
double ProcessorInformation::GetProcessorPerformancePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Processor Performance";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Idle Break Events/sec
double ProcessorInformation::GetIdleBreakEventsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Idle Break Events/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Average Idle Time
double ProcessorInformation::GetAverageIdleTime(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Average Idle Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Clock Interrupts/sec
double ProcessorInformation::GetClockInterruptsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Clock Interrupts/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Processor State Flags
double ProcessorInformation::GetProcessorStateFlags(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Processor State Flags";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % of Maximum Frequency
double ProcessorInformation::GetPercentageOfMaximumFrequency(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% of Maximum Frequency";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Processor Frequency
double ProcessorInformation::GetProcessorFrequency(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Processor Frequency";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Parking Status
double ProcessorInformation::GetParkingStatus(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Parking Status";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Priority Time
double ProcessorInformation::GetPriorityTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Priority Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C3 Transitions/sec
double ProcessorInformation::GetC3TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C3 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C2 Transitions/sec
double ProcessorInformation::GetC2TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C2 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C1 Transitions/sec
double ProcessorInformation::GetC1TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C1 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C3 Time
double ProcessorInformation::GetC3TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C3 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C2 Time
double ProcessorInformation::GetC2TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C2 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C1 Time
double ProcessorInformation::GetC1TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C1 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Idle Time
double ProcessorInformation::GetIdleTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Idle Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// DPC Rate
double ProcessorInformation::GetDpcRate(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\DPC Rate";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// DPCs Queued/sec
double ProcessorInformation::GetDpcsQueuedPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\DPCs Queued/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Interrupt Time
double ProcessorInformation::GetInterruptTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Interrupt Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % DPC Time
double ProcessorInformation::GetDpcTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% DPC Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Interrupts/sec
double ProcessorInformation::GetInterruptsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Interrupts/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Privileged Time
double ProcessorInformation::GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Privileged Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % User Time
double ProcessorInformation::GetUserTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% User Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Processor Time
double ProcessorInformation::GetProcessorTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor Information(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Processor Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}