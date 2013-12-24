#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "TCPv6.h"

list<wstring> TCPv6::GetCounterList()
{
	return Common::GetCounterList(L"TCPv6");
}

// Segments/sec
double TCPv6::GetSegmentsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Segments/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Connections Established
double TCPv6::GetConnectionsEstablished()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Connections Established";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Active
double TCPv6::GetConnectionsActive()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Connections Active";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Passive
double TCPv6::GetConnectionsPassive()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Connections Passive";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connection Failures
double TCPv6::GetConnectionFailures()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Connection Failures";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Reset
double TCPv6::GetConnectionsReset()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Connections Reset";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Segments Received/sec
double TCPv6::GetSegmentsReceivedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Segments Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Segments Sent/sec
double TCPv6::GetSegmentsSentPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Segments Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Segments Retransmitted/sec
double TCPv6::GetSegmentsRetransmittedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv6\\Segments Retransmitted/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}