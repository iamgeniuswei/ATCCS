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
	${OBJECTDIR}/src/atccs_global.o \
	${OBJECTDIR}/src/atccsaddress.o \
	${OBJECTDIR}/src/atccscontroller.o \
	${OBJECTDIR}/src/atccsdata.o \
	${OBJECTDIR}/src/atccsdatahandler.o \
	${OBJECTDIR}/src/atccsdataprocessor.o \
	${OBJECTDIR}/src/atccsdbaddress.o \
	${OBJECTDIR}/src/atccsexception.o \
	${OBJECTDIR}/src/atccsexceptionhandler.o \
	${OBJECTDIR}/src/atccsmapmanager.o \
	${OBJECTDIR}/src/atccsonline.o \
	${OBJECTDIR}/src/atccsqueue.o \
	${OBJECTDIR}/src/atccsthread.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/atccs_global.o: src/atccs_global.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccs_global.o src/atccs_global.cpp

${OBJECTDIR}/src/atccsaddress.o: src/atccsaddress.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsaddress.o src/atccsaddress.cpp

${OBJECTDIR}/src/atccscontroller.o: src/atccscontroller.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccscontroller.o src/atccscontroller.cpp

${OBJECTDIR}/src/atccsdata.o: src/atccsdata.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdata.o src/atccsdata.cpp

${OBJECTDIR}/src/atccsdatahandler.o: src/atccsdatahandler.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatahandler.o src/atccsdatahandler.cpp

${OBJECTDIR}/src/atccsdataprocessor.o: src/atccsdataprocessor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdataprocessor.o src/atccsdataprocessor.cpp

${OBJECTDIR}/src/atccsdbaddress.o: src/atccsdbaddress.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdbaddress.o src/atccsdbaddress.cpp

${OBJECTDIR}/src/atccsexception.o: src/atccsexception.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsexception.o src/atccsexception.cpp

${OBJECTDIR}/src/atccsexceptionhandler.o: src/atccsexceptionhandler.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsexceptionhandler.o src/atccsexceptionhandler.cpp

${OBJECTDIR}/src/atccsmapmanager.o: src/atccsmapmanager.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsmapmanager.o src/atccsmapmanager.cpp

${OBJECTDIR}/src/atccsonline.o: src/atccsonline.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsonline.o src/atccsonline.cpp

${OBJECTDIR}/src/atccsqueue.o: src/atccsqueue.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsqueue.o src/atccsqueue.cpp

${OBJECTDIR}/src/atccsthread.o: src/atccsthread.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsthread.o src/atccsthread.cpp

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
