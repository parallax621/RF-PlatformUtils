#ifndef IOSTREAM_PLATFORM_H
#define IOSTREAM_PLATFORM_H
#include "platform_types.h"
#include "pthread.h"

#if defined(linux) || defined(__linux) || defined(__linux__)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif

#define TRACE_LEVEL_SILENT -1
#define TRACE_LEVEL_CRITICAL 0
#define TRACE_LEVEL_ERROR 1
#define TRACE_LEVEL_WARNING 2
#define TRACE_LEVEL_INFO 3
#define TRACE_LEVEL_DEBUG 4

#define TRACE_FORMAT_SHORT 0
#define TRACE_FORMAT_LONG 1


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
#define CURRENT_TRACE_LEVEL TRACE_LEVEL_DEBUG

extern pthread_mutex_t print_mutex;


#ifndef NDEBUG
#define TRACE(lvl, trace_format, print_format, ... ) \
if (trace_format == TRACE_FORMAT_SHORT) \
{ TRACE_SHORT(lvl, print_format, __VA_ARGS__); } \
else { TRACE_LONG(lvl, print_format, __VA_ARGS__); }
#else
#define TRACE(lvl, trace_format, print_format, ... ) ((void)0)
#endif


#define TRACE_LONG(lvl, format, ... ) if (lvl <= CURRENT_TRACE_LEVEL) \
{ pthread_mutex_lock(&print_mutex); switch(lvl){ \
    case TRACE_LEVEL_CRITICAL: \
{   COLOR_PRINT ("[CRITICAL ] ", 4); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[---------] ", 4); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[---------] ", 4); \
    printf      ( "%s:%d\n\n", __FILENAME__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_ERROR: \
{   COLOR_PRINT ("[EXCEPTION] ", 12); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[---------] ", 12); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[---------] ", 12); \
    printf      ( "%s:%d\n\n", __FILENAME__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_WARNING: \
{   COLOR_PRINT ("[WARNING  ] ", 6); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[---------] ", 6); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[---------] ", 6); \
    printf      ( "%s:%d\n\n", __FILENAME__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_INFO: \
{   COLOR_PRINT ("[INFO     ] ", 9); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[---------] ", 9); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[---------] ", 9); \
    printf      ( "%s:%d\n\n", __FILENAME__, __LINE__ ); \
    break; } \
    case TRACE_LEVEL_DEBUG: \
{   COLOR_PRINT ("[DEBUG    ] ", 7); \
    printf      ( "" format, __VA_ARGS__ ); \
    COLOR_PRINT ("[---------] ", 7); \
    printf      ("%s()\n",  __FUNCTION__ ); \
    COLOR_PRINT ("[---------] ", 7); \
    printf      ( "%s:%d\n\n", __FILENAME__, __LINE__ ); \
    break; } \
    default: \
{   break; } \
} pthread_mutex_unlock(&print_mutex); \
}


#define TRACE_SHORT(lvl, format, ... ) if (lvl <= CURRENT_TRACE_LEVEL) \
{ pthread_mutex_lock(&print_mutex); switch(lvl){ \
    case TRACE_LEVEL_CRITICAL: \
{   COLOR_PRINT ("[CRITICAL ] ", 4); \
    printf      ( "" format, __VA_ARGS__ ); \
    break; } \
    case TRACE_LEVEL_ERROR: \
{   COLOR_PRINT ("[EXCEPTION] ", 12); \
    printf      ( "" format, __VA_ARGS__ ); \
    break; } \
    case TRACE_LEVEL_WARNING: \
{   COLOR_PRINT ("[WARNING  ] ", 6); \
    printf      ( "" format, __VA_ARGS__ ); \
    break; } \
    case TRACE_LEVEL_INFO: \
{   COLOR_PRINT ("[INFO     ] ", 9); \
    printf      ( "" format, __VA_ARGS__ ); \
    break; } \
    case TRACE_LEVEL_DEBUG: \
{   COLOR_PRINT ("[DEBUG    ] ", 7); \
    printf      ( "" format, __VA_ARGS__ ); \
    break; } \
    default: \
{   break; } \
} pthread_mutex_unlock(&print_mutex); \
};


/**
 * @brief Method for outputting debugging information
 *
 * @param msg Pointer to a string containing the text to be output
 * @param ...(additional arguments) Depending on the format string, the function
 * may expect a sequence of additional arguments
 *
 * @return On success, the total number of characters written is returned.
 */
typedef rfInt(*trace_info_t)(const rfChar* msg, ...);


/**
 * @brief Method for outputting alert information
 *
 * @param msg Pointer to a string containing the text to be output
 * @param ...(additional arguments) Depending on the format string, the function
 * may expect a sequence of additional arguments
 *
 * @return On success, the total number of characters written is returned.
 */
typedef rfInt(*trace_warning_t)(const rfChar* msg, ...);


/**
 * @brief Method for outputting error information
 *
 * @param msg Pointer to a string containing the text to be output
 * @param ...(additional arguments) Depending on the format string, the function
 * may expect a sequence of additional arguments
 *
 * @return On success, the total number of characters written is returned.
 */
typedef rfInt(*trace_error_t)(const rfChar* msg, ...);

/**
 * @brief Structure with user-provided iostream platform-specific methods
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
