#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "TCPv4.h"

list<wstring> TCPv4::GetCounterList()
{
	return Common::GetCounterList(L"TCPv4");
}

// Segments/sec
double TCPv4::GetSegmentsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Segments/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Connections Established
double TCPv4::GetConnectionsEstablished()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Connections Established";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Active
double TCPv4::GetConnectionsActive()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Connections Active";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Passive
double TCPv4::GetConnectionsPassive()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Connections Passive";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connection Failures
double TCPv4::GetConnectionFailures()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Connection Failures";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Connections Reset
double TCPv4::GetConnectionsReset()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Connections Reset";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Segments Received/sec
double TCPv4::GetSegmentsReceivedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Segments Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Segments Sent/sec
double TCPv4::GetSegmentsSentPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Segments Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Segments Retransmitted/sec
double TCPv4::GetSegmentsRetransmittedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\TCPv4\\Segments Retransmitted/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}