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
	${OBJECTDIR}/src/emedatadispatcherprocessor.o \
	${OBJECTDIR}/src/emedatagather.o \
	${OBJECTDIR}/src/emsetting.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../ATCCSUtility/dist/Release/GNU-Linux' -L../ATCCSUtility/dist/Release/GNU-Linux -lATCCSUtility -Wl,-rpath,'../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'../ATCCSNetwork/dist/Debug/GNU-Linux' -L../ATCCSNetwork/dist/Debug/GNU-Linux -lATCCSNetwork -Wl,-rpath,'../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -Wl,-rpath,'../ATCCSDataMediator/dist/Debug/GNU-Linux' -L../ATCCSDataMediator/dist/Debug/GNU-Linux -lATCCSDataMediator

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/emedatadispatcherprocessor.o: src/emedatadispatcherprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatadispatcherprocessor.o src/emedatadispatcherprocessor.cpp

${OBJECTDIR}/src/emedatagather.o: src/emedatagather.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emedatagather.o src/emedatagather.cpp

${OBJECTDIR}/src/emsetting.o: src/emsetting.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATCCSUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emsetting.o src/emsetting.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSEMCore.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../ATCCSUtility && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
