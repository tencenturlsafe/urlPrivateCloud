/**
 *  Copyright (c) 2018 Tencent, Inc. All rights reserved.
 * 
 *     Filename: parse_conf.h
 *      Company: Tencent
 *  Description:  
 */

#ifndef _PARSE_CONF_
#define _PARSE_CONF_

#include <stdbool.h>

#define MAX_FILE_LEN 128
#define MAX_THREAD_NUM 128

#pragma pack(4)
typedef struct { 
    unsigned int uiType;
    unsigned int uiShmKey;
    unsigned int uiSize;
    short port[MAX_THREAD_NUM];
    short threadNum;
    char strLicence[MAX_FILE_LEN];
} stConf;
#pragma pack()

bool AnalyzeConf(const char * szConfFile,stConf * pConf);

#endif //_PARSE_CONF_
