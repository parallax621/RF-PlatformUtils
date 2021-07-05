#include "iostream_platform.h"
#include "memory_platform.h"

#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#else

#endif

pthread_mutex_t print_mutex;
iostream_platform_dependent_methods_t iostream_platform;
void init_iostream_platform(iostream_platform_dependent_methods_t* methods)
{
    pthread_mutex_init(&print_mutex, NULL);
    iostream_platform = *methods;
    freopen("error.txt", "w", stderr);
}

void COLOR_PRINT(const char* s, int color)
{
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
#else

#endif
}
