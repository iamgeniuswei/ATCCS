#!/bin/sh
# 
# File:   atccs_pre_compile.sh
# Author: lenovo
#
# Created on Jul 27, 2017, 9:55:12 AM
#

#atccs related *.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccsuser --generate-query --generate-session atccsuser.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccsat --generate-query --generate-session atccsat.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccsdevice --generate-query --generate-session atccsdevice.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccseme --generate-query --generate-session atccseme.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccsutilization --generate-query --generate-session atccsutilization.h
odb -d pgsql --std c++11 --generate-schema --schema-format embedded --schema-name atccsutilizationlog --generate-query --generate-session atccsutilizationlog.h

#at independent related *.h
odb -d pgsql --std c++11 --generate-query --generate-session atccspublicstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsgimbalstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsccdstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsfocusstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsfilterstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsslavedomestatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsfullopeneddomestatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsdpmstatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsguidescopestatus.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsplan.h -I ../../ATCCSProtocol/src/
odb -d pgsql --std c++11 --generate-query --generate-session atccsinstruction.h -I ../../ATCCSProtocol/src/

#at60 related *.h
