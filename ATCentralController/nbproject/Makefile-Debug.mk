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
	${OBJECTDIR}/src/ATCCATController.o \
	${OBJECTDIR}/src/ATCCLevel1DataProcessor.o \
	${OBJECTDIR}/src/ATCCLevel2DataProcessor.o


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
LDLIBSOPTIONS=-Wl,-rpath,'$$ORIGIN/../../../../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'$$ORIGIN/../../../../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -Wl,-rpath,'$$ORIGIN/../../../../ATCCSNetwork/dist/Debug/GNU-Linux' -L../ATCCSNetwork/dist/Debug/GNU-Linux -lATCCSNetwork -Wl,-rpath,'$$ORIGIN/../../../../ATCCSDataMediator/dist/Debug/GNU-Linux' -L../ATCCSDataMediator/dist/Debug/GNU-Linux -lATCCSDataMediator -Wl,-rpath,'$$ORIGIN/../../../../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller
	${CP} ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller ${OBJECTFILES} ${LDLIBSOPTIONS} -lodb -lodb-pgsql

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSOrm/src -I../ATCCSNetwork/src -I../ATCCSController/src -I../ATCCSDataMediator/src -I../ATCCOrm/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/ATCCATController.o: src/ATCCATController.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSOrm/src -I../ATCCSNetwork/src -I../ATCCSController/src -I../ATCCSDataMediator/src -I../ATCCOrm/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ATCCATController.o src/ATCCATController.cpp

${OBJECTDIR}/src/ATCCLevel1DataProcessor.o: src/ATCCLevel1DataProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSOrm/src -I../ATCCSNetwork/src -I../ATCCSController/src -I../ATCCSDataMediator/src -I../ATCCOrm/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ATCCLevel1DataProcessor.o src/ATCCLevel1DataProcessor.cpp

${OBJECTDIR}/src/ATCCLevel2DataProcessor.o: src/ATCCLevel2DataProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSOrm/src -I../ATCCSNetwork/src -I../ATCCSController/src -I../ATCCSDataMediator/src -I../ATCCOrm/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ATCCLevel2DataProcessor.o src/ATCCLevel2DataProcessor.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/atcentralcontroller

# Subprojects
.clean-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
