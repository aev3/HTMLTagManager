#############################################################################
#
# Copyright (c) 2014 AWOLart.com. All rights reserved.	      					
#									      								
# $Id: Makefile 3596 2010-12-15 15:26:57Z avossberg $			      		
#									      								
#############################################################################

#############################################################################
# Makefile for gcc-4.8.x						      					
#############################################################################

#############################################################################
# Artifacts: libHTMLTagger-1.0.1.dylib	& HTMLTagManagerApp	
#############################################################################

#############################################################################
# LIB/BIN/DATA names and src, build, and install directories			     
#############################################################################

ifndef DEBUG
LIB_NAME 			= libHTMLTagManager
else
LIB_NAME 			= libHTMLTagManagerD
endif

LIB_VERSION 		= 1.0.1
SHARED_LIB_SUFFIX 	= dylib
SHARED_LIB 			= ${LIB_NAME}-${LIB_VERSION}.${SHARED_LIB_SUFFIX}
STATIC_LIB_SUFFIX	= a
STATIC_LIB			= ${LIB_NAME}-${LIB_VERSION}.${STATIC_LIB_SUFFIX}

ifndef DEBUG
APP_NAME 			= HTMLTagManagerApp
else
APP_NAME 			= HTMLTagManagerAppD
endif

SRC_DIR 			= ./src
LIB_SRC_DIR 		= ${SRC_DIR}
APP_SRC_DIR 		= ${SRC_DIR}

BUILD_DIR			= build
LIB_BUILD_DIR 		= ${BUILD_DIR}/lib
APP_BUILD_DIR 		= ${BUILD_DIR}/bin

###############################################################################
# C/C++ executables, options, pre-processor flags, load flags, and libraries  #
###############################################################################

CC					= gcc
CXX					= g++

CCWARNINGS			= -Wall
CXXWARNINGS			= -Wall

CCFLAGS 			= ${CFLAGS} ${CCWARNINGS} -DPIC -fPIC -O2
CXXFLAGS 			= -std=c++11 ${CFLAGS} ${CXXWARNINGS} -DPIC -fPIC -O2 -fpermissive

ifdef DEBUG
SYSLDFLAGS 			= -g -O
else
SYSLDFLAGS 			=
endif

CXXLDFLAGS 			= ${CXXFLAGS} ${SYSLDFLAGS}
CCLDFLAGS 			= ${CCFLAGS} ${SYSLDFLAGS}

#####################################################
######               Libraries                 ######               
#####################################################

ifdef MACOSX
LIB_LIBS 			= 
APP_LIBS			= 
else
LIB_LIBS 			= 
APP_LIBS			= 
endif

CXXLIBS 			= 
CPPFLAGS 			= 
INCLUDES 			=	-I${SRC_DIR} \
						-I/usr/local/include \
						-I/usr/local/include/C++
DEFINES				=	

#############################################################################
# C/C++ compiler options						      						#
#############################################################################

CXXCOMPILE 			= ${CXX} ${CXXLDFLAGS} ${INCLUDES} ${DEFINES} -DPIC -fPIC

CCCOMPILE 			= ${CC} ${CCLDFLAGS} ${INCLUDES} ${DEFINES} -DPIC -fPIC 

SHARED_LINK 		= ${CXX} -shared

#############################################################################
# Suffix/Compiler suffix mappings					      					#
#############################################################################

.SUFFIXES: .c .cc .cpp
.cpp.o:
	${CXXCOMPILE} -c $< -o $@
.cc.o:
	${CXXCOMPILE} -c $< -o $@
.c.o:
	${CCCOMPILE} -c $< -o $@

#############################################################################
# LIB/BIN Objects							      							#
#############################################################################

LIB_OBJS 		= 	${LIB_SRC_DIR}/HTMLTagManager.o \
					${LIB_SRC_DIR}/REXConsts.o

