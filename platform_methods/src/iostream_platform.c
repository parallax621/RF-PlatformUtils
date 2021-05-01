#include "iostream_platform.h"
#include "memory_platform.h"

#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#else

#endif

iostream_platform_dependent_methods_t iostream_platform;
void init_iostream_platform(iostream_platform_dependent_methods_t* methods)
{
    iostream_platform = *methods;
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
