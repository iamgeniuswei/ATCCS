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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/at60ccdcontroller.o \
	${OBJECTDIR}/src/at60exceptiondisplayer.o \
	${OBJECTDIR}/src/at60filtercontroller.o \
	${OBJECTDIR}/src/at60focuscontroller.o \
	${OBJECTDIR}/src/at60gimbalcontroller.o \
	${OBJECTDIR}/src/at60plancontroller.o \
	${OBJECTDIR}/src/at60setting.o \
	${OBJECTDIR}/src/at60slavedomecontroller.o \
	${OBJECTDIR}/src/tinyxml2.o


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
LDLIBSOPTIONS=-L/usr/local/lib -Wl,-rpath,'/usr/local/lib' -Wl,-rpath,'$$ORIGIN/../../../../ATCCSNetwork/dist/Release/GNU-Linux' -L../ATCCSNetwork/dist/Release/GNU-Linux -lATCCSNetwork -Wl,-rpath,'$$ORIGIN/../../../../ATCCSOrm/dist/Release/GNU-Linux' -L../ATCCSOrm/dist/Release/GNU-Linux -lATCCSOrm -Wl,-rpath,'$$ORIGIN/../../../../ATCCSProtocol/dist/Release/GNU-Linux' -L../ATCCSProtocol/dist/Release/GNU-Linux -lATCCSProtocol -Wl,-rpath,'$$ORIGIN/../../../../ATController/dist/Release/GNU-Linux' -L../ATController/dist/Release/GNU-Linux -lATController -Wl,-rpath,'$$ORIGIN/../../../../ATCCSDataMediator/dist/Release/GNU-Linux' -L../ATCCSDataMediator/dist/Release/GNU-Linux -lATCCSDataMediator

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller
	${CP} ../ATCCSNetwork/dist/Release/GNU-Linux/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSOrm/dist/Release/GNU-Linux/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSProtocol/dist/Release/GNU-Linux/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATController/dist/Release/GNU-Linux/libATController.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSDataMediator/dist/Release/GNU-Linux/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSNetwork/dist/Release/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSOrm/dist/Release/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSProtocol/dist/Release/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATController/dist/Release/GNU-Linux/libATController.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSDataMediator/dist/Release/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller ${OBJECTFILES} ${LDLIBSOPTIONS} -lodb -lodb-pgsql

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/at60ccdcontroller.o: src/at60ccdcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdcontroller.o src/at60ccdcontroller.cpp

${OBJECTDIR}/src/at60exceptiondisplayer.o: src/at60exceptiondisplayer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60exceptiondisplayer.o src/at60exceptiondisplayer.cpp

${OBJECTDIR}/src/at60filtercontroller.o: src/at60filtercontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filtercontroller.o src/at60filtercontroller.cpp

${OBJECTDIR}/src/at60focuscontroller.o: src/at60focuscontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focuscontroller.o src/at60focuscontroller.cpp

${OBJECTDIR}/src/at60gimbalcontroller.o: src/at60gimbalcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalcontroller.o src/at60gimbalcontroller.cpp

${OBJECTDIR}/src/at60plancontroller.o: src/at60plancontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plancontroller.o src/at60plancontroller.cpp

${OBJECTDIR}/src/at60setting.o: src/at60setting.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60setting.o src/at60setting.cpp

${OBJECTDIR}/src/at60slavedomecontroller.o: src/at60slavedomecontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomecontroller.o src/at60slavedomecontroller.cpp

${OBJECTDIR}/src/tinyxml2.o: src/tinyxml2.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyxml2.o src/tinyxml2.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Release
	cd ../ATController && ${MAKE}  -f Makefile CONF=Release
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATController.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller

# Subprojects
.clean-subprojects:
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATController && ${MAKE}  -f Makefile CONF=Release clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
