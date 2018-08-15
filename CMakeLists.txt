#  For more information, please see: http://software.sci.utah.edu
#
#  The MIT License
#
#  Copyright (c) 2018 Scientific Computing and Imaging Institute,
#  University of Utah.
#
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the
#  Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included
#  in all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.

SET(Qt5_PATH "" CACHE PATH "Path to directory where Qt 5 is installed. Directory should contain lib and bin subdirectories.")
  
  IF(IS_DIRECTORY ${Qt5_PATH})
    FIND_PACKAGE(Qt5Core REQUIRED HINTS ${Qt5_PATH})
    FIND_PACKAGE(Qt5Gui REQUIRED HINTS ${Qt5_PATH})
    FIND_PACKAGE(Qt5OpenGL REQUIRED HINTS ${Qt5_PATH})
  ELSE()
    MESSAGE(SEND_ERROR "Set Qt5_PATH to directory where Qt 5 is installed (containing lib and bin subdirectories) or set SEG3D_BUILD_INTERFACE to OFF.")
  ENDIF()
  IF(Qt5Core_FOUND)
    MESSAGE(STATUS "Found Qt version: ${Qt5Core_VERSION}")
    IF(${Qt5Core_VERSION} VERSION_LESS "5.9")
      MESSAGE(FATAL_ERROR "Qt 5.9 or greater is required for building the Seg3D GUI")
    ENDIF()
  ELSE()
    MESSAGE(FATAL_ERROR "Qt5 is required for building the Seg3D GUI")
  ENDIF()

 INCLUDE_DIRECTORIES(
 ${Qt5Core_INCLUDE_DIRS}
 ${Qt5Gui_INCLUDE_DIRS}
 ${Qt5OpenGL_INCLUDE_DIRS}
 ${Qt5Widgets_INCLUDE_DIRS}
)

############################################
# Set Seg3D main sources
###########################################

SET(PHILIPS_MAIN_SRCS
  philips_main.cc
)

###########################################
# Build the Seg3D executable
###########################################

ADD_EXECUTABLE(philips ${PHILIPS_MAIN_SRCS})

###########################################
#Add path to Seg3D lib file
###########################################

SET(PHILIPS_LIB "C:/SgbinNoPyR/Seg3D/Main/Philips/Lib/Release/philips_lib.lib")

###########################################
#Required libraries
###########################################

FIND_PACKAGE(OpenGL REQUIRED)

TARGET_LINK_LIBRARIES(philips
  ${PHILIPS_LIB}
  ${OPENGL_LIBRARIES}
  Qt5::Widgets
  Qt5::OpenGL
  wsock32
  rpcrt4
)