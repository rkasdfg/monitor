/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_bench4q_monitor_performance_windows_ProcessorMonitor */

#ifndef _Included_org_bench4q_monitor_performance_windows_ProcessorMonitor
#define _Included_org_bench4q_monitor_performance_windows_ProcessorMonitor
#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getInstances
	* Signature: ()[Ljava/lang/String;
	*/
	JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInstances
		(JNIEnv *, jobject);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getCounterList
	* Signature: ()[Ljava/lang/String;
	*/
	JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getCounterList
		(JNIEnv *, jobject);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getProcessorTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getProcessorTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getUserTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getUserTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getPrivilegedTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getPrivilegedTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getInterruptsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInterruptsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getDpcTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getInterruptTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getInterruptTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getDpcsQueuedPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcsQueuedPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getDpcRate
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getDpcRate
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getIdleTimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getIdleTimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC1TimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC1TimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC2TimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC2TimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC3TimePercent
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC3TimePercent
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC1TransitionsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC1TransitionsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC2TransitionsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC2TransitionsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_ProcessorMonitor
	* Method:    getC3TransitionsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_ProcessorMonitor_getC3TransitionsPerSecond
		(JNIEnv *, jobject, jstring, jint);

#ifdef __cplusplus
}
#endif
#endif