#include <jni.h>
/* Header for class org_bench4q_monitor_performance_windows_SystemMonitor */

#ifndef _Included_org_bench4q_monitor_performance_windows_SystemMonitor
#define _Included_org_bench4q_monitor_performance_windows_SystemMonitor
#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getCounterList
	(JNIEnv * environment, jobject object);


JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getFileDataOperationsPerSecond
	(JNIEnv * environment, jobject object, jint idleTime);



JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_SystemMonitor_getProcessorQueueLength
	(JNIEnv * environment, jobject object);

#ifdef __cplusplus
}
#endif
#endif