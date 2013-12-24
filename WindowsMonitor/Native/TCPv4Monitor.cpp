#include "stdafx.h"
#include "TCPv4Monitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=TCPv4::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getSegmentsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv4::GetSegmentsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getConnectionsEstablished
	(JNIEnv * environment, jobject object)
{
	return TCPv4::GetConnectionsEstablished();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getConnectionsActive
	(JNIEnv * environment, jobject object)
{
	return TCPv4::GetConnectionsActive();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getConnectionsPassive
	(JNIEnv * environment, jobject object)
{
	return TCPv4::GetConnectionsPassive();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getConnectionFailures
	(JNIEnv * environment, jobject object)
{
	return TCPv4::GetConnectionFailures();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getConnectionsReset
	(JNIEnv * environment, jobject object)
{
	return TCPv4::GetConnectionsReset();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getSegmentsReceivedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv4::GetSegmentsReceivedPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getSegmentsSentPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv4::GetSegmentsSentPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_TCPv4Monitor_getSegmentsRetransmittedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return TCPv4::GetSegmentsRetransmittedPerSecond(idleTime);
}