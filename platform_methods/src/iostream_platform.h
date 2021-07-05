#ifndef IOSTREAM_PLATFORM_H
#define IOSTREAM_PLATFORM_H
#include "platform_types.h"
#include "pthread.h"

#define TRACE_LEVEL_SILENT -1
#define TRACE_LEVEL_CRITICAL 0
#define TRACE_LEVEL_ERROR 1
#define TRACE_LEVEL_WARNING 2
#define TRACE_LEVEL_INFO 3
#define TRACE_LEVEL_DEBUG 4

#ifdef _WIN32
/*
 * 0 = black 8 = gray
 * 1 = blue 9 = light blue
 * 2 = green 10 = light green
 * 3 = light green 11 = light green
 * 4 = red 12 = light red
 * 5 = purple 13 = light purple
 * 6 = yellow 14 = light yellow
 * 7 = white 15 = bright white
 */
void COLOR_PRINT(const char* s, int color);
#else
void COLOR_PRINT(const char* s, int color);
#endif

// select trace level for debug
#define CURRENT_TRACE_LEVEL TRACE_LEVEL_WARNING

extern pthread_mutex_t print_mutex;

#if defined NDEBUG
    #define TRACE( format, lvl, ... )
#else
#define TRACE(lvl, format, ... ) if (lvl <= CURRENT_TRACE_LEVEL) \
{ pthread_mutex_lock(&print_mutex); switch(lvl){ \
    case TRACE_LEVEL_CRITICAL: \
{   COLOR_PRINT ("[CRITICAL] ", 4); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[--------] ", 4); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[--------] ", 4); \
    printf      ( "%s:%d\n\n", __FILE__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_ERROR: \
{   COLOR_PRINT ("[ERROR   ] ", 12); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[--------] ", 12); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[--------] ", 12); \
    printf      ( "%s:%d\n\n", __FILE__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_WARNING: \
{   COLOR_PRINT ("[WARNING ] ", 6); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[--------] ", 6); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[--------] ", 6); \
    printf      ( "%s:%d\n\n", __FILE__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_INFO: \
{   COLOR_PRINT ("[INFO    ] ", 9); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[--------] ", 9); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[--------] ", 9); \
    printf      ( "%s:%d\n\n", __FILE__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_DEBUG: \
{   COLOR_PRINT ("[DEBUG   ] ", 7); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[--------] ", 7); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[--------] ", 7); \
    printf      ( "%s:%d\n\n", __FILE__, __LINE__ ); \
    break; } \
    default: \
{   break; } \
} pthread_mutex_unlock(&print_mutex); \
}
#endif

/** @brief Method for outputting debugging information
 */
typedef rfInt(*trace_info_t)(const rfChar* msg, ...);


/** @brief Method for outputting alert information
 */
typedef rfInt(*trace_warning_t)(const rfChar* msg, ...);


/** @brief Method for outputting error information
 */
typedef rfInt(*trace_error_t)(const rfChar* msg, ...);

/** @brief Structure with user-provided platform-specific methods
 */
typedef struct
{
    trace_info_t trace_info;
    trace_warning_t trace_warning;
    trace_error_t trace_error;
}iostream_platform_dependent_methods_t;
extern iostream_platform_dependent_methods_t iostream_platform;

/**
 * @brief init_iostream_platform - function for init iostream
 * @param methods
 */
void init_iostream_platform(iostream_platform_dependent_methods_t* methods);


#endif //IOSTREAM_PLATFORM_H
