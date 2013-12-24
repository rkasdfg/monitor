#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "UDPv4.h"

list<wstring> UDPv4::GetCounterList()
{
	return Common::GetCounterList(L"UDPv4");
}

// Datagrams/sec
double UDPv4::GetDatagramsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv4\\Datagrams/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams Received/sec
double UDPv4::GetDatagramsReceivedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv4\\Datagrams Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams No Port/sec
double UDPv4::GetDatagramsNoPortPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv4\\Datagrams No Port/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams Received Errors
double UDPv4::GetDatagramsReceivedErrors()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv4\\Datagrams Received Errors";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Datagrams Sent/sec
double UDPv4::GetDatagramsSentPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv4\\Datagrams Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}
