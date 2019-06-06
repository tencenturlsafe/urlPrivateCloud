#!/bin/bash

function Config() {
    PKG_NAME=online_update
    PROCESS_NUM=1

    DIR=/data/privateCloud
    BIN=${DIR}/bin/${PKG_NAME}
    CONF=${DIR}/conf/licence.conf
    LOG=${DIR}/log/monitor.log
}

function ReStart() {
    killall -9 $PKG_NAME &> /dev/null
    cd ${DIR}/bin
    `${BIN} ${CONF}`
}

function Log() {
    local date=`date +'%Y-%m-%d %H:%M:%S'`
    local ip=`/sbin/ifconfig eth0 | grep "inet " | awk '{print $2}' | sed 's/addr\://'`
    echo "$date|$BIN restart in $ip" >> $LOG
}

function SH_Main() {
    Config

    local num=`ps -ef | grep ${BIN} | grep -v "grep" | wc -l`
    if [ $num -lt ${PROCESS_NUM} ]; then
        ReStart
        Log
    fi
}

SH_Main
