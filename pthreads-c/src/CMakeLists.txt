cmake_minimum_required(VERSION 3.13)



###############################################################################
## LIBRARY-PROJECT
## name and version
###############################################################################
project(pthreads-c LANGUAGES C)



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



###############################################################################
## TARGET
## create target and add include path
###############################################################################
set(PTHREAD_API
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sched.h
    ${CMAKE_CURRENT_SOURCE_DIR}/semaphore.h)

set(PTHREAD_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/attr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/barrier.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cancel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cleanup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/condvar.c
    ${CMAKE_CURRENT_SOURCE_DIR}/create.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/autostatic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/errno.c
    ${CMAKE_CURRENT_SOURCE_DIR}/exit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fork.c
    ${CMAKE_CURRENT_SOURCE_DIR}/global.c
    ${CMAKE_CURRENT_SOURCE_DIR}/misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nonportable.c
    ${CMAKE_CURRENT_SOURCE_DIR}/private.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rwlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched.c
    ${CMAKE_CURRENT_SOURCE_DIR}/semaphore.c
    ${CMAKE_CURRENT_SOURCE_DIR}/signal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/spin.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sync.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tsd.c)
set(PTHREAD_RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/version.rc)
set(PTHREAD_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/need_errno.h)

set(PTHREAD_STATIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getdetachstate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setdetachstate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getstackaddr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setstackaddr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getstacksize.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setstacksize.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getscope.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setscope.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setschedpolicy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getschedpolicy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setschedparam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getschedparam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_setinheritsched.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_attr_getinheritsched.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrier_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrier_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrier_wait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrierattr_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrierattr_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrierattr_setpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_barrierattr_getpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_setcancelstate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_setcanceltype.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_testcancel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cancel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cleanup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_condattr_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_condattr_getpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_condattr_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_condattr_setpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cond_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cond_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cond_signal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_cond_wait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/create.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/autostatic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/errno.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_exit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fork.c
    ${CMAKE_CURRENT_SOURCE_DIR}/global.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_getpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_setpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_settype.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_gettype.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_setrobust.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_getrobust.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_timedlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_unlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_trylock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutex_consistent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_setkind_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_mutexattr_getkind_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_getw32threadhandle_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_getunique_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_delay_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_num_processors_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_win32_attach_detach_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_equal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_getconcurrency.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_once.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_self.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_setconcurrency.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlockattr_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlockattr_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlockattr_getpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlockattr_setpshared.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_rdlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_wrlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_unlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_tryrdlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_rwlock_trywrlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_setschedparam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_getschedparam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_timechange_handler_np.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_is_attr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_processInitialize.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_processTerminate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_threadStart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_threadDestroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_tkAssocCreate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_tkAssocDestroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_callUserDestroyRoutines.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_timespec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_throw.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_getprocessors.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_calloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_new.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_reuse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_rwlock_check_need_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_cond_check_need_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_mutex_check_need_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_semwait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_relmillisecs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_MCS_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched_get_priority_max.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched_get_priority_min.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched_setscheduler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched_getscheduler.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sched_yield.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_trywait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_timedwait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_wait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_post.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_post_multiple.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_getvalue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_open.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_close.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem_unlink.c
    ${CMAKE_CURRENT_SOURCE_DIR}/signal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_kill.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ptw32_spinlock_check_need_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_spin_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_spin_destroy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_spin_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_spin_unlock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_spin_trylock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_detach.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_join.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_key_create.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_key_delete.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_setspecific.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pthread_getspecific.c
    ${CMAKE_CURRENT_SOURCE_DIR}/w32_CancelableWait.c)

if(CPTHREADS_BUILD_STATIC)
    add_definitions(-DPTW32_STATIC_LIB)
    set(PTHREADS_LIBTYPE STATIC)
else()
    set(PTHREADS_LIBTYPE SHARED)
endif()

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    add_definitions( -DPTW32_ARCH="x64" )
else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    add_definitions( -DPTW32_ARCH="x86" )
endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

if(MSVC)
    add_definitions(/DPTW32_RC_MSC)
    set(PTHREADS_COMPILER V)
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(PTHREADS_COMPILER G)
else()
    message("WARNING: pthreads-win32 doesn't recognize your compiler!")
endif()

if(PTHREADS_BUILD_CPP)
    set(PTHREADS_EXCEPTION_SCHEME CE)
    add_definitions(/__CLEANUP_CXX)
    message("Building pthreads-win32 with C++ exception handling.")
elseif(PTHREADS_BUILD_SEH)
    set(PTHREADS_EXCEPTION_SCHEME SE)
    add_definitions(/__CLEANUP_SEH)
    message("Building pthreads-win32 with Microsoft SEH exception handling.")
else()
    # defaults to C - setjmp/longjmp
    set(PTHREADS_EXCEPTION_SCHEME C)
    message("Building pthreads-win32 with C setjmp/longjmp (default/recommended exception scheme).")
endif()


set(CMAKE_DEBUG_POSTFIX d)
add_definitions(/DHAVE_PTW32_CONFIG_H)

if (NOT TARGET ${PROJECT_NAME})
    add_library(
        ${PROJECT_NAME} ${PTHREADS_LIBTYPE}
        ${PTHREAD_SOURCES}
#        ${PTHREAD_STATIC_SOURCES}
        ${PTHREAD_API}
        ${PTHREAD_RESOURCES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
