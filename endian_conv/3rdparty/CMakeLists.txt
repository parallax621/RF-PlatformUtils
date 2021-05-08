cmake_minimum_required(VERSION 3.13)



###############################################################################
## 3RD-PARTY
## dependencies for the project
###############################################################################
project(3rdparty LANGUAGES C)



###############################################################################
## INCLUDING SUBDIRECTORIES
## Adding subdirectories according to the 3rd-party configuration
###############################################################################
# set platform_methods path variable
set(PLATFORM_METHODS_DIR "../../platform_methods")
# add subdirectory of platform_methods lib
add_subdirectory(${PLATFORM_METHODS_DIR} platform_methods)
