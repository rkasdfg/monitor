#pragma once
#include "Monitor.h"
#include <list>
#include <string>
using namespace std;

class MONITOR_API Memory
{
public:
	static list<wstring> GetCounterList();
	static double GetPageFaultsPerSecond(int idleTime);
	static double GetAvailableBytes();
	static double GetCommittedBytes();
	static double GetCommitLimit();
	static double GetWriteCopiesPerSecond(int idleTime);
	static double GetTransitionFaultsPerSecond(int idleTime);
	static double GetCacheFaultsPerSecond(int idleTime);
	static double GetDemandZeroFaultsPerSecond(int idleTime);
	static double GetPagesPerSecond(int idleTime);
	static double GetPagesInputPerSecond(int idleTime);
	static double GetPageReadsPerSecond(int idleTime);
	static double GetPagesOutputPerSecond(int idleTime);
	static double GetPoolPagedBytes();
	static double GetPoolNonpagedBytes();
	static double GetPageWritesPerSecond(int idleTime);
	static double GetPoolPagedAllocs();
	static double GetPoolNonpagedAllocs();
	static double GetFreeSystemPageTableEntries();
	static double GetCacheBytes();
	static double GetCacheBytesPeak();
	static double GetPoolPagedResidentBytes();
	static double GetSystemCodeTotalBytes();
	static double GetSystemCodeResidentBytes();
	static double GetSystemDriverTotalBytes();
	static double GetSystemDriverResidentBytes();
	static double GetSystemCacheResidentBytes();
	static double GetCommittedBytesInUsePercent();
	static double GetAvailableKiloBytes();
	static double GetAvailableMegaBytes();
	static double GetTransitionPagesRepurposedPerSecond(int idleTime);
	static double GetFreeAndZeroPageListBytes();
	static double GetModifiedPageListBytes();
	static double GetStandbyCacheReserveBytes();
	static double GetStandbyCacheNormalPriorityBytes();
	static double GetStandbyCacheCoreBytes();
	static double GetLongTermAverageStandbyCacheLifetimes();
};
