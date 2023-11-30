#
# Set CMAKE version
#
cmake_minimum_required( VERSION 3.9 )

#
# Project information
#
set(VERSION 2.2.2) # VERSION should be same as snap version
project( ctrlx_nanotec VERSION ${VERSION} )

#
# Compiler setting
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti") # no Run-Time Type Information
set(CMAKE_CXX_STANDARD 17) # set the required version of Cpp Compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC") # position independent code, useful with shared libraries, compiled coded can be loaded at any address
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG") # preprocessor variable definition, can be used in the source code
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -O2 -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC") # position independent code, useful with shared libraries, compiled coded can be loaded at any address
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMY_DEBUG") # preprocessor variable definition, can be used in the source code

#
# Compiling architecture configuration
#
MESSAGE( STATUS "Selected BuildKit: ${CMAKE_BUILD_KIT}")
IF(${CMAKE_BUILD_KIT} MATCHES "aarch64")
  # SET(PLATFORM_NAME "ubuntu22-gcc-aarch64")
  SET(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
  SET(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
  SET(TARGET_ARCH aarch64-linux-gnu)
  SET(TARGET_PROJECT_NAME ctrlx_nanotec_arm64)
ELSEIF(${CMAKE_BUILD_KIT} MATCHES "x86_64")
  # SET(PLATFORM_NAME "ubuntu22-gcc-x64")
  SET(CMAKE_C_COMPILER gcc) # CMAKE_C_COMPILER is a predefined variable, set it to gcc
  SET(CMAKE_CXX_COMPILER g++) # CMAKE_CXX_COMPILER is a predefined variable, set it to g++
  SET(TARGET_ARCH x86_64-linux-gnu)
  SET(TARGET_PROJECT_NAME ctrlx_nanotec_amd64)
ELSE()
  MESSAGE( ERROR "The selected build kit does not match any of the compilation architectures")
ENDIF()
MESSAGE( STATUS "######################################")

#
# Source file directories
#
set( SOURCE_FILES
  ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/nanotecHandler.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/dataLayerHandler.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/nanolib_helper.cpp
)

#
# Executable defintion
#
add_executable( ${TARGET_PROJECT_NAME} ${SOURCE_FILES} )

#
# Include directories
#
set (INC_DIR ${CMAKE_CURRENT_LIST_DIR}/inc) # for the header files that are in the inc folder
set (SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src) # for the header files that are in the src folder
MESSAGE( STATUS "Include directory: ${INC_DIR}")
target_include_directories ( ${TARGET_PROJECT_NAME} PUBLIC ${INC_DIR} )
target_include_directories ( ${TARGET_PROJECT_NAME} PUBLIC ${SRC_DIR} )

#
# Library directories
#
set (LIB_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)
SET(SYS_LIB_DIR /usr/lib/${TARGET_ARCH})
link_directories(${LIB_DIR} ${SYSTEM_LIB_DIR} )
MESSAGE( STATUS "Project libraries directory: ${LIB_DIR}")
MESSAGE( STATUS "System libraries directory: ${SYS_LIB_DIR}")

target_link_libraries(${TARGET_PROJECT_NAME} -Wl,--no-undefined)
target_link_libraries(${TARGET_PROJECT_NAME} 
${LIB_DIR}/nanotec/${TARGET_ARCH}/libnanolib.so
${LIB_DIR}/commDatalayer/${TARGET_ARCH}/libcomm_datalayer.so
${LIB_DIR}/commDatalayer/${TARGET_ARCH}/libzmq.so
${SYS_LIB_DIR}/libpthread.so.0
${SYS_LIB_DIR}/libssl.so
${SYS_LIB_DIR}/libcrypto.so
)

#
# Install instructions
#
set(INS_LIB "${LIB_DIR}/nanotec/${TARGET_ARCH}\;${LIB_DIR}/commDatalayer/${TARGET_ARCH}/")

set_target_properties(${TARGET_PROJECT_NAME} PROPERTIES
    INSTALL_RPATH ${INS_LIB}
    INSTALL_RPATH_USE_LINK_PATH TRUE)

MESSAGE( STATUS "Install library path: ${INS_LIB}")

install( TARGETS ${TARGET_PROJECT_NAME}
    RUNTIME 
        DESTINATION ${CMAKE_CURRENT_LIST_DIR}/install
  ) 


