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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/mydb_class.o \
	${OBJECTDIR}/src/Client.o \
	${OBJECTDIR}/src/DisplayManager.o \
	${OBJECTDIR}/src/Input.o \
	${OBJECTDIR}/src/LoginManager.o \
	${OBJECTDIR}/src/Staff.o \
	${OBJECTDIR}/src/StaffGeneralMgr.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222_assignment2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222_assignment2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222_assignment2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/mydb_class.o: mydb_class.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mydb_class.o mydb_class.cpp

${OBJECTDIR}/src/Client.o: src/Client.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Client.o src/Client.cpp

${OBJECTDIR}/src/DisplayManager.o: src/DisplayManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DisplayManager.o src/DisplayManager.cpp

${OBJECTDIR}/src/Input.o: src/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Input.o src/Input.cpp

${OBJECTDIR}/src/LoginManager.o: src/LoginManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LoginManager.o src/LoginManager.cpp

${OBJECTDIR}/src/Staff.o: src/Staff.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Staff.o src/Staff.cpp

${OBJECTDIR}/src/StaffGeneralMgr.o: src/StaffGeneralMgr.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StaffGeneralMgr.o src/StaffGeneralMgr.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci222_assignment2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
