#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ORMHelper.o \
	${OBJECTDIR}/src/ascrealtimedata-odb.o \
	${OBJECTDIR}/src/ascrealtimedata.o \
	${OBJECTDIR}/src/at60ccdstatus-odb.o \
	${OBJECTDIR}/src/at60ccdstatus.o \
	${OBJECTDIR}/src/at60filterstatus-odb.o \
	${OBJECTDIR}/src/at60filterstatus.o \
	${OBJECTDIR}/src/at60focusstatus-odb.o \
	${OBJECTDIR}/src/at60focusstatus.o \
	${OBJECTDIR}/src/at60gimbalstatus-odb.o \
	${OBJECTDIR}/src/at60gimbalstatus.o \
	${OBJECTDIR}/src/at60instruction-odb.o \
	${OBJECTDIR}/src/at60instruction.o \
	${OBJECTDIR}/src/at60plan-odb.o \
	${OBJECTDIR}/src/at60plan.o \
	${OBJECTDIR}/src/at60slavedomestatus-odb.o \
	${OBJECTDIR}/src/at60slavedomestatus.o \
	${OBJECTDIR}/src/atccsat-odb.o \
	${OBJECTDIR}/src/atccsat.o \
	${OBJECTDIR}/src/atccsccdstatus-odb.o \
	${OBJECTDIR}/src/atccsccdstatus.o \
	${OBJECTDIR}/src/atccsdevice-odb.o \
	${OBJECTDIR}/src/atccsdevice.o \
	${OBJECTDIR}/src/atccsdpmstatus-odb.o \
	${OBJECTDIR}/src/atccsdpmstatus.o \
	${OBJECTDIR}/src/atccseme-odb.o \
	${OBJECTDIR}/src/atccseme.o \
	${OBJECTDIR}/src/atccsfilterstatus-odb.o \
	${OBJECTDIR}/src/atccsfilterstatus.o \
	${OBJECTDIR}/src/atccsfocusstatus-odb.o \
	${OBJECTDIR}/src/atccsfocusstatus.o \
	${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o \
	${OBJECTDIR}/src/atccsfullopeneddomestatus.o \
	${OBJECTDIR}/src/atccsgimbalstatus-odb.o \
	${OBJECTDIR}/src/atccsgimbalstatus.o \
	${OBJECTDIR}/src/atccsguidescopestatus-odb.o \
	${OBJECTDIR}/src/atccsguidescopestatus.o \
	${OBJECTDIR}/src/atccsinstruction-odb.o \
	${OBJECTDIR}/src/atccsinstruction.o \
	${OBJECTDIR}/src/atccsoccupation-odb.o \
	${OBJECTDIR}/src/atccsoccupation.o \
	${OBJECTDIR}/src/atccsplan-odb.o \
	${OBJECTDIR}/src/atccsplan.o \
	${OBJECTDIR}/src/atccspublicstatus-odb.o \
	${OBJECTDIR}/src/atccspublicstatus.o \
	${OBJECTDIR}/src/atccsslavedomestatus-odb.o \
	${OBJECTDIR}/src/atccsslavedomestatus.o \
	${OBJECTDIR}/src/atccsuser-odb.o \
	${OBJECTDIR}/src/atccsuser.o \
	${OBJECTDIR}/src/atccsutilization-odb.o \
	${OBJECTDIR}/src/atccsutilization.o \
	${OBJECTDIR}/src/atccsutilizationlog-odb.o \
	${OBJECTDIR}/src/atccsutilizationlog.o \
	${OBJECTDIR}/src/csrealtimedata-odb.o \
	${OBJECTDIR}/src/csrealtimedata.o \
	${OBJECTDIR}/src/dimmrealtimedata-odb.o \
	${OBJECTDIR}/src/dimmrealtimedata.o \
	${OBJECTDIR}/src/dustrealtimedata-odb.o \
	${OBJECTDIR}/src/dustrealtimedata.o \
	${OBJECTDIR}/src/emerealtimedata-odb.o \
	${OBJECTDIR}/src/emerealtimedata.o \
	${OBJECTDIR}/src/sqmrealtimedata-odb.o \
	${OBJECTDIR}/src/sqmrealtimedata.o \
	${OBJECTDIR}/src/wsrealtimedata-odb.o \
	${OBJECTDIR}/src/wsrealtimedata.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/Testclass_csrealtimedata.o \
	${TESTDIR}/tests/Testclass_dimmrealtimedata.o \
	${TESTDIR}/tests/Testclass_dustrealtimedata.o \
	${TESTDIR}/tests/Testclass_sqmrealtimedata.o \
	${TESTDIR}/tests/Testclass_wsrealtimedata.o \
	${TESTDIR}/tests/Testrunner_csrealtimedata.o \
	${TESTDIR}/tests/Testrunner_wsrealtimedata.o \
	${TESTDIR}/tests/newtestclass.o \
	${TESTDIR}/tests/newtestrunner.o \
	${TESTDIR}/tests/testclass_ascrealtimedata.o \
	${TESTDIR}/tests/testrunner_ascrealtimedata.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'../ATCCSProtocol/dist/Release/GNU-Linux' -L../ATCCSProtocol/dist/Release/GNU-Linux -lATCCSProtocol

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.${CND_DLIB_EXT}: ../ATCCSProtocol/dist/Release/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -lodb-pgsql -lodb -shared -fPIC

${OBJECTDIR}/src/ORMHelper.o: src/ORMHelper.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ORMHelper.o src/ORMHelper.cpp

${OBJECTDIR}/src/ascrealtimedata-odb.o: src/ascrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata-odb.o src/ascrealtimedata-odb.cxx

${OBJECTDIR}/src/ascrealtimedata.o: src/ascrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata.o src/ascrealtimedata.cpp

${OBJECTDIR}/src/at60ccdstatus-odb.o: src/at60ccdstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus-odb.o src/at60ccdstatus-odb.cxx

${OBJECTDIR}/src/at60ccdstatus.o: src/at60ccdstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus.o src/at60ccdstatus.cpp

${OBJECTDIR}/src/at60filterstatus-odb.o: src/at60filterstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus-odb.o src/at60filterstatus-odb.cxx

${OBJECTDIR}/src/at60filterstatus.o: src/at60filterstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus.o src/at60filterstatus.cpp

${OBJECTDIR}/src/at60focusstatus-odb.o: src/at60focusstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus-odb.o src/at60focusstatus-odb.cxx

${OBJECTDIR}/src/at60focusstatus.o: src/at60focusstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus.o src/at60focusstatus.cpp

${OBJECTDIR}/src/at60gimbalstatus-odb.o: src/at60gimbalstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus-odb.o src/at60gimbalstatus-odb.cxx

${OBJECTDIR}/src/at60gimbalstatus.o: src/at60gimbalstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus.o src/at60gimbalstatus.cpp

${OBJECTDIR}/src/at60instruction-odb.o: src/at60instruction-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction-odb.o src/at60instruction-odb.cxx

${OBJECTDIR}/src/at60instruction.o: src/at60instruction.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction.o src/at60instruction.cpp

${OBJECTDIR}/src/at60plan-odb.o: src/at60plan-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan-odb.o src/at60plan-odb.cxx

${OBJECTDIR}/src/at60plan.o: src/at60plan.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan.o src/at60plan.cpp

${OBJECTDIR}/src/at60slavedomestatus-odb.o: src/at60slavedomestatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus-odb.o src/at60slavedomestatus-odb.cxx

${OBJECTDIR}/src/at60slavedomestatus.o: src/at60slavedomestatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus.o src/at60slavedomestatus.cpp

${OBJECTDIR}/src/atccsat-odb.o: src/atccsat-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsat-odb.o src/atccsat-odb.cxx

${OBJECTDIR}/src/atccsat.o: src/atccsat.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsat.o src/atccsat.cpp

${OBJECTDIR}/src/atccsccdstatus-odb.o: src/atccsccdstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsccdstatus-odb.o src/atccsccdstatus-odb.cxx

${OBJECTDIR}/src/atccsccdstatus.o: src/atccsccdstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsccdstatus.o src/atccsccdstatus.cpp

${OBJECTDIR}/src/atccsdevice-odb.o: src/atccsdevice-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevice-odb.o src/atccsdevice-odb.cxx

${OBJECTDIR}/src/atccsdevice.o: src/atccsdevice.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevice.o src/atccsdevice.cpp

${OBJECTDIR}/src/atccsdpmstatus-odb.o: src/atccsdpmstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdpmstatus-odb.o src/atccsdpmstatus-odb.cxx

${OBJECTDIR}/src/atccsdpmstatus.o: src/atccsdpmstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdpmstatus.o src/atccsdpmstatus.cpp

${OBJECTDIR}/src/atccseme-odb.o: src/atccseme-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccseme-odb.o src/atccseme-odb.cxx

${OBJECTDIR}/src/atccseme.o: src/atccseme.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccseme.o src/atccseme.cpp

${OBJECTDIR}/src/atccsfilterstatus-odb.o: src/atccsfilterstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfilterstatus-odb.o src/atccsfilterstatus-odb.cxx

${OBJECTDIR}/src/atccsfilterstatus.o: src/atccsfilterstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfilterstatus.o src/atccsfilterstatus.cpp

${OBJECTDIR}/src/atccsfocusstatus-odb.o: src/atccsfocusstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfocusstatus-odb.o src/atccsfocusstatus-odb.cxx

${OBJECTDIR}/src/atccsfocusstatus.o: src/atccsfocusstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfocusstatus.o src/atccsfocusstatus.cpp

${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o: src/atccsfullopeneddomestatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o src/atccsfullopeneddomestatus-odb.cxx

${OBJECTDIR}/src/atccsfullopeneddomestatus.o: src/atccsfullopeneddomestatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfullopeneddomestatus.o src/atccsfullopeneddomestatus.cpp

${OBJECTDIR}/src/atccsgimbalstatus-odb.o: src/atccsgimbalstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsgimbalstatus-odb.o src/atccsgimbalstatus-odb.cxx

${OBJECTDIR}/src/atccsgimbalstatus.o: src/atccsgimbalstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsgimbalstatus.o src/atccsgimbalstatus.cpp

${OBJECTDIR}/src/atccsguidescopestatus-odb.o: src/atccsguidescopestatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsguidescopestatus-odb.o src/atccsguidescopestatus-odb.cxx

${OBJECTDIR}/src/atccsguidescopestatus.o: src/atccsguidescopestatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsguidescopestatus.o src/atccsguidescopestatus.cpp

${OBJECTDIR}/src/atccsinstruction-odb.o: src/atccsinstruction-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstruction-odb.o src/atccsinstruction-odb.cxx

${OBJECTDIR}/src/atccsinstruction.o: src/atccsinstruction.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstruction.o src/atccsinstruction.cpp

${OBJECTDIR}/src/atccsoccupation-odb.o: src/atccsoccupation-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsoccupation-odb.o src/atccsoccupation-odb.cxx

${OBJECTDIR}/src/atccsoccupation.o: src/atccsoccupation.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsoccupation.o src/atccsoccupation.cpp

${OBJECTDIR}/src/atccsplan-odb.o: src/atccsplan-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplan-odb.o src/atccsplan-odb.cxx

${OBJECTDIR}/src/atccsplan.o: src/atccsplan.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplan.o src/atccsplan.cpp

${OBJECTDIR}/src/atccspublicstatus-odb.o: src/atccspublicstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccspublicstatus-odb.o src/atccspublicstatus-odb.cxx

${OBJECTDIR}/src/atccspublicstatus.o: src/atccspublicstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccspublicstatus.o src/atccspublicstatus.cpp

${OBJECTDIR}/src/atccsslavedomestatus-odb.o: src/atccsslavedomestatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsslavedomestatus-odb.o src/atccsslavedomestatus-odb.cxx

${OBJECTDIR}/src/atccsslavedomestatus.o: src/atccsslavedomestatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsslavedomestatus.o src/atccsslavedomestatus.cpp

${OBJECTDIR}/src/atccsuser-odb.o: src/atccsuser-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsuser-odb.o src/atccsuser-odb.cxx

${OBJECTDIR}/src/atccsuser.o: src/atccsuser.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsuser.o src/atccsuser.cpp

${OBJECTDIR}/src/atccsutilization-odb.o: src/atccsutilization-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilization-odb.o src/atccsutilization-odb.cxx

${OBJECTDIR}/src/atccsutilization.o: src/atccsutilization.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilization.o src/atccsutilization.cpp

${OBJECTDIR}/src/atccsutilizationlog-odb.o: src/atccsutilizationlog-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilizationlog-odb.o src/atccsutilizationlog-odb.cxx

${OBJECTDIR}/src/atccsutilizationlog.o: src/atccsutilizationlog.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilizationlog.o src/atccsutilizationlog.cpp

${OBJECTDIR}/src/csrealtimedata-odb.o: src/csrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata-odb.o src/csrealtimedata-odb.cxx

${OBJECTDIR}/src/csrealtimedata.o: src/csrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata.o src/csrealtimedata.cpp

${OBJECTDIR}/src/dimmrealtimedata-odb.o: src/dimmrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata-odb.o src/dimmrealtimedata-odb.cxx

${OBJECTDIR}/src/dimmrealtimedata.o: src/dimmrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata.o src/dimmrealtimedata.cpp

${OBJECTDIR}/src/dustrealtimedata-odb.o: src/dustrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata-odb.o src/dustrealtimedata-odb.cxx

${OBJECTDIR}/src/dustrealtimedata.o: src/dustrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata.o src/dustrealtimedata.cpp

${OBJECTDIR}/src/emerealtimedata-odb.o: src/emerealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata-odb.o src/emerealtimedata-odb.cxx

${OBJECTDIR}/src/emerealtimedata.o: src/emerealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata.o src/emerealtimedata.cpp

${OBJECTDIR}/src/sqmrealtimedata-odb.o: src/sqmrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata-odb.o src/sqmrealtimedata-odb.cxx

${OBJECTDIR}/src/sqmrealtimedata.o: src/sqmrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata.o src/sqmrealtimedata.cpp

${OBJECTDIR}/src/wsrealtimedata-odb.o: src/wsrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata-odb.o src/wsrealtimedata-odb.cxx

${OBJECTDIR}/src/wsrealtimedata.o: src/wsrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata.o src/wsrealtimedata.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Release

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/testclass_ascrealtimedata.o ${TESTDIR}/tests/testrunner_ascrealtimedata.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/Testclass_csrealtimedata.o ${TESTDIR}/tests/Testclass_dimmrealtimedata.o ${TESTDIR}/tests/Testclass_dustrealtimedata.o ${TESTDIR}/tests/Testclass_sqmrealtimedata.o ${TESTDIR}/tests/Testrunner_csrealtimedata.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newtestclass.o ${TESTDIR}/tests/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/Testclass_wsrealtimedata.o ${TESTDIR}/tests/Testrunner_wsrealtimedata.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   


${TESTDIR}/tests/testclass_ascrealtimedata.o: tests/testclass_ascrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testclass_ascrealtimedata.o tests/testclass_ascrealtimedata.cpp


${TESTDIR}/tests/testrunner_ascrealtimedata.o: tests/testrunner_ascrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testrunner_ascrealtimedata.o tests/testrunner_ascrealtimedata.cpp


${TESTDIR}/tests/Testclass_csrealtimedata.o: tests/Testclass_csrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testclass_csrealtimedata.o tests/Testclass_csrealtimedata.cpp


${TESTDIR}/tests/Testclass_dimmrealtimedata.o: tests/Testclass_dimmrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testclass_dimmrealtimedata.o tests/Testclass_dimmrealtimedata.cpp


${TESTDIR}/tests/Testclass_dustrealtimedata.o: tests/Testclass_dustrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testclass_dustrealtimedata.o tests/Testclass_dustrealtimedata.cpp


${TESTDIR}/tests/Testclass_sqmrealtimedata.o: tests/Testclass_sqmrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testclass_sqmrealtimedata.o tests/Testclass_sqmrealtimedata.cpp


${TESTDIR}/tests/Testrunner_csrealtimedata.o: tests/Testrunner_csrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testrunner_csrealtimedata.o tests/Testrunner_csrealtimedata.cpp


${TESTDIR}/tests/newtestclass.o: tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestclass.o tests/newtestclass.cpp


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${TESTDIR}/tests/Testclass_wsrealtimedata.o: tests/Testclass_wsrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testclass_wsrealtimedata.o tests/Testclass_wsrealtimedata.cpp


${TESTDIR}/tests/Testrunner_wsrealtimedata.o: tests/Testrunner_wsrealtimedata.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Testrunner_wsrealtimedata.o tests/Testrunner_wsrealtimedata.cpp


${OBJECTDIR}/src/ORMHelper_nomain.o: ${OBJECTDIR}/src/ORMHelper.o src/ORMHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ORMHelper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ORMHelper_nomain.o src/ORMHelper.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ORMHelper.o ${OBJECTDIR}/src/ORMHelper_nomain.o;\
	fi

${OBJECTDIR}/src/ascrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/ascrealtimedata-odb.o src/ascrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ascrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata-odb_nomain.o src/ascrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ascrealtimedata-odb.o ${OBJECTDIR}/src/ascrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/ascrealtimedata_nomain.o: ${OBJECTDIR}/src/ascrealtimedata.o src/ascrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ascrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata_nomain.o src/ascrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ascrealtimedata.o ${OBJECTDIR}/src/ascrealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/at60ccdstatus-odb_nomain.o: ${OBJECTDIR}/src/at60ccdstatus-odb.o src/at60ccdstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60ccdstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus-odb_nomain.o src/at60ccdstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60ccdstatus-odb.o ${OBJECTDIR}/src/at60ccdstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60ccdstatus_nomain.o: ${OBJECTDIR}/src/at60ccdstatus.o src/at60ccdstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60ccdstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus_nomain.o src/at60ccdstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60ccdstatus.o ${OBJECTDIR}/src/at60ccdstatus_nomain.o;\
	fi

${OBJECTDIR}/src/at60filterstatus-odb_nomain.o: ${OBJECTDIR}/src/at60filterstatus-odb.o src/at60filterstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60filterstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus-odb_nomain.o src/at60filterstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60filterstatus-odb.o ${OBJECTDIR}/src/at60filterstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60filterstatus_nomain.o: ${OBJECTDIR}/src/at60filterstatus.o src/at60filterstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60filterstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus_nomain.o src/at60filterstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60filterstatus.o ${OBJECTDIR}/src/at60filterstatus_nomain.o;\
	fi

${OBJECTDIR}/src/at60focusstatus-odb_nomain.o: ${OBJECTDIR}/src/at60focusstatus-odb.o src/at60focusstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60focusstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus-odb_nomain.o src/at60focusstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60focusstatus-odb.o ${OBJECTDIR}/src/at60focusstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60focusstatus_nomain.o: ${OBJECTDIR}/src/at60focusstatus.o src/at60focusstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60focusstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus_nomain.o src/at60focusstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60focusstatus.o ${OBJECTDIR}/src/at60focusstatus_nomain.o;\
	fi

${OBJECTDIR}/src/at60gimbalstatus-odb_nomain.o: ${OBJECTDIR}/src/at60gimbalstatus-odb.o src/at60gimbalstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60gimbalstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus-odb_nomain.o src/at60gimbalstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60gimbalstatus-odb.o ${OBJECTDIR}/src/at60gimbalstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60gimbalstatus_nomain.o: ${OBJECTDIR}/src/at60gimbalstatus.o src/at60gimbalstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60gimbalstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus_nomain.o src/at60gimbalstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60gimbalstatus.o ${OBJECTDIR}/src/at60gimbalstatus_nomain.o;\
	fi

${OBJECTDIR}/src/at60instruction-odb_nomain.o: ${OBJECTDIR}/src/at60instruction-odb.o src/at60instruction-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60instruction-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction-odb_nomain.o src/at60instruction-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60instruction-odb.o ${OBJECTDIR}/src/at60instruction-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60instruction_nomain.o: ${OBJECTDIR}/src/at60instruction.o src/at60instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction_nomain.o src/at60instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60instruction.o ${OBJECTDIR}/src/at60instruction_nomain.o;\
	fi

${OBJECTDIR}/src/at60plan-odb_nomain.o: ${OBJECTDIR}/src/at60plan-odb.o src/at60plan-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60plan-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan-odb_nomain.o src/at60plan-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60plan-odb.o ${OBJECTDIR}/src/at60plan-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60plan_nomain.o: ${OBJECTDIR}/src/at60plan.o src/at60plan.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60plan.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan_nomain.o src/at60plan.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60plan.o ${OBJECTDIR}/src/at60plan_nomain.o;\
	fi

${OBJECTDIR}/src/at60slavedomestatus-odb_nomain.o: ${OBJECTDIR}/src/at60slavedomestatus-odb.o src/at60slavedomestatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60slavedomestatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus-odb_nomain.o src/at60slavedomestatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60slavedomestatus-odb.o ${OBJECTDIR}/src/at60slavedomestatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/at60slavedomestatus_nomain.o: ${OBJECTDIR}/src/at60slavedomestatus.o src/at60slavedomestatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/at60slavedomestatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus_nomain.o src/at60slavedomestatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/at60slavedomestatus.o ${OBJECTDIR}/src/at60slavedomestatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsat-odb_nomain.o: ${OBJECTDIR}/src/atccsat-odb.o src/atccsat-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsat-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsat-odb_nomain.o src/atccsat-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsat-odb.o ${OBJECTDIR}/src/atccsat-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsat_nomain.o: ${OBJECTDIR}/src/atccsat.o src/atccsat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsat_nomain.o src/atccsat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsat.o ${OBJECTDIR}/src/atccsat_nomain.o;\
	fi

${OBJECTDIR}/src/atccsccdstatus-odb_nomain.o: ${OBJECTDIR}/src/atccsccdstatus-odb.o src/atccsccdstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsccdstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsccdstatus-odb_nomain.o src/atccsccdstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsccdstatus-odb.o ${OBJECTDIR}/src/atccsccdstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsccdstatus_nomain.o: ${OBJECTDIR}/src/atccsccdstatus.o src/atccsccdstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsccdstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsccdstatus_nomain.o src/atccsccdstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsccdstatus.o ${OBJECTDIR}/src/atccsccdstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdevice-odb_nomain.o: ${OBJECTDIR}/src/atccsdevice-odb.o src/atccsdevice-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdevice-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevice-odb_nomain.o src/atccsdevice-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdevice-odb.o ${OBJECTDIR}/src/atccsdevice-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdevice_nomain.o: ${OBJECTDIR}/src/atccsdevice.o src/atccsdevice.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdevice.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevice_nomain.o src/atccsdevice.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdevice.o ${OBJECTDIR}/src/atccsdevice_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdpmstatus-odb_nomain.o: ${OBJECTDIR}/src/atccsdpmstatus-odb.o src/atccsdpmstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdpmstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdpmstatus-odb_nomain.o src/atccsdpmstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdpmstatus-odb.o ${OBJECTDIR}/src/atccsdpmstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdpmstatus_nomain.o: ${OBJECTDIR}/src/atccsdpmstatus.o src/atccsdpmstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdpmstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdpmstatus_nomain.o src/atccsdpmstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdpmstatus.o ${OBJECTDIR}/src/atccsdpmstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccseme-odb_nomain.o: ${OBJECTDIR}/src/atccseme-odb.o src/atccseme-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccseme-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccseme-odb_nomain.o src/atccseme-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccseme-odb.o ${OBJECTDIR}/src/atccseme-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccseme_nomain.o: ${OBJECTDIR}/src/atccseme.o src/atccseme.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccseme.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccseme_nomain.o src/atccseme.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccseme.o ${OBJECTDIR}/src/atccseme_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfilterstatus-odb_nomain.o: ${OBJECTDIR}/src/atccsfilterstatus-odb.o src/atccsfilterstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfilterstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfilterstatus-odb_nomain.o src/atccsfilterstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfilterstatus-odb.o ${OBJECTDIR}/src/atccsfilterstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfilterstatus_nomain.o: ${OBJECTDIR}/src/atccsfilterstatus.o src/atccsfilterstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfilterstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfilterstatus_nomain.o src/atccsfilterstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfilterstatus.o ${OBJECTDIR}/src/atccsfilterstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfocusstatus-odb_nomain.o: ${OBJECTDIR}/src/atccsfocusstatus-odb.o src/atccsfocusstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfocusstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfocusstatus-odb_nomain.o src/atccsfocusstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfocusstatus-odb.o ${OBJECTDIR}/src/atccsfocusstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfocusstatus_nomain.o: ${OBJECTDIR}/src/atccsfocusstatus.o src/atccsfocusstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfocusstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfocusstatus_nomain.o src/atccsfocusstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfocusstatus.o ${OBJECTDIR}/src/atccsfocusstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfullopeneddomestatus-odb_nomain.o: ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o src/atccsfullopeneddomestatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb_nomain.o src/atccsfullopeneddomestatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb.o ${OBJECTDIR}/src/atccsfullopeneddomestatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsfullopeneddomestatus_nomain.o: ${OBJECTDIR}/src/atccsfullopeneddomestatus.o src/atccsfullopeneddomestatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsfullopeneddomestatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfullopeneddomestatus_nomain.o src/atccsfullopeneddomestatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsfullopeneddomestatus.o ${OBJECTDIR}/src/atccsfullopeneddomestatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsgimbalstatus-odb_nomain.o: ${OBJECTDIR}/src/atccsgimbalstatus-odb.o src/atccsgimbalstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsgimbalstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsgimbalstatus-odb_nomain.o src/atccsgimbalstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsgimbalstatus-odb.o ${OBJECTDIR}/src/atccsgimbalstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsgimbalstatus_nomain.o: ${OBJECTDIR}/src/atccsgimbalstatus.o src/atccsgimbalstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsgimbalstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsgimbalstatus_nomain.o src/atccsgimbalstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsgimbalstatus.o ${OBJECTDIR}/src/atccsgimbalstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsguidescopestatus-odb_nomain.o: ${OBJECTDIR}/src/atccsguidescopestatus-odb.o src/atccsguidescopestatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsguidescopestatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsguidescopestatus-odb_nomain.o src/atccsguidescopestatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsguidescopestatus-odb.o ${OBJECTDIR}/src/atccsguidescopestatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsguidescopestatus_nomain.o: ${OBJECTDIR}/src/atccsguidescopestatus.o src/atccsguidescopestatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsguidescopestatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsguidescopestatus_nomain.o src/atccsguidescopestatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsguidescopestatus.o ${OBJECTDIR}/src/atccsguidescopestatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsinstruction-odb_nomain.o: ${OBJECTDIR}/src/atccsinstruction-odb.o src/atccsinstruction-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsinstruction-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstruction-odb_nomain.o src/atccsinstruction-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsinstruction-odb.o ${OBJECTDIR}/src/atccsinstruction-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsinstruction_nomain.o: ${OBJECTDIR}/src/atccsinstruction.o src/atccsinstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsinstruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstruction_nomain.o src/atccsinstruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsinstruction.o ${OBJECTDIR}/src/atccsinstruction_nomain.o;\
	fi

${OBJECTDIR}/src/atccsoccupation-odb_nomain.o: ${OBJECTDIR}/src/atccsoccupation-odb.o src/atccsoccupation-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsoccupation-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsoccupation-odb_nomain.o src/atccsoccupation-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsoccupation-odb.o ${OBJECTDIR}/src/atccsoccupation-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsoccupation_nomain.o: ${OBJECTDIR}/src/atccsoccupation.o src/atccsoccupation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsoccupation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsoccupation_nomain.o src/atccsoccupation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsoccupation.o ${OBJECTDIR}/src/atccsoccupation_nomain.o;\
	fi

${OBJECTDIR}/src/atccsplan-odb_nomain.o: ${OBJECTDIR}/src/atccsplan-odb.o src/atccsplan-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsplan-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplan-odb_nomain.o src/atccsplan-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsplan-odb.o ${OBJECTDIR}/src/atccsplan-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsplan_nomain.o: ${OBJECTDIR}/src/atccsplan.o src/atccsplan.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsplan.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplan_nomain.o src/atccsplan.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsplan.o ${OBJECTDIR}/src/atccsplan_nomain.o;\
	fi

${OBJECTDIR}/src/atccspublicstatus-odb_nomain.o: ${OBJECTDIR}/src/atccspublicstatus-odb.o src/atccspublicstatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccspublicstatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccspublicstatus-odb_nomain.o src/atccspublicstatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccspublicstatus-odb.o ${OBJECTDIR}/src/atccspublicstatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccspublicstatus_nomain.o: ${OBJECTDIR}/src/atccspublicstatus.o src/atccspublicstatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccspublicstatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccspublicstatus_nomain.o src/atccspublicstatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccspublicstatus.o ${OBJECTDIR}/src/atccspublicstatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsslavedomestatus-odb_nomain.o: ${OBJECTDIR}/src/atccsslavedomestatus-odb.o src/atccsslavedomestatus-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsslavedomestatus-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsslavedomestatus-odb_nomain.o src/atccsslavedomestatus-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsslavedomestatus-odb.o ${OBJECTDIR}/src/atccsslavedomestatus-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsslavedomestatus_nomain.o: ${OBJECTDIR}/src/atccsslavedomestatus.o src/atccsslavedomestatus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsslavedomestatus.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsslavedomestatus_nomain.o src/atccsslavedomestatus.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsslavedomestatus.o ${OBJECTDIR}/src/atccsslavedomestatus_nomain.o;\
	fi

${OBJECTDIR}/src/atccsuser-odb_nomain.o: ${OBJECTDIR}/src/atccsuser-odb.o src/atccsuser-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsuser-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsuser-odb_nomain.o src/atccsuser-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsuser-odb.o ${OBJECTDIR}/src/atccsuser-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsuser_nomain.o: ${OBJECTDIR}/src/atccsuser.o src/atccsuser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsuser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsuser_nomain.o src/atccsuser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsuser.o ${OBJECTDIR}/src/atccsuser_nomain.o;\
	fi

${OBJECTDIR}/src/atccsutilization-odb_nomain.o: ${OBJECTDIR}/src/atccsutilization-odb.o src/atccsutilization-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsutilization-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilization-odb_nomain.o src/atccsutilization-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsutilization-odb.o ${OBJECTDIR}/src/atccsutilization-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsutilization_nomain.o: ${OBJECTDIR}/src/atccsutilization.o src/atccsutilization.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsutilization.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilization_nomain.o src/atccsutilization.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsutilization.o ${OBJECTDIR}/src/atccsutilization_nomain.o;\
	fi

${OBJECTDIR}/src/atccsutilizationlog-odb_nomain.o: ${OBJECTDIR}/src/atccsutilizationlog-odb.o src/atccsutilizationlog-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsutilizationlog-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilizationlog-odb_nomain.o src/atccsutilizationlog-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsutilizationlog-odb.o ${OBJECTDIR}/src/atccsutilizationlog-odb_nomain.o;\
	fi

${OBJECTDIR}/src/atccsutilizationlog_nomain.o: ${OBJECTDIR}/src/atccsutilizationlog.o src/atccsutilizationlog.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsutilizationlog.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsutilizationlog_nomain.o src/atccsutilizationlog.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsutilizationlog.o ${OBJECTDIR}/src/atccsutilizationlog_nomain.o;\
	fi

${OBJECTDIR}/src/csrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/csrealtimedata-odb.o src/csrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/csrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata-odb_nomain.o src/csrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/csrealtimedata-odb.o ${OBJECTDIR}/src/csrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/csrealtimedata_nomain.o: ${OBJECTDIR}/src/csrealtimedata.o src/csrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/csrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata_nomain.o src/csrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/csrealtimedata.o ${OBJECTDIR}/src/csrealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/dimmrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/dimmrealtimedata-odb.o src/dimmrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/dimmrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata-odb_nomain.o src/dimmrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/dimmrealtimedata-odb.o ${OBJECTDIR}/src/dimmrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/dimmrealtimedata_nomain.o: ${OBJECTDIR}/src/dimmrealtimedata.o src/dimmrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/dimmrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata_nomain.o src/dimmrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/dimmrealtimedata.o ${OBJECTDIR}/src/dimmrealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/dustrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/dustrealtimedata-odb.o src/dustrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/dustrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata-odb_nomain.o src/dustrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/dustrealtimedata-odb.o ${OBJECTDIR}/src/dustrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/dustrealtimedata_nomain.o: ${OBJECTDIR}/src/dustrealtimedata.o src/dustrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/dustrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata_nomain.o src/dustrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/dustrealtimedata.o ${OBJECTDIR}/src/dustrealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/emerealtimedata-odb_nomain.o: ${OBJECTDIR}/src/emerealtimedata-odb.o src/emerealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/emerealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata-odb_nomain.o src/emerealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/emerealtimedata-odb.o ${OBJECTDIR}/src/emerealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/emerealtimedata_nomain.o: ${OBJECTDIR}/src/emerealtimedata.o src/emerealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/emerealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata_nomain.o src/emerealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/emerealtimedata.o ${OBJECTDIR}/src/emerealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/sqmrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/sqmrealtimedata-odb.o src/sqmrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/sqmrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata-odb_nomain.o src/sqmrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/sqmrealtimedata-odb.o ${OBJECTDIR}/src/sqmrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/sqmrealtimedata_nomain.o: ${OBJECTDIR}/src/sqmrealtimedata.o src/sqmrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/sqmrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata_nomain.o src/sqmrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/sqmrealtimedata.o ${OBJECTDIR}/src/sqmrealtimedata_nomain.o;\
	fi

${OBJECTDIR}/src/wsrealtimedata-odb_nomain.o: ${OBJECTDIR}/src/wsrealtimedata-odb.o src/wsrealtimedata-odb.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/wsrealtimedata-odb.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata-odb_nomain.o src/wsrealtimedata-odb.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/wsrealtimedata-odb.o ${OBJECTDIR}/src/wsrealtimedata-odb_nomain.o;\
	fi

${OBJECTDIR}/src/wsrealtimedata_nomain.o: ${OBJECTDIR}/src/wsrealtimedata.o src/wsrealtimedata.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/wsrealtimedata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I../ATCCSProtocol/src -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata_nomain.o src/wsrealtimedata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/wsrealtimedata.o ${OBJECTDIR}/src/wsrealtimedata_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
