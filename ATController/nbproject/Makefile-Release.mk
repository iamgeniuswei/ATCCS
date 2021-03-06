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
	${OBJECTDIR}/src/atccsccdcontroller.o \
	${OBJECTDIR}/src/atccsdatapacker.o \
	${OBJECTDIR}/src/atccsdevicecontroller.o \
	${OBJECTDIR}/src/atccsdevicestatusprocessor.o \
	${OBJECTDIR}/src/atccsfiltercontroller.o \
	${OBJECTDIR}/src/atccsfocuscontroller.o \
	${OBJECTDIR}/src/atccsgimbalcontroller.o \
	${OBJECTDIR}/src/atccsheartbeatprocessor.o \
	${OBJECTDIR}/src/atccsinstructionresultprocessor.o \
	${OBJECTDIR}/src/atccsinstructionsender.o \
	${OBJECTDIR}/src/atccsplancontroller.o \
	${OBJECTDIR}/src/atccsplanprocessor.o \
	${OBJECTDIR}/src/atccssetting.o \
	${OBJECTDIR}/src/atccsslavedomecontroller.o \
	${OBJECTDIR}/src/atccsupgoingcontroller.o \
	${OBJECTDIR}/src/atccsupgoingdataprocessor.o \
	${OBJECTDIR}/src/atclevel1dataprocessor.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATController.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATController.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATController.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/atccsccdcontroller.o: src/atccsccdcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsccdcontroller.o src/atccsccdcontroller.cpp

${OBJECTDIR}/src/atccsdatapacker.o: src/atccsdatapacker.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatapacker.o src/atccsdatapacker.cpp

${OBJECTDIR}/src/atccsdevicecontroller.o: src/atccsdevicecontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevicecontroller.o src/atccsdevicecontroller.cpp

${OBJECTDIR}/src/atccsdevicestatusprocessor.o: src/atccsdevicestatusprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdevicestatusprocessor.o src/atccsdevicestatusprocessor.cpp

${OBJECTDIR}/src/atccsfiltercontroller.o: src/atccsfiltercontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfiltercontroller.o src/atccsfiltercontroller.cpp

${OBJECTDIR}/src/atccsfocuscontroller.o: src/atccsfocuscontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsfocuscontroller.o src/atccsfocuscontroller.cpp

${OBJECTDIR}/src/atccsgimbalcontroller.o: src/atccsgimbalcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsgimbalcontroller.o src/atccsgimbalcontroller.cpp

${OBJECTDIR}/src/atccsheartbeatprocessor.o: src/atccsheartbeatprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsheartbeatprocessor.o src/atccsheartbeatprocessor.cpp

${OBJECTDIR}/src/atccsinstructionresultprocessor.o: src/atccsinstructionresultprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstructionresultprocessor.o src/atccsinstructionresultprocessor.cpp

${OBJECTDIR}/src/atccsinstructionsender.o: src/atccsinstructionsender.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsinstructionsender.o src/atccsinstructionsender.cpp

${OBJECTDIR}/src/atccsplancontroller.o: src/atccsplancontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplancontroller.o src/atccsplancontroller.cpp

${OBJECTDIR}/src/atccsplanprocessor.o: src/atccsplanprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsplanprocessor.o src/atccsplanprocessor.cpp

${OBJECTDIR}/src/atccssetting.o: src/atccssetting.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccssetting.o src/atccssetting.cpp

${OBJECTDIR}/src/atccsslavedomecontroller.o: src/atccsslavedomecontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsslavedomecontroller.o src/atccsslavedomecontroller.cpp

${OBJECTDIR}/src/atccsupgoingcontroller.o: src/atccsupgoingcontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsupgoingcontroller.o src/atccsupgoingcontroller.cpp

${OBJECTDIR}/src/atccsupgoingdataprocessor.o: src/atccsupgoingdataprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsupgoingdataprocessor.o src/atccsupgoingdataprocessor.cpp

${OBJECTDIR}/src/atclevel1dataprocessor.o: src/atclevel1dataprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atclevel1dataprocessor.o src/atclevel1dataprocessor.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
