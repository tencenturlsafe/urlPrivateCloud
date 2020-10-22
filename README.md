## 腾讯网址私有云(神荼)服务

### 1. 简介

本文档提供的SDK供您使用请求调用的方式来实现腾讯神荼服务的接入等相关服务。请确保在使用这些接口前，已对腾讯神荼服务充分了解。

腾讯神荼服务主要包含两个模块：更新模块以及匹配模块。

1. 更新模块：同步远程服务的网址库至本地共享内存
  (1) 在线更新方式：本地机器直接使用Http接口请求远程服务同步更新网址库
  (2) 离线更新方式：本地机器通过边界Ftp同步网址库文件至指定更新目录，通过SDK接口加载更新网址库
2. 匹配模块：使用SDK接口查询匹配本地网址库

### 2. 最低配置要求

- 内存：8G可用内存
- 硬盘：32GB可用硬盘空间
- CPU：一个4核CPU

> 注：该配置下可支持10w/s的并发查询，实际服务性能以压测为准。

### 3. 申请网址私有云服务证书

1. 下载位于 tools/getInfo 的证书生成工具，于目标机器执行生成证书文件 licence.info
2. 发送证书至腾讯网址私有云库负责人进行授权，成功授权后返回授权证书 licence.conf
3. 使用SDK接口指定授权证书文件进行网址私有云服务初始化。

### 4. 目录结构

- include/：神荼SDK头文件
- lib/：神荼SDK静态库
- examples/：神荼更新服务源码示例
  - local_demo/ : 离线更新模块服务样例
  - online_demo/ : 在线更新模块服务样例
  - udp_server/ : 匹配模块后台服务样例
  - udp_client/ : 匹配模块客户端调用样例
- build/：神荼更新服务预编译部署包

### 5. 在线更新服务Demo部署指引

1. 解压 build/online_demo.tgz 至指定服务部署目录
2. 修改 online_demo/script/update_monitor.sh 的DIR变量为指定服务部署目录
3. 替换 online_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 online_demo/script/update_monitor.sh 脚本，启动服务
5. 观察 online_demo/script/online_update.log 日志，查看是否异常

### 6. 离线更新服务Demo部署指引

1. 解压 build/local_demo.tgz 至指定服务部署目录
2. 修改 local_demo/script/update_monitor.sh 脚本的DIR变量为指定服务部署目录
3. 替换 local_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 local_demo/script/update_monitor.sh 脚本，启动服务
5. 观察 local_demo/script/online_update.log 日志，查看是否异常
6. 修改 local_demo/script/sync_ftp.sh 脚本配置函数变量
   (1) 修改DIR变量为指定服务部署目录
   (2) 修改MAC变量为licence.conf的注册MAC地址
   (3) 修改FTP变量为本地FTP目录
7. 启动 local_demo/script/sync_ftp.sh 脚本，查看同步是否异常

### 7. UDP匹配服务Demo部署指引

1. 解压 build/match_demo.tgz 至指定服务部署目录
2. 修改 match_demo/script/match_monitor.sh 脚本的DIR变量为指定服务部署目录
3. 替换 match_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 match_demo/script/match_monitor.sh 脚本，启动服务
5. 执行 match_demo/bin/matchClient 测试客户端进行查询测试，输入参数为待匹配URL
