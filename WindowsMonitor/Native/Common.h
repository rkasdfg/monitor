#pragma once

#include <jni.h>

char * GetJString(JNIEnv * environment, jstring jstr);
char * GetUTF8String(const wchar_t * str);