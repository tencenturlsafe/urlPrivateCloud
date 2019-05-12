/**
 *  Copyright (c) 2018 Tencent, Inc. All rights reserved.
 * 
 *     Filename: common.h
 *      Company: Tencent
 *  Description:  
 */

#ifndef ONLINE_DEMO_COMMON_H_
#define ONLINE_DEMO_COMMON_H_

#define LOG(format, ...) \
    do {\
        printf("[ %s/%s, %d ]\t" format "\n", \
               __FILE__, __func__, __LINE__, ##__VA_ARGS__);\
    } while (0)

#endif  // ONLINE_DEMO_COMMON_H_
