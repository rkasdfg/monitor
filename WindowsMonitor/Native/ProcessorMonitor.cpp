#include "stdafx.h"
#include "ProcessorMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=Processor::GetInstances();
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

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=Processor::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getProcessorTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetProcessorTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getUserTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetUserTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getPrivilegedTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetPrivilegedTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInterruptsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetInterruptsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetDpcTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInterruptTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetInterruptTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcsQueuedPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetDpcsQueuedPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcRate
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return Processor::GetDpcRate(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getIdleTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetIdleTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC1TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC1TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC2TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC2TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC3TimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC3TimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC1TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC1TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC2TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC2TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC3TransitionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return Processor::GetC3TransitionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}