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
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-Wl,-rpath,'$$ORIGIN/../../../../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -Wl,-rpath,'$$ORIGIN/../../../../ATCCSNetwork/dist/Debug/GNU-Linux' -L../ATCCSNetwork/dist/Debug/GNU-Linux -lATCCSNetwork -Wl,-rpath,'$$ORIGIN/../../../../ATCCSUtility/dist/Release/GNU-Linux' -L../ATCCSUtility/dist/Release/GNU-Linux -lATCCSUtility -Wl,-rpath,'$$ORIGIN/../../../../ATCCSDataMediator/dist/Debug/GNU-Linux' -L../ATCCSDataMediator/dist/Debug/GNU-Linux -lATCCSDataMediator -Wl,-rpath,'$$ORIGIN/../../../../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'$$ORIGIN/../../../../ATCCSEMCore/dist/Debug/GNU-Linux' -L../ATCCSEMCore/dist/Debug/GNU-Linux -lATCCSEMCore

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole
	${CP} ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSEMCore/dist/Debug/GNU-Linux/libATCCSEMCore.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ../ATCCSEMCore/dist/Debug/GNU-Linux/libATCCSEMCore.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole ${OBJECTFILES} ${LDLIBSOPTIONS} -lodb -lodb-pgsql

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSOrm/src -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSUtility/src -I../ATCCSNetwork/src -I../ATCCSEMCore/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSEMCore && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/emgatherconsole

# Subprojects
.clean-subprojects:
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSEMCore && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
