/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor */

#ifndef _Included_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
#define _Included_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getInstances
	* Signature: ()[Ljava/lang/String;
	*/
	JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getInstances
		(JNIEnv *, jobject);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getCounterList
	* Signature: ()[Ljava/lang/String;
	*/
	JNIEXPORT jobjectArray JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getCounterList
		(JNIEnv *, jobject);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getBytesTotalPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesTotalPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsSentPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getCurrentBandwidth
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getCurrentBandwidth
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getBytesReceivedPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesReceivedPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedUnicastPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedUnicastPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedNonUnicastPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedNonUnicastPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedDiscarded
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedDiscarded
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedErrors
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedErrors
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsReceivedUnknown
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsReceivedUnknown
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getBytesSentPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getBytesSentPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsSentUnicastPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentUnicastPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsSentNonUnicastPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsSentNonUnicastPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsOutboundDiscarded
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsOutboundDiscarded
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getPacketsOutboundErrors
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getPacketsOutboundErrors
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getOutputQueueLength
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getOutputQueueLength
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getOffloadedConnections
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getOffloadedConnections
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getTcpActiveRscConnections
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpActiveRscConnections
		(JNIEnv *, jobject, jstring);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getTcpRscCoalescedPacketsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscCoalescedPacketsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getTcpRscExceptionsPerSecond
	* Signature: (Ljava/lang/String;I)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscExceptionsPerSecond
		(JNIEnv *, jobject, jstring, jint);

	/*
	* Class:     org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor
	* Method:    getTcpRscAveragePacketSize
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_org_bench4q_monitor_performance_windows_NetworkInterfaceMonitor_getTcpRscAveragePacketSize
		(JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif