#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Pdh.h>
#include <PdhMsg.h>

#include <memory>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

#pragma comment(lib, "Pdh.lib")