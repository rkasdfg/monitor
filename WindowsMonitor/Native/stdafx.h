#pragma once

#ifdef _DEBUG
#ifdef _WIN64
#pragma comment(lib,"../x64/Debug/Monitor.lib")
#else
#pragma comment(lib,"../Debug/Monitor.lib")
#endif
#else
#ifdef _WIN64
#pragma comment(lib,"../x64/Release/Monitor.lib")
#else
#pragma comment(lib,"../Release/Monitor.lib")
#endif
#endif


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "MonitorApi.h"