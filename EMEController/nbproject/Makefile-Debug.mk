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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/emedatadispatcherprocessor.o \
	${OBJECTDIR}/src/emedatagather.o \
	${OBJECTDIR}/src/emesetting.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/TC_EMESetting.o \
	${TESTDIR}/tests/TESTRUNNER.o \
	${TESTDIR}/tests/TEST_EMEDataGather.o \
	${TESTDIR}/tests/TestRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wl,--no-as-needed -pthread
CXXFLAGS=-Wl,--no-as-needed -pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'../ATCCSDataMediator/dist/Debug/GNU-Linux' -L../ATCCSDataMediator/dist/Debug/GNU-Linux -lATCCSDataMediator -Wl,-rpath,'../ATCCSNetwork/dist/Debug/GNU-Linux' -L../ATCCSNetwork/dist/Debug/GNU-Linux -lATCCSNetwork -Wl,-rpath,'../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -Wl,-rpath,'../ATCCSUtility/dist/Release/GNU-Linux' -L../ATCCSUtility/dist/Release/GNU-Linux -lATCCSUtility

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller
	${CP} ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/emedatadispatcherprocessor.o: src/emedatadispatcherprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatadispatcherprocessor.o src/emedatadispatcherprocessor.cpp

${OBJECTDIR}/src/emedatagather.o: src/emedatagather.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatagather.o src/emedatagather.cpp

${OBJECTDIR}/src/emesetting.o: src/emesetting.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emesetting.o src/emesetting.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/TC_EMESetting.o ${TESTDIR}/tests/TestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}  -lcppunit `cppunit-config --libs` -Wl,-rpath,'../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'../ATCCSUtility/dist/Release/GNU-Linux' -L../ATCCSUtility/dist/Release/GNU-Linux -lATCCSUtility   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TESTRUNNER.o ${TESTDIR}/tests/TEST_EMEDataGather.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}  -lcppunit `cppunit-config --libs` -Wl,-rpath,'../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol   


${TESTDIR}/tests/TC_EMESetting.o: tests/TC_EMESetting.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -Isrc -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TC_EMESetting.o tests/TC_EMESetting.cpp


${TESTDIR}/tests/TestRunner.o: tests/TestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -Isrc -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestRunner.o tests/TestRunner.cpp


${TESTDIR}/tests/TESTRUNNER.o: tests/TESTRUNNER.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -Isrc -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TESTRUNNER.o tests/TESTRUNNER.cpp


${TESTDIR}/tests/TEST_EMEDataGather.o: tests/TEST_EMEDataGather.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -Isrc -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TEST_EMEDataGather.o tests/TEST_EMEDataGather.cpp


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/src/emedatadispatcherprocessor_nomain.o: ${OBJECTDIR}/src/emedatadispatcherprocessor.o src/emedatadispatcherprocessor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/emedatadispatcherprocessor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatadispatcherprocessor_nomain.o src/emedatadispatcherprocessor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/emedatadispatcherprocessor.o ${OBJECTDIR}/src/emedatadispatcherprocessor_nomain.o;\
	fi

${OBJECTDIR}/src/emedatagather_nomain.o: ${OBJECTDIR}/src/emedatagather.o src/emedatagather.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/emedatagather.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatagather_nomain.o src/emedatagather.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/emedatagather.o ${OBJECTDIR}/src/emedatagather_nomain.o;\
	fi

${OBJECTDIR}/src/emesetting_nomain.o: ${OBJECTDIR}/src/emesetting.o src/emesetting.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/emesetting.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emesetting_nomain.o src/emesetting.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/emesetting.o ${OBJECTDIR}/src/emesetting_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSUtility.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emecontroller

# Subprojects
.clean-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
