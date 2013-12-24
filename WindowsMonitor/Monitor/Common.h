#pragma once
#include "Monitor.h"
#include <string>
using namespace std;

class MONITOR_API Common
{
public:
	static string WideStringToString(const wstring & str);
	static wstring StringToWideString(const string & str);
	static double GetCounterValue(const wchar_t * fullCounterPath);
	static double GetCounterValueWithIdle(const wchar_t * fullCounterPath,int idleTime);
	static list<wstring> GetInstanceName(const wchar_t * objectName);
	static list<wstring> GetCounterList(const wchar_t * objectName);
};