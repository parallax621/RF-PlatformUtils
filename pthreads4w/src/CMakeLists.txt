cmake_minimum_required(VERSION 3.13)



###############################################################################
## LIBRARY-PROJECT
## name and version
###############################################################################
project(pthreads4w LANGUAGES C)



###############################################################################
## SETTINGS
## basic project settings before use
###############################################################################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_C_STANDARD 99)
# Enabling export of all symbols to create a dynamic library
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# creating output directory architecture in accordance with GNU guidelines
set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR}/lib")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING "Choose the type of build, options are: Debug, Release, or MinSizeRel." FORCE)
    message(STATUS "No build type specified, defaulting to MinSizeRel.")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include (get_version)

message(STATUS "Generator ......... ${CMAKE_GENERATOR}")
message(STATUS "Build Type ........ ${CMAKE_BUILD_TYPE}")
message(STATUS "Version ........... ${PTHREADS4W_VERSION}")

set(PTW32_VER ${PROJECT_VERSION_MAJOR}${EXTRAVERSION})
set(CMAKE_DEBUG_POSTFIX d)

# Update filename with proper version info
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.rc.in ${CMAKE_CURRENT_BINARY_DIR}/version.rc @ONLY)


# Uncomment this if config.h defines RETAIN_WSALASTERROR
#set(XLIBS wsock32.lib)


include_directories(.)



###############################################################################
## TARGET
## create target and add include path
###############################################################################
include (target_arch)

get_target_arch(TARGET_ARCH)

if(${TARGET_ARCH} STREQUAL "ARM")
    add_definitions(-D__PTW32_ARCHARM -D_ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE=1)
elseif(${TARGET_ARCH} STREQUAL "ARM64")
    add_definitions(-D__PTW32_ARCHARM64 -D_ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE=1)
elseif(${TARGET_ARCH} STREQUAL "x86_64")
    add_definitions(-D__PTW32_ARCHAMD64)
elseif(${TARGET_ARCH} STREQUAL "x86")
    add_definitions(-D__PTW32_ARCHX86)
elseif(${TARGET_ARCH} STREQUAL "x64")
    add_definitions(-D__PTW32_ARCHX64)
else()
    MESSAGE(ERROR "\"${TARGET_ARCH}\" not supported in version.rc")
endif()
message(STATUS "Target ............ ${TARGET_ARCH}")

if(MSVC)
    message(STATUS "MSVC Version ...... ${MSVC_VERSION}")
endif()

add_definitions(-D__PTW32_BUILD_INLINED)

if(MSVC)

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /errorReport:none /nologo ")

    # C++ Exceptions
    # (Note: If you are using Microsoft VC++6.0, the library needs to be built
    # with /EHa instead of /EHs or else cancellation won't work properly.)
    if(MSVC_VERSION EQUAL 1200)
        set(VCEFLAGS  "/EHa /TP ")
    else()
        set(VCEFLAGS  "/EHs /TP ")
    endif()

    add_definitions(-DHAVE_CONFIG_H -D__PTW32_RC_MSC)

endif()

file (GLOB_RECURSE H_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

macro(shared_lib def)
    set(targ ${PROJECT_NAME})
    add_library(${targ} SHARED pthread.c
        ${CMAKE_CURRENT_BINARY_DIR}/version.rc ${H_FILES})
    target_compile_definitions(${targ} PUBLIC "-D${def}")
    target_include_directories(${targ} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
endmacro()

macro(static_lib def)
    set(targ lib${PROJECT_NAME})
    add_library(${targ} STATIC pthread.c
        ${H_FILES})
    target_compile_definitions(${targ} PUBLIC "-D${def}" -D__PTW32_STATIC_LIB)
    target_include_directories(${targ} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
endmacro()

if(PTHREADS4W_BUILD_STATIC)
    static_lib (__PTW32_CLEANUP_C)
else()
    shared_lib (__PTW32_CLEANUP_C )
endif()


#################################
# Test                          #
#################################
#include (CTest)

#if(NOT CMAKE_CROSSCOMPILING AND BUILD_TESTING)
#    add_subdirectory(tests)
#endif()
