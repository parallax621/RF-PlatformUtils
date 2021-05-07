cmake_minimum_required(VERSION 3.13)



###############################################################################
## PROJECT
## name and version
###############################################################################
project(RF-PlatformUtils)



###############################################################################
## SETTINGS
## basic project settings before use
###############################################################################
# If this project is used as a submodule, the variable should be overridden
# to "OFF" in the top-level application (to disable forced cache rewriting)
option(${PARENT}_SUBMODULE_CACHE_OVERWRITE "Enable forced cache rewriting" ON)
if (${PARENT}_SUBMODULE_CACHE_OVERWRITE)
    SET(REWRITE_FORCE "FORCE")
else()
    SET(REWRITE_FORCE "")
endif()



###############################################################################
## CONFIGURATION
## project configuration
###############################################################################
# platform_methods
SET(${PARENT}_PLATFORM_METHODS              ON CACHE BOOL  "" ${REWRITE_FORCE})

# endian_conv
SET(${PARENT}_ENDIAN_CONV   		    ON CACHE BOOL  "" ${REWRITE_FORCE})

# custom_vector
SET(${PARENT}_CUSTOM_VECTOR                 ON CACHE BOOL  "" ${REWRITE_FORCE})

# custom_string
SET(${PARENT}_CUSTOM_STRING                 ON CACHE BOOL  "" ${REWRITE_FORCE})

# pthreads-c
SET(${PARENT}_PTHREADS4W                    ON CACHE BOOL  "" ${REWRITE_FORCE})

# getopt
SET(${PARENT}_GETOPT                        ON CACHE BOOL  "" ${REWRITE_FORCE})

# sandbox
SET(${PARENT}_SANDBOX                       ON CACHE BOOL  "" ${REWRITE_FORCE})


###############################################################################
## INCLUDING SUBDIRECTORIES
## Adding subdirectories according to the configuration
###############################################################################
# platform_methods
if (${PARENT}_PLATFORM_METHODS)
    add_subdirectory(platform_methods)
endif()

# endian_conv
if (${PARENT}_ENDIAN_CONV)
    add_subdirectory(endian_conv)
endif()

# custom_vector
if (${PARENT}_CUSTOM_VECTOR)
    add_subdirectory(custom_vector)
endif()

# custom_string
if (${PARENT}_CUSTOM_STRING)
    add_subdirectory(custom_string)
endif()

# pthreads-c
if (${PARENT}_PTHREADS4W)
    SET(PTHREADS4W_BUILD_STATIC TRUE)
    add_subdirectory(pthreads4w)
endif()

# getopt
if (${PARENT}_GETOPT)
    add_subdirectory(getopt)
endif()

# sandbox
if (${PARENT}_SANDBOX)
    add_subdirectory(sandbox)
endif()
