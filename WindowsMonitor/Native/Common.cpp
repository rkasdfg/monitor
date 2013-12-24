#include "stdafx.h"
#include <jni.h>

char * GetJString(JNIEnv * environment, jstring str)
{
	jsize length=environment->GetStringLength(str);
	const jchar * jcstr=environment->GetStringChars(str,NULL);
	int size=0;
	char * ret=(char *)malloc(length*2+1);
	if(ret==NULL)
	{
		return NULL;
	}
	if((size=WideCharToMultiByte(CP_ACP,0,(wchar_t *)jcstr,length,ret,length*2+1,NULL,NULL))==0)
	{
		return NULL;
	}
	environment->ReleaseStringChars(str,jcstr);
	ret[size]='\0';
	return ret;
}

char * GetUTF8String(const wchar_t * str)
{
	int length=WideCharToMultiByte(CP_UTF8,NULL,str,(long)wcslen(str),NULL,0,NULL,NULL);
	char * ret=new char[length + 1];
	WideCharToMultiByte(CP_UTF8,NULL,str,(long)wcslen(str),ret,length,NULL,NULL);
	ret[length]='\0';
	return ret;
}