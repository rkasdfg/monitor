#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "NetworkInterface.h"

list<wstring> NetworkInterface::GetInstances()
{
	return Common::GetInstanceName(L"Network Interface");
}

list<wstring> NetworkInterface::GetCounterList()
{
	return Common::GetCounterList(L"Network Interface");
}

// Bytes Total/sec
double NetworkInterface::GetBytesTotalPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Bytes Total/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets/sec
double NetworkInterface::GetPacketsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Received/sec
double NetworkInterface::GetPacketsReceivedPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Sent/sec
double NetworkInterface::GetPacketsSentPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Current Bandwidth
double NetworkInterface::GetCurrentBandwidth(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Current Bandwidth";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Bytes Received/sec
double NetworkInterface::GetBytesReceivedPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Bytes Received/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Received Unicast/sec
double NetworkInterface::GetPacketsReceivedUnicastPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received Unicast/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Received Non-Unicast/sec
double NetworkInterface::GetPacketsReceivedNonUnicastPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received Non-Unicast/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Received Discarded
double NetworkInterface::GetPacketsReceivedDiscarded(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received Discarded";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Packets Received Errors
double NetworkInterface::GetPacketsReceivedErrors(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received Errors";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Packets Received Unknown
double NetworkInterface::GetPacketsReceivedUnknown(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Received Unknown";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Bytes Sent/sec
double NetworkInterface::GetBytesSentPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Bytes Sent/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Sent Unicast/sec
double NetworkInterface::GetPacketsSentUnicastPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Sent Unicast/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Sent Non-Unicast/sec
double NetworkInterface::GetPacketsSentNonUnicastPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Sent Non-Unicast/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Packets Outbound Discarded
double NetworkInterface::GetPacketsOutboundDiscarded(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Outbound Discarded";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Packets Outbound Errors
double NetworkInterface::GetPacketsOutboundErrors(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Packets Outbound Errors";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Output Queue Length
double NetworkInterface::GetOutputQueueLength(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Output Queue Length";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Offloaded Connections
double NetworkInterface::GetOffloadedConnections(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\Offloaded Connections";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// TCP Active RSC Connections
double NetworkInterface::GetTcpActiveRscConnections(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\TCP Active RSC Connections";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// TCP RSC Coalesced Packets/sec
double NetworkInterface::GetTcpRscCoalescedPacketsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\TCP RSC Coalesced Packets/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// TCP RSC Exceptions/sec
double NetworkInterface::GetTcpRscExceptionsPerSecond(const wchar_t * instanceName, int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\TCP RSC Exceptions/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// TCP RSC Average Packet Size
double NetworkInterface::GetTcpRscAveragePacketSize(const wchar_t * instanceName)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Network Interface(";
	fullCounterPath+=instanceName;
	fullCounterPath+=L")\\TCP RSC Average Packet Size";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}
