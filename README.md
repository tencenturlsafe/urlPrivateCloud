## 神荼服务部署指引



### 1. 简介

本文档提供的SDK供您使用请求调用的方式来实现腾讯神荼服务的接入等相关服务。请确保在使用这些接口前，已对腾讯神荼服务充分了解。



### 2. 目录结构

- include/：神荼SDK头文件
- lib/：神荼SDK静态库
- examples/：神荼更新服务源码示例
- build/：神荼更新服务预编译部署包



### 3. 在线更新服务Demo部署指引

1. 解压 build/online_demo.tgz 至指定服务部署目录
2. 修改 online_demo/script/update_monitor.sh 的DIR变量为指定服务部署目录
3. 替换 online_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 online_demo/script/update_monitor.sh 脚本，启动服务
5. 观察 online_demo/script/online_update.log 日志，查看是否异常



### 4. 离线更新服务Demo部署指引

1. 解压 build/local_demo.tgz 至指定服务部署目录
2. 修改 local_demo/script/update_monitor.sh 脚本的DIR变量为指定服务部署目录
3. 替换 local_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 local_demo/script/update_monitor.sh 脚本，启动服务
5. 观察 local_demo/script/online_update.log 日志，查看是否异常
6. 修改 local_demo/script/sync_ftp.sh 脚本配置函数变量</br>
   (1) 修改DIR变量为指定服务部署目录</br>
   (2) 修改MAC变量为licence.conf的注册MAC地址</br>
   (3) 修改FTP变量为本地FTP目录</br>
7. 启动 local_demo/script/sync_ftp.sh 脚本，查看同步是否异常
