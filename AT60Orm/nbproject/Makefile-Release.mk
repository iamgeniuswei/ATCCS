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
	${OBJECTDIR}/src/at60slavedomestatus.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libAT60Orm.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libAT60Orm.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libAT60Orm.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/at60ccdstatus-odb.o: src/at60ccdstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus-odb.o src/at60ccdstatus-odb.cxx

${OBJECTDIR}/src/at60ccdstatus.o: src/at60ccdstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60ccdstatus.o src/at60ccdstatus.cpp

${OBJECTDIR}/src/at60filterstatus-odb.o: src/at60filterstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus-odb.o src/at60filterstatus-odb.cxx

${OBJECTDIR}/src/at60filterstatus.o: src/at60filterstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60filterstatus.o src/at60filterstatus.cpp

${OBJECTDIR}/src/at60focusstatus-odb.o: src/at60focusstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus-odb.o src/at60focusstatus-odb.cxx

${OBJECTDIR}/src/at60focusstatus.o: src/at60focusstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60focusstatus.o src/at60focusstatus.cpp

${OBJECTDIR}/src/at60gimbalstatus-odb.o: src/at60gimbalstatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus-odb.o src/at60gimbalstatus-odb.cxx

${OBJECTDIR}/src/at60gimbalstatus.o: src/at60gimbalstatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60gimbalstatus.o src/at60gimbalstatus.cpp

${OBJECTDIR}/src/at60instruction-odb.o: src/at60instruction-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction-odb.o src/at60instruction-odb.cxx

${OBJECTDIR}/src/at60instruction.o: src/at60instruction.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60instruction.o src/at60instruction.cpp

${OBJECTDIR}/src/at60plan-odb.o: src/at60plan-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan-odb.o src/at60plan-odb.cxx

${OBJECTDIR}/src/at60plan.o: src/at60plan.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60plan.o src/at60plan.cpp

${OBJECTDIR}/src/at60slavedomestatus-odb.o: src/at60slavedomestatus-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus-odb.o src/at60slavedomestatus-odb.cxx

${OBJECTDIR}/src/at60slavedomestatus.o: src/at60slavedomestatus.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/at60slavedomestatus.o src/at60slavedomestatus.cpp

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
