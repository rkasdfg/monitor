#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API UDPv4
{
public:
	static list<wstring> GetCounterList();
	static double GetDatagramsPerSecond(int idleTime);
	static double GetDatagramsReceivedPerSecond(int idleTime);
	static double GetDatagramsNoPortPerSecond(int idleTime);
	static double GetDatagramsReceivedErrors();
	static double GetDatagramsSentPerSecond(int idleTime);
};