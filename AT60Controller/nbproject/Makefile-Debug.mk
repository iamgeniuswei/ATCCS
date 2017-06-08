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
LDLIBSOPTIONS=-L/usr/local/lib -Wl,-rpath,'/usr/local/lib' -Wl,-rpath,'$$ORIGIN/../../../../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol -Wl,-rpath,'$$ORIGIN/../../../../ATCCSNetwork/dist/Debug/GNU-Linux' -L../ATCCSNetwork/dist/Debug/GNU-Linux -lATCCSNetwork -Wl,-rpath,'$$ORIGIN/../../../../ATCCSDataMediator/dist/Debug/GNU-Linux' -L../ATCCSDataMediator/dist/Debug/GNU-Linux -lATCCSDataMediator -Wl,-rpath,'$$ORIGIN/../../../../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -lATCCSProtocol -lATCCSOrm -lATCCSNetwork -lATCCSDataMediator -Wl,-rpath,'$$ORIGIN/../../../../ATController/dist/Debug/GNU-Linux' -L../ATController/dist/Debug/GNU-Linux -lATController

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller
	${CP} ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../ATController/dist/Debug/GNU-Linux/libATController.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSNetwork/dist/Debug/GNU-Linux/libATCCSNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSDataMediator/dist/Debug/GNU-Linux/libATCCSDataMediator.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ../ATController/dist/Debug/GNU-Linux/libATController.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller ${OBJECTFILES} ${LDLIBSOPTIONS} -lodb -lodb-pgsql

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/at60ccdcontroller.o: src/at60ccdcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdcontroller.o src/at60ccdcontroller.cpp

${OBJECTDIR}/src/at60exceptiondisplayer.o: src/at60exceptiondisplayer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60exceptiondisplayer.o src/at60exceptiondisplayer.cpp

${OBJECTDIR}/src/at60filtercontroller.o: src/at60filtercontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filtercontroller.o src/at60filtercontroller.cpp

${OBJECTDIR}/src/at60focuscontroller.o: src/at60focuscontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focuscontroller.o src/at60focuscontroller.cpp

${OBJECTDIR}/src/at60gimbalcontroller.o: src/at60gimbalcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalcontroller.o src/at60gimbalcontroller.cpp

${OBJECTDIR}/src/at60plancontroller.o: src/at60plancontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plancontroller.o src/at60plancontroller.cpp

${OBJECTDIR}/src/at60setting.o: src/at60setting.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60setting.o src/at60setting.cpp

${OBJECTDIR}/src/at60slavedomecontroller.o: src/at60slavedomecontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomecontroller.o src/at60slavedomecontroller.cpp

${OBJECTDIR}/src/tinyxml2.o: src/tinyxml2.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSNetwork/src -I../ATCCSDataMediator/src -I../ATCCSOrm/src -I../ATController/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyxml2.o src/tinyxml2.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATController && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSNetwork.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATController.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/at60controller

# Subprojects
.clean-subprojects:
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSNetwork && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSDataMediator && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATController && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
