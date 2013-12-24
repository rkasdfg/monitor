#include "stdafx.h"
#include "UDPv4Monitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=UDPv4::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getDatagramsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return UDPv4::GetDatagramsPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getDatagramsReceivedPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return UDPv4::GetDatagramsReceivedPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getDatagramsNoPortPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return UDPv4::GetDatagramsNoPortPerSecond(idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getDatagramsReceivedErrors
	(JNIEnv * environment, jobject object)
{
	return UDPv4::GetDatagramsReceivedErrors();
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_UDPv4Monitor_getDatagramsSentPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return UDPv4::GetDatagramsSentPerSecond(idleTime);
}
