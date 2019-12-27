/**
 *  Copyright (c) 2018 Tencent, Inc. All rights reserved.
 * 
 *     Filename: insert_userdata.c
 *      Company: Tencent
 *  Description:  
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include "common.h"
#include "urllibhandler.h"

#define MAX_PARA_LEN 128
#define URLLIB_SHM_KEY 363700
#define URLLIB_MAX_CNT 1500000

int main(int argc, char * argv[])
{
    if(argc != 5){
        LOG("Usage %s url level urltype eviltype\n",argv[0]);
        return -1;
    }
    
    // 打印库版本信息
    LOG("%s\n", UrlLibVersion());

    int iErrCode = 0;
    if(!UserDefineInit(URLLIB_SHM_KEY,URLLIB_MAX_CNT,&iErrCode))
    {
        LOG("UrlLibInit Failed\tErrcode:%#x\n",iErrCode);
        return -2;
    }

    const char * pUrl = argv[1];
    unsigned int uiLevel = atoi(argv[2]);
    unsigned int uiUrlType = atoi(argv[3]);
    unsigned int uiEvilType = atoi(argv[4]);
    int iRet = InsertUserDefineEle(pUrl,uiLevel,uiUrlType,uiEvilType);
    if(iRet != 0x00){
        LOG("url:%s\tInsertUserDefineEle failed! iRet:%#x\n",argv[1],iRet);
    } else {
        LOG("InsertUserDefineEle success");
    }
    return 0;
}
