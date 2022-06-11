#include "iostream_platform.h"
#include "memory_platform.h"


#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#endif

pthread_mutex_t print_mutex;
iostream_platform_dependent_methods_t iostream_platform;
void init_iostream_platform(iostream_platform_dependent_methods_t* methods)
{
    pthread_mutex_init(&print_mutex, NULL);
    iostream_platform = *methods;
    // freopen("error.txt", "w", stderr);
}

void COLOR_PRINT(const char* s, int color)
{
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf("%s",s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
#else
    switch (color) {
    case 4:
        printf("\033[;31m%s\033[0m", s);
        break;
    case 12:
        printf("\033[;31m%s\033[0m", s);
        break;
    case 6:
        printf("\033[;33m%s\033[0m", s);
        break;
    case 9:
        printf("\033[;37m%s\033[0m", s);
        break;
    case 7:
        printf("\033[;37m%s\033[0m", s);
        break;
    default:
        printf("%s",s);
        break;
    }
#endif
}
