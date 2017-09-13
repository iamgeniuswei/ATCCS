#!/bin/sh
# 
# File:   pre_compile.sh
# Author: lenovo
#
# Created on Sep 12, 2017, 1:57:48 PM
#


#环境监测数据表预编译指令
odb -d pgsql --std c++11 --generate-query --generate-session emerealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name wsrealtimedata --generate-query --generate-session wsrealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name sqmrealtimedata --generate-query --generate-session sqmrealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name dustrealtimedata --generate-query --generate-session dustrealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name dimmrealtimedata --generate-query --generate-session dimmrealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name csrealtimedata --generate-query --generate-session csrealtimedata.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name ascrealtimedata --generate-query --generate-session ascrealtimedata.h
