#include "stdafx.h"
#include "TCPv6Monitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=TCPv6::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getSegmentsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv6::GetSegmentsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getConnectionsEstablished
	(JNIEnv * environment, jobject object)
{
	return TCPv6::GetConnectionsEstablished();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getConnectionsActive
	(JNIEnv * environment, jobject object)
{
	return TCPv6::GetConnectionsActive();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getConnectionsPassive
	(JNIEnv * environment, jobject object)
{
	return TCPv6::GetConnectionsPassive();
}
JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getConnectionFailures
	(JNIEnv * environment, jobject object)
{
	return TCPv6::GetConnectionFailures();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getConnectionsReset
	(JNIEnv * environment, jobject object)
{
	return TCPv6::GetConnectionsReset();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getSegmentsReceivedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv6::GetSegmentsReceivedPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getSegmentsSentPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv6::GetSegmentsSentPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv6Monitor_getSegmentsRetransmittedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv6::GetSegmentsRetransmittedPerSecond(idleTime);
}