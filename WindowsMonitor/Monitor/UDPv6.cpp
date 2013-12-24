#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "UDPv6.h"

list<wstring> UDPv6::GetCounterList()
{
	return Common::GetCounterList(L"UDPv6");
}

// Datagrams/sec
double UDPv6::GetDatagramsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv6\\Datagrams/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams Received/sec
double UDPv6::GetDatagramsReceivedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv6\\Datagrams Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams No Port/sec
double UDPv6::GetDatagramsNoPortPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv6\\Datagrams No Port/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Datagrams Received Errors
double UDPv6::GetDatagramsReceivedErrors()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv6\\Datagrams Received Errors";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Datagrams Sent/sec
double UDPv6::GetDatagramsSentPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\UDPv6\\Datagrams Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}
