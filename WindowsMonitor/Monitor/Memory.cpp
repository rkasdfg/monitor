#include "stdafx.h"
#include "Monitor.h"
#include "Common.h"
#include "Memory.h"

list<wstring> Memory::GetCounterList()
{
	return Common::GetCounterList(L"Memory");
}

// Page Faults/sec
double Memory::GetPageFaultsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Page Faults/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Available Bytes
double Memory::GetAvailableBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Available Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Committed Bytes
double Memory::GetCommittedBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Committed Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Commit Limit
double Memory::GetCommitLimit()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Commit Limit";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Write Copies/sec
double Memory::GetWriteCopiesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Write Copies/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Transition Faults/sec
double Memory::GetTransitionFaultsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Transition Faults/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Cache Faults/sec
double Memory::GetCacheFaultsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Cache Faults/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Demand Zero Faults/sec
double Memory::GetDemandZeroFaultsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Demand Zero Faults/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Pages/sec
double Memory::GetPagesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pages/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Pages Input/sec
double Memory::GetPagesInputPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pages Input/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Page Reads/sec
double Memory::GetPageReadsPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Page Reads/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Pages Output/sec
double Memory::GetPagesOutputPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pages Output/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Pool Paged Bytes
double Memory::GetPoolPagedBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pool Paged Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Pool Nonpaged Bytes
double Memory::GetPoolNonpagedBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pool Nonpaged Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Page Writes/sec
double Memory::GetPageWritesPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Page Writes/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Pool Paged Allocs
double Memory::GetPoolPagedAllocs()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pool Paged Allocs";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Pool Nonpaged Allocs
double Memory::GetPoolNonpagedAllocs()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pool Nonpaged Allocs";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Free System Page Table Entries
double Memory::GetFreeSystemPageTableEntries()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Free System Page Table Entries";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Cache Bytes
double Memory::GetCacheBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Cache Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Cache Bytes Peak
double Memory::GetCacheBytesPeak()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Cache Bytes Peak";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Pool Paged Resident Bytes
double Memory::GetPoolPagedResidentBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Pool Paged Resident Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// System Code Total Bytes
double Memory::GetSystemCodeTotalBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\System Code Total Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// System Code Resident Bytes
double Memory::GetSystemCodeResidentBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\System Code Resident Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// System Driver Total Bytes
double Memory::GetSystemDriverTotalBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\System Driver Total Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// System Driver Resident Bytes
double Memory::GetSystemDriverResidentBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\System Driver Resident Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// System Cache Resident Bytes
double Memory::GetSystemCacheResidentBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\System Cache Resident Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// % Committed Bytes In Use
double Memory::GetCommittedBytesInUsePercent()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\% Committed Bytes In Use";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Available KBytes
double Memory::GetAvailableKiloBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Available KBytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Available MBytes
double Memory::GetAvailableMegaBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Available MBytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Transition Pages RePurposed/sec
double Memory::GetTransitionPagesRepurposedPerSecond(int idleTime)
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Transition Pages RePurposed/sec";
	double ret=Common::GetCounterValueWithIdle(fullCounterPath.c_str(),idleTime);
	return ret;
}

// Free & Zero Page List Bytes
double Memory::GetFreeAndZeroPageListBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Free & Zero Page List Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Modified Page List Bytes
double Memory::GetModifiedPageListBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Modified Page List Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Standby Cache Reserve Bytes
double Memory::GetStandbyCacheReserveBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Standby Cache Reserve Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Standby Cache Normal Priority Bytes
double Memory::GetStandbyCacheNormalPriorityBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Standby Cache Normal Priority Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Standby Cache Core Bytes
double Memory::GetStandbyCacheCoreBytes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Standby Cache Core Bytes";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}

// Long-Term Average Standby Cache Lifetime (s)
double Memory::GetLongTermAverageStandbyCacheLifetimes()
{
	wstring fullCounterPath(L"");
	fullCounterPath+=L"\\Memory\\Long-Term Average Standby Cache Lifetime (s)";
	double ret=Common::GetCounterValue(fullCounterPath.c_str());
	return ret;
}
