#pragma once

#ifdef MONITOR_EXPORTS
#define MONITOR_API __declspec(dllexport)
#else
#define MONITOR_API __declspec(dllimport)
#endif

#include <list>
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

class MONITOR_API LogicalDisk
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetFreeSpacePercent(const wchar_t * instanceName);
	static double GetFreeMegabytes(const wchar_t * instanceName);
	static double GetCurrentDiskQueueLength(const wchar_t * instanceName);
	static double GetDiskTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskTransferTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskTransfersPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWritesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerTransfer(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerRead(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerWrite(const wchar_t * instanceName, int idleTime);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetSplitIOPerSecond(const wchar_t * instanceName, int idleTime);
};

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

class MONITOR_API PhysicalDisk
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetCurrentDiskQueueLength(const wchar_t * instanceName);
	static double GetDiskTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteQueueLength(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskTransferTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskReadTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskWriteTimeInSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskTransfersPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWritesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskReadBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDiskWriteBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerTransfer(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerRead(const wchar_t * instanceName, int idleTime);
	static double GetAverageDiskBytesPerWrite(const wchar_t * instanceName, int idleTime);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetSplitIOPerSecond(const wchar_t * instanceName, int idleTime);
};

class MONITOR_API Process
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetProcessorTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetUserTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetVirtualBytesPeak(const wchar_t * instanceName);
	static double GetVirtualBytes(const wchar_t * instanceName);
	static double GetPageFaultsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetWorkingSetPeak(const wchar_t * instanceName);
	static double GetWorkingSet(const wchar_t * instanceName);
	static double GetPageFileBytesPeak(const wchar_t * instanceName);
	static double GetPageFileBytes(const wchar_t * instanceName);
	static double GetPrivateBytes(const wchar_t * instanceName);
	static double GetThreadCount(const wchar_t * instanceName);
	static double GetPriorityBase(const wchar_t * instanceName);
	static double GetElapsedTime(const wchar_t * instanceName);
	static double GetProcessId(const wchar_t * instanceName);
	static double GetCreatingProcessId(const wchar_t * instanceName);
	static double GetPoolPagedBytes(const wchar_t * instanceName);
	static double GetPoolNonpagedBytes(const wchar_t * instanceName);
	static double GetHandleCount(const wchar_t * instanceName);
	static double GetIOReadOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOWriteOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIODataOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOOtherOperationsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOReadBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOWriteBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIODataBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetIOOtherBytesPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPrivateWorkingSet(const wchar_t * instanceName);
};

class MONITOR_API Processor
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetProcessorTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetUserTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetInterruptsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDpcTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetInterruptTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetDpcsQueuedPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetDpcRate(const wchar_t * instanceName);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC1TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC2TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC3TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC1TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC2TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC3TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
};

class MONITOR_API ProcessorInformation
{
public:
	static list<wstring> GetInstances();
	static list<wstring> GetCounterList();
	static double GetPerformanceLimitFlags(const wchar_t * instanceName);
	static double GetPerformanceLimitPercent(const wchar_t * instanceName);
	static double GetPrivilegedUtilityPercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorUtilityPercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorPerformancePercent(const wchar_t * instanceName, int idleTime);
	static double GetIdleBreakEventsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetAverageIdleTime(const wchar_t * instanceName, int idleTime);
	static double GetClockInterruptsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetProcessorStateFlags(const wchar_t * instanceName);
	static double GetPercentageOfMaximumFrequency(const wchar_t * instanceName);
	static double GetProcessorFrequency(const wchar_t * instanceName);
	static double GetParkingStatus(const wchar_t * instanceName);
	static double GetPriorityTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC3TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC2TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC1TransitionsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetC3TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC2TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetC1TimePercent(const wchar_t * instanceName, int idleTime);
	static double GetIdleTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetDpcRate(const wchar_t * instanceName);
	static double GetDpcsQueuedPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetInterruptTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetDpcTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetInterruptsPerSecond(const wchar_t * instanceName, int idleTime);
	static double GetPrivilegedTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetUserTimePercent(const wchar_t * instanceName, int idleTime);
	static double GetProcessorTimePercent(const wchar_t * instanceName, int idleTime);
};

class MONITOR_API System
{
public:
	static list<wstring> GetCounterList();
	static double GetFileReadOperationsPerSecond(int idleTime);
	static double GetFileWriteOperationsPerSecond(int idleTime);
	static double GetFileControlOperationsPerSecond(int idleTime);
	static double GetFileReadBytesPerSecond(int idleTime);
	static double GetFileWriteBytesPerSecond(int idleTime);
	static double GetFileControlBytesPerSecond(int idleTime);
	static double GetContextSwitchesPerSecond(int idleTime);
	static double GetSystemCallsPerSecond(int idleTime);
	static double GetFileDataOperationsPerSecond(int idleTime);
	static double GetSystemUpTime();
	static double GetProcessorQueueLength();
	static double GetProcessesCount();
	static double GetThreadsCount();
	static double GetAlignmentFixupsPerSecond(int idleTime);
	static double GetExceptionDispatchesPerSecond(int idleTime);
	static double GetFloatingEmulationsPerSecond(int idleTime);
	static double GetRegistryQuotaInUsePercent();
};

class MONITOR_API TCPv4
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

class MONITOR_API UDPv6
{
public:
	static list<wstring> GetCounterList();
	static double GetDatagramsPerSecond(int idleTime);
	static double GetDatagramsReceivedPerSecond(int idleTime);
	static double GetDatagramsNoPortPerSecond(int idleTime);
	static double GetDatagramsReceivedErrors();
	static double GetDatagramsSentPerSecond(int idleTime);
};