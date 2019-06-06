#!/bin/bash

function Config() {
    DIR=/data/privateCloud/
    FTP=/home/ftp_qq/
    MAC="2c4d54477790"

    PULL_DIR=$FTP/local_check_info/
    PUSH_DIR=$FTP/local_policy_info/$MAC/
    DEST_DIR=$DIR/data/
    CHECK_FILE=$DIR/bin/$MAC
}

function SyncCheckFile() {
    if [ -f ${CHECK_FILE} ]; then
        local last_change_time=`stat -c %Y "${CHECK_FILE}"`
        local now_time=`date +%s`
        local time_diff=`expr ${now_time} - ${last_change_time}`
        if [ ${time_diff} -gt 10 ]; then
            mv ${CHECK_FILE} ${PULL_DIR}
        fi
    fi
}

function SyncUrlLibData() {
    if [ -d ${PUSH_DIR} ]; then
        for file in `ls ${PUSH_DIR}`
        do
            if [ -f ${PUSH_DIR}${file} ]; then
                local last_change_time=`stat -c %Y "${PUSH_DIR}${file}"`
                local now_time=`date +%s`
                local time_diff=`expr ${now_time} - ${last_change_time}`
                if [ ${time_diff} -gt 60 ]; then
                    `mv -f "${PUSH_DIR}${file}" ${DEST_DIR}`
                fi
            fi
        done
    fi
}

function SH_Main() {
    Config
    SyncCheckFile
    SyncUrlLibData
}

SH_Main
