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
	${OBJECTDIR}/src/ascrealtimedata-odb.o \
	${OBJECTDIR}/src/ascrealtimedata.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libEMOrm.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libEMOrm.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libEMOrm.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/ascrealtimedata-odb.o: src/ascrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata-odb.o src/ascrealtimedata-odb.cxx

${OBJECTDIR}/src/ascrealtimedata.o: src/ascrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ascrealtimedata.o src/ascrealtimedata.cpp

${OBJECTDIR}/src/csrealtimedata-odb.o: src/csrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata-odb.o src/csrealtimedata-odb.cxx

${OBJECTDIR}/src/csrealtimedata.o: src/csrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/csrealtimedata.o src/csrealtimedata.cpp

${OBJECTDIR}/src/dimmrealtimedata-odb.o: src/dimmrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata-odb.o src/dimmrealtimedata-odb.cxx

${OBJECTDIR}/src/dimmrealtimedata.o: src/dimmrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dimmrealtimedata.o src/dimmrealtimedata.cpp

${OBJECTDIR}/src/dustrealtimedata-odb.o: src/dustrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata-odb.o src/dustrealtimedata-odb.cxx

${OBJECTDIR}/src/dustrealtimedata.o: src/dustrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dustrealtimedata.o src/dustrealtimedata.cpp

${OBJECTDIR}/src/emerealtimedata-odb.o: src/emerealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata-odb.o src/emerealtimedata-odb.cxx

${OBJECTDIR}/src/emerealtimedata.o: src/emerealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/emerealtimedata.o src/emerealtimedata.cpp

${OBJECTDIR}/src/sqmrealtimedata-odb.o: src/sqmrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata-odb.o src/sqmrealtimedata-odb.cxx

${OBJECTDIR}/src/sqmrealtimedata.o: src/sqmrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/sqmrealtimedata.o src/sqmrealtimedata.cpp

${OBJECTDIR}/src/wsrealtimedata-odb.o: src/wsrealtimedata-odb.cxx
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata-odb.o src/wsrealtimedata-odb.cxx

${OBJECTDIR}/src/wsrealtimedata.o: src/wsrealtimedata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wsrealtimedata.o src/wsrealtimedata.cpp

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
