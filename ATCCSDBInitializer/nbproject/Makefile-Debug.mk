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
	${OBJECTDIR}/src/atccsdbinitializer.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../ATCCSOrm/dist/Debug/GNU-Linux' -L../ATCCSOrm/dist/Debug/GNU-Linux -lATCCSOrm -Wl,-rpath,'../ATCCSProtocol/dist/Debug/GNU-Linux' -L../ATCCSProtocol/dist/Debug/GNU-Linux -lATCCSProtocol

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT}: ../ATCCSOrm/dist/Debug/GNU-Linux/libATCCSOrm.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT}: ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/atccsdbinitializer.o: src/atccsdbinitializer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../ATCCSProtocol/src -I../ATCCSOrm/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdbinitializer.o src/atccsdbinitializer.cpp

# Subprojects
.build-subprojects:
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSOrm.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSProtocol.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDBInitializer.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../ATCCSOrm && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../ATCCSProtocol && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc