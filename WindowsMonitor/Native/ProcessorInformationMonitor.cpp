#include "stdafx.h"
#include "ProcessorInformationMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=ProcessorInformation::GetInstances();
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

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=ProcessorInformation::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPerformanceLimitFlags
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetPerformanceLimitFlags(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPerformanceLimitPercent
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetPerformanceLimitPercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPrivilegedUtilityPercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetPrivilegedUtilityPercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getProcessorUtilityPercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetProcessorUtilityPercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getProcessorPerformancePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetProcessorPerformancePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getIdleBreakEventsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetIdleBreakEventsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getAverageIdleTime
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetAverageIdleTime(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getClockInterruptsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetClockInterruptsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getProcessorStateFlags
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetProcessorStateFlags(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPercentageOfMaximumFrequency
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetPercentageOfMaximumFrequency(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getProcessorFrequency
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetProcessorFrequency(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getParkingStatus
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetParkingStatus(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPriorityTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetPriorityTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC3TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC3TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC2TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC2TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC1TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC1TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC3TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC3TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC2TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC2TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getC1TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetC1TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getIdleTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetIdleTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getDpcRate
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return ProcessorInformation::GetDpcRate(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getDpcsQueuedPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetDpcsQueuedPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getInterruptTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetInterruptTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getDpcTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetDpcTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getInterruptsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetInterruptsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getPrivilegedTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetPrivilegedTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getUserTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetUserTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorInformationMonitor_getProcessorTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return ProcessorInformation::GetProcessorTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}