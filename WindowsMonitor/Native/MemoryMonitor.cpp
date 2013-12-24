#include "stdafx.h"
#include "MemoryMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=Memory::GetCounterList();
	list<wstring>::iterator iter;
	long count=(long)counterList.size();
	jobjectArray array=environment->NewObjectArray(
		count,environment->FindClass("java/lang/String"),environment->NewStringUTF(""));
	int i=0;
	for(iter=counterList.begin();iter!=counterList.end();iter++)
	{
		environment->SetObjectArrayElement(array,i
			,environment->NewStringUTF(GetUTF8String((*iter).c_str())));
		i++;
	}
	return array;
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPageFaultsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPageFaultsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getAvailableBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetAvailableBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCommittedBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetCommittedBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCommitLimit
	(JNIEnv * environment, jobject object)
{
	return Memory::GetCommitLimit();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getWriteCopiesPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetWriteCopiesPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getTransitionFaultsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetTransitionFaultsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCacheFaultsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetCacheFaultsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getDemandZeroFaultsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetDemandZeroFaultsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPagesPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPagesPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPagesInputPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPagesInputPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPageReadsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPageReadsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPagesOutputPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPagesOutputPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPoolPagedBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetPoolPagedBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPoolNonpagedBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetPoolNonpagedBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPageWritesPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetPageWritesPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPoolPagedAllocs
	(JNIEnv * environment, jobject object)
{
	return Memory::GetPoolPagedAllocs();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPoolNonpagedAllocs
	(JNIEnv * environment, jobject object)
{
	return Memory::GetPoolNonpagedAllocs();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getFreeSystemPageTableEntries
	(JNIEnv * environment, jobject object)
{
	return Memory::GetFreeSystemPageTableEntries();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCacheBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetCacheBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCacheBytesPeak
	(JNIEnv * environment, jobject object)
{
	return Memory::GetCacheBytesPeak();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getPoolPagedResidentBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetPoolPagedResidentBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getSystemCodeTotalBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetSystemCodeTotalBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getSystemCodeResidentBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetSystemCodeResidentBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getSystemDriverTotalBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetSystemDriverTotalBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getSystemDriverResidentBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetSystemDriverResidentBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getSystemCacheResidentBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetSystemCacheResidentBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getCommittedBytesInUsePercent
	(JNIEnv * environment, jobject object)
{
	return Memory::GetCommittedBytesInUsePercent();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getAvailableKiloBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetAvailableKiloBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getAvailableMegaBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetAvailableMegaBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getTransitionPagesRepurposedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return Memory::GetTransitionPagesRepurposedPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getFreeAndZeroPageListBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetFreeAndZeroPageListBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getModifiedPageListBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetModifiedPageListBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getStandbyCacheReserveBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetStandbyCacheReserveBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getStandbyCacheNormalPriorityBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetStandbyCacheNormalPriorityBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getStandbyCacheCoreBytes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetStandbyCacheCoreBytes();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_MemoryMonitor_getLongTermAverageStandbyCacheLifetimes
	(JNIEnv * environment, jobject object)
{
	return Memory::GetLongTermAverageStandbyCacheLifetimes();
}