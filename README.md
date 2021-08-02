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
3. 修改licence.conf中的日志输出路径为部署路径，具体方法如下，在证书顶部增加下面两行
   - statPath=XXXXX/stat
   - logPath=XXXXX/log/local_update.log
   - 其中XXXXX填写安装的绝对路径，例如证书文件放在 /data/local_demo/conf/license.conf，那么XXXXX就是/data/local_demo
   - 其中stat目录有更详细的更新信息
4. 使用SDK接口指定授权证书文件进行网址私有云服务初始化。

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
8. sync_ftp.sh脚本作用是将离线库文件移动到 local_demo/data/ 目录下，部署时可以根据实际情况自行移动

### 7. UDP匹配服务Demo部署指引

1. 解压 build/match_demo.tgz 至指定服务部署目录
2. 修改 match_demo/script/match_monitor.sh 脚本的DIR变量为指定服务部署目录
3. 替换 match_demo/conf/licence.conf 为本机申请的licence.conf
4. 执行 match_demo/script/match_monitor.sh 脚本，启动服务
5. 执行 match_demo/bin/matchClient 测试客户端进行查询测试，输入参数为待匹配URL

### 8. 简单工具的使用
1. 单条查询 build/local_demo/ 下single_match 使用方法 ./single_match www.xxxx.com 
   (1) 返回  url:www.xxxx.com       uiUrlType:1     uiEvilType:0    uiLevel:0
2. 批量查询 multi_match 使用方法 ./multi_match urlFile saveFile
   (1) urlFile ：网址文件，每行一条网址
   (2) saveFile: 结果文件
    
### 9. 返回参数说明
1. uiUrlType 反诈使用场景下可以忽略
2. uiEvilType 标签类型，代表不同恶意类型。每个标签代表含义请联系服务方获取最新映射
3. uiLevel 代表这条数据的黑级别 
   (1) 1-3：可认为是路径黑
   (2) 4：站点黑
   (3) 5：域名黑

### 10. 接口的二次开发
1. 接口API的说明，详细见 https://github.com/tencenturlsafe/urlPrivateCloud/blob/master/include/urllibhandler.h
2. 使用样例 详见 examples/online_demo/ 和 examples/local_demo/ 开发用例

### 11. 常见错误说明
1.运行single_match时,报错errcode 0x5:
  - 可能原因（1）：没有指定类型转换文件。解决方法：（1）下载文件https://github.com/tencenturlsafe/urlPrivateCloud.old/blob/master/doc/Type2Class.txt （2）licence.conf 增加 typeConvFile配置项指向这个文件路径就行了 
  - 可能原因（2）：single_match应该放在主目录下的./bin目录中，否则无法读到证书，请注意

### 12. 基本操作
1. 重启引擎:
  - (1) 执行 ps -ef | grep online_update | grep -v grep | cut -c 9-15 | xargs kill -s 9 
  - (2) 执行 ./update_monitor.sh &
2. 新增检出类型
  - (1) 在licence.conf 加入相应的标签配置，测试相应的网址是否能命中相应的标签，命中则说明
  - (2) 执行命令关闭更新程序 ps -ef | grep online_update | grep -v grep | cut -c 9-15 | xargs kill -s 9
  - (3) 清空相应的共享内存，重新导入恶意库。
  - (4) 执行命令重启引擎 ./update_monitor.sh &
