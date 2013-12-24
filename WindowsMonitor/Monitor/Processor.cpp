#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "Processor.h"

list<wstring> Processor::GetInstances()
{
	return Common::GetInstanceName(L"Processor");
}

list<wstring> Processor::GetCounterList()
{
	return Common::GetCounterList(L"Processor");
}

// % Processor Time
double Processor::GetProcessorTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Processor Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % User Time
double Processor::GetUserTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% User Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Privileged Time
double Processor::GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Privileged Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Interrupts/sec
double Processor::GetInterruptsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Interrupts/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % DPC Time
double Processor::GetDpcTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% DPC Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % Interrupt Time
double Processor::GetInterruptTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Interrupt Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// DPCs Queued/sec
double Processor::GetDpcsQueuedPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\DPCs Queued/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// DPC Rate
double Processor::GetDpcRate(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\DPC Rate";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Idle Time
double Processor::GetIdleTimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% Idle Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C1 Time
double Processor::GetC1TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C1 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C2 Time
double Processor::GetC2TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C2 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// % C3 Time
double Processor::GetC3TimePercent(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\% C3 Time";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C1 Transitions/sec
double Processor::GetC1TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C1 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C2 Transitions/sec
double Processor::GetC2TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C2 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// C3 Transitions/sec
double Processor::GetC3TransitionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Processor(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\C3 Transitions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}