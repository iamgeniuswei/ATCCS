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
	${OBJECTDIR}/src/atccsdatadispatcher.o \
	${OBJECTDIR}/src/atccsdataqueue.o \
	${OBJECTDIR}/src/atccsdatareceiver.o \
	${OBJECTDIR}/src/atccsdatasender.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libATCCSDataMediator.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/atccsdatadispatcher.o: src/atccsdatadispatcher.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatadispatcher.o src/atccsdatadispatcher.cpp

${OBJECTDIR}/src/atccsdataqueue.o: src/atccsdataqueue.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdataqueue.o src/atccsdataqueue.cpp

${OBJECTDIR}/src/atccsdatareceiver.o: src/atccsdatareceiver.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatareceiver.o src/atccsdatareceiver.cpp

${OBJECTDIR}/src/atccsdatasender.o: src/atccsdatasender.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatasender.o src/atccsdatasender.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/src/atccsdatadispatcher_nomain.o: ${OBJECTDIR}/src/atccsdatadispatcher.o src/atccsdatadispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdatadispatcher.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatadispatcher_nomain.o src/atccsdatadispatcher.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdatadispatcher.o ${OBJECTDIR}/src/atccsdatadispatcher_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdataqueue_nomain.o: ${OBJECTDIR}/src/atccsdataqueue.o src/atccsdataqueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdataqueue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdataqueue_nomain.o src/atccsdataqueue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdataqueue.o ${OBJECTDIR}/src/atccsdataqueue_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdatareceiver_nomain.o: ${OBJECTDIR}/src/atccsdatareceiver.o src/atccsdatareceiver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdatareceiver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatareceiver_nomain.o src/atccsdatareceiver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdatareceiver.o ${OBJECTDIR}/src/atccsdatareceiver_nomain.o;\
	fi

${OBJECTDIR}/src/atccsdatasender_nomain.o: ${OBJECTDIR}/src/atccsdatasender.o src/atccsdatasender.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/atccsdatasender.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atccsdatasender_nomain.o src/atccsdatasender.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/atccsdatasender.o ${OBJECTDIR}/src/atccsdatasender_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
