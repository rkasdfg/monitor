#include "stdafx.h"
#include "NetworkInterfaceMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=NetworkInterface::GetInstances();
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

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=NetworkInterface::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesTotalPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetBytesTotalPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsReceivedPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsSentPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getCurrentBandwidth
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetCurrentBandwidth(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesReceivedPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetBytesReceivedPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedUnicastPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsReceivedUnicastPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedNonUnicastPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsReceivedNonUnicastPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedDiscarded
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetPacketsReceivedDiscarded(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedErrors
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetPacketsReceivedErrors(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedUnknown
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetPacketsReceivedUnknown(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesSentPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetBytesSentPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentUnicastPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsSentUnicastPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentNonUnicastPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetPacketsSentNonUnicastPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsOutboundDiscarded
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetPacketsOutboundDiscarded(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsOutboundErrors
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetPacketsOutboundErrors(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getOutputQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetOutputQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getOffloadedConnections
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetOffloadedConnections(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpActiveRscConnections
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetTcpActiveRscConnections(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscCoalescedPacketsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetTcpRscCoalescedPacketsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscExceptionsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return NetworkInterface::GetTcpRscExceptionsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscAveragePacketSize
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return NetworkInterface::GetTcpRscAveragePacketSize(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}