APP_OBJ 		= 	${APP_SRC_DIR}/HTMLTagManagerApp.o 
				
#############################################################################
# Common commands used to install and clean/uninstall bin/lib artifacts	 	#
#############################################################################

MKDIR       			= mkdir -p
RM          			= rm -rf
LN						= ln -s
CD 						= cd
COPY					= cp
INSTALL     			= install -c

###############################################################################
# Command for generating static library archive	and shared library			  #
###############################################################################

AR						= ar cru
STATIC_LINK 			= ${CXX} -static 

#############################################################################
# Build Targets								     	 						#
#############################################################################

all:: setup lib app

setup::
	${MKDIR} ${LIB_BUILD_DIR}	
	${MKDIR} ${APP_BUILD_DIR}

lib:: ${LIB_OBJS}
	${SHARED_LINK} ${CXXLDFLAGS} -o ${LIB_BUILD_DIR}/${SHARED_LIB} \
		${LIB_OBJS} ${CXXLIBS}
	${AR} ${LIB_BUILD_DIR}/${STATIC_LIB} ${LIB_OBJS} 

app:: lib ${APP_OBJ}
	${CXX} ${CXXLDFLAGS} -o ${APP_BUILD_DIR}/${APP_NAME} \
		${APP_OBJ} ${LIB_OBJS} ${CXXLIBS}


#############################################################################
# Install Targets							      							#
#############################################################################

install-lib:: setup lib
	${MKDIR} ${LIB_INSTALL_DIR}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}.${STATIC_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${STATIC_LIB}
	${INSTALL} ${LIB_BUILD_DIR}/${STATIC_LIB} \
		${LIB_INSTALL_DIR}/${STATIC_LIB}
	${CD} ${LIB_INSTALL_DIR} && ${LN} ${STATIC_LIB} ${LIB_NAME}.${STATIC_LIB_SUFFIX}
	${INSTALL} ${LIB_BUILD_DIR}/${SHARED_LIB} ${LIB_INSTALL_DIR}/${SHARED_LIB}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}-1.0.${SHARED_LIB_SUFFIX}
	${CD} ${LIB_INSTALL_DIR} && ${LN} ${SHARED_LIB} ${LIB_NAME}-1.0.${SHARED_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}-1.${SHARED_LIB_SUFFIX}
	${CD} ${LIB_INSTALL_DIR} && ${LN} ${SHARED_LIB} ${LIB_NAME}-1.${SHARED_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}.${SHARED_LIB_SUFFIX}
	${CD} ${LIB_INSTALL_DIR} && ${LN} ${SHARED_LIB} ${LIB_NAME}.${SHARED_LIB_SUFFIX}

install-app:: setup lib app
	${MKDIR} ${APP_INSTALL_DIR}
	${INSTALL} ${APP_BUILD_DIR}/${APP_NAME} ${APP_INSTALL_DIR}/${APP_NAME} 

install-data::
	${MKDIR} ${DATA_INSTALL_DIR}
	${COPY} ${DATA_SRC_DIR}/*.txt ${DATA_INSTALL_DIR}
	${COPY} ${DATA_SRC_DIR}/*.properties ${DATA_INSTALL_DIR}


install:: install-lib install-app  

#############################################################################
# Clean/Uninstall Targets						      						#
#############################################################################

clean::
	${RM} ${LIB_SRC_DIR}/*.o
	${RM} ${APP_SRC_DIR}/*.o

distclean:: clean
	${RM} ${BUILD_DIR}

uninstall:: distclean
	${RM} ${LIB_INSTALL_DIR}/${STATIC_LIB}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}.${STATIC_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}-1.0.${SHARED_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}-1.${SHARED_LIB_SUFFIX}
	${RM} ${LIB_INSTALL_DIR}/${LIB_NAME}.${SHARED_LIB_SUFFIX}
	${RM} ${APP_INSTALL_DIR}/${APP_NAME}

# EoF Makefile
