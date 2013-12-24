#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API TCPv6
{
public:
	static list<wstring> GetCounterList();
	static double GetSegmentsPerSecond(int idleTime);
	static double GetConnectionsEstablished();
	static double GetConnectionsActive();
	static double GetConnectionsPassive();
	static double GetConnectionFailures();
	static double GetConnectionsReset();
	static double GetSegmentsReceivedPerSecond(int idleTime);
	static double GetSegmentsSentPerSecond(int idleTime);
	static double GetSegmentsRetransmittedPerSecond(int idleTime);
};