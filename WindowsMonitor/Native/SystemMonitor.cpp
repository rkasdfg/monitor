#include "stdafx.h"
#include "SystemMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=System::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getFileDataOperationsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime)
{
	return System::GetFileDataOperationsPerSecond(idleTime);
}



JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getProcessorQueueLength
	(JNIEnv * environment, jobject object)
{
	return System::GetProcessorQueueLength();
}

