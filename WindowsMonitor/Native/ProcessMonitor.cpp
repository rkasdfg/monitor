#include "stdafx.h"
#include "ProcessMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=Process::GetInstances();
	list<wstring>::iterator iter;
	long count=(long)instances.size();
	jobjectArray array=environment->NewObjectArray(
		count,environment->FindClass("java/lang/String"),environment->NewStringUTF(""));
	int i=0;
	for(iter=instances.begin();iter!=instances.end();iter++)
	{
		environment->SetObjectArrayElement(array,i
			,environment->NewStringUTF(GetUTF8String((*iter).c_str())));
		i++;
	}
	return array;
}

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=Process::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getProcessorTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetProcessorTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getUserTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetUserTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPrivilegedTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetPrivilegedTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getVirtualBytesPeak
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetVirtualBytesPeak(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getVirtualBytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetVirtualBytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPageFaultsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetPageFaultsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getWorkingSetPeak
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetWorkingSetPeak(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getWorkingSet
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetWorkingSet(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPageFileBytesPeak
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPageFileBytesPeak(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPageFileBytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPageFileBytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPrivateBytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPrivateBytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getThreadCount
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetThreadCount(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPriorityBase
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPriorityBase(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getElapsedTime
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetElapsedTime(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getProcessId
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetProcessId(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getCreatingProcessId
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetCreatingProcessId(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPoolPagedBytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPoolPagedBytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPoolNonpagedBytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPoolNonpagedBytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getHandleCount
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetHandleCount(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOReadOperationsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOReadOperationsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOWriteOperationsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOWriteOperationsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIODataOperationsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIODataOperationsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOOtherOperationsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOOtherOperationsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOReadBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOReadBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOWriteBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOWriteBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIODataBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIODataBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getIOOtherBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Process::GetIOOtherBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessMonitor_getPrivateWorkingSet
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Process::GetPrivateWorkingSet(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}
