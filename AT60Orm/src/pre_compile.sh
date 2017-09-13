#!/bin/sh
# 
# File:   pre_compile.sh
# Author: lenovo
#
# Created on Sep 12, 2017, 2:20:16 PM
#
#60cm望远镜数据表预编译指令
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60gimbalstatus --generate-query --generate-session at60gimbalstatus.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60ccdstatus --generate-query --generate-session at60ccdstatus.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60focusstatus --generate-query --generate-session at60focusstatus.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60filterstatus --generate-query --generate-session at60filterstatus.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60slavedomestatus --generate-query --generate-session at60slavedomestatus.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60plan --generate-query --generate-session at60plan.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name at60instruction --generate-query --generate-session at60instruction.h -I ../../ATCCSProtocol/src/ -I ../../ATCCSOrm/src/