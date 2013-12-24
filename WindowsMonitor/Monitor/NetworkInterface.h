#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API NetworkInterface
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetBytesTotalPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsReceivedPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsSentPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetCurrentBandwidth(const wchar_t * instanceName);
	static double GetBytesReceivedPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsReceivedUnicastPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsReceivedNonUnicastPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsReceivedDiscarded(const wchar_t * instanceName);
	static double GetPacketsReceivedErrors(const wchar_t * instanceName);
	static double GetPacketsReceivedUnknown(const wchar_t * instanceName);
	static double GetBytesSentPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsSentUnicastPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsSentNonUnicastPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPacketsOutboundDiscarded(const wchar_t * instanceName);
	static double GetPacketsOutboundErrors(const wchar_t * instanceName);
	static double GetOutputQueueLength(const wchar_t * instanceName);
	static double GetOffloadedConnections(const wchar_t * instanceName);
	static double GetTcpActiveRscConnections(const wchar_t * instanceName);
	static double GetTcpRscCoalescedPacketsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetTcpRscExceptionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetTcpRscAveragePacketSize(const wchar_t * instanceName);
};