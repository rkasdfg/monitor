#include "stdafx.h"
#include "LogicalDiskMonitor.h"
#include "Common.h"

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getInstances
	(JNIEnv * environment, jobject object)
{
	list<wstring> instances=LogicalDisk::GetInstances();
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

JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getCounterList
	(JNIEnv * environment, jobject object)
{
	list<wstring> counterList=LogicalDisk::GetCounterList();
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

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getFreeSpacePercent
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return LogicalDisk::GetFreeSpacePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getFreeMegabytes
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return LogicalDisk::GetFreeMegabytes(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getCurrentDiskQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName)
{
	return LogicalDisk::GetCurrentDiskQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str());
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskReadTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskReadTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskReadQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskReadQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskWriteTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskWriteTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskWriteQueueLength
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskWriteQueueLength(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskTransferTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskTransferTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskReadTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskReadTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskWriteTimeInSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskWriteTimeInSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskTransfersPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskTransfersPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskReadsPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskReadsPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskWritesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskWritesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskReadBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskReadBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getDiskWriteBytesPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetDiskWriteBytesPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskBytesPerTransfer
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskBytesPerTransfer(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskBytesPerRead
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskBytesPerRead(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getAverageDiskBytesPerWrite
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetAverageDiskBytesPerWrite(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getIdleTimePercent
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetIdleTimePercent(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}

JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_LogicalDiskMonitor_getSplitIOPerSecond
	(JNIEnv * environment, jobject object, jstring instanceName, jint idleTime)
{
	return LogicalDisk::GetSplitIOPerSecond(
		Common::StringToWideString(GetJString(environment,instanceName)).c_str()
		,idleTime);
}
