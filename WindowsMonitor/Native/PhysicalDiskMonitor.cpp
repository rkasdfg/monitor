#include "stdafx.h"
#include "PhysicalDiskMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=PhysicalDisk::GetInstances();
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

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=PhysicalDisk::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getCurrentDiskQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return PhysicalDisk::GetCurrentDiskQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskReadTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskReadTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskReadQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskReadQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskWriteTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskWriteTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskWriteQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskWriteQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskTransferTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskTransferTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskReadTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskReadTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskWriteTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskWriteTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskTransfersPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskTransfersPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskReadsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskReadsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskWritesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskWritesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskReadBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskReadBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getDiskWriteBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetDiskWriteBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskBytesPerTransfer
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskBytesPerTransfer(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskBytesPerRead
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskBytesPerRead(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getAverageDiskBytesPerWrite
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetAverageDiskBytesPerWrite(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getIdleTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetIdleTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_PhysicalDiskMonitor_getSplitIOPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return PhysicalDisk::GetSplitIOPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}