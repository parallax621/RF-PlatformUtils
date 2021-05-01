#include "memory_platform.h"

memory_platform_dependent_methods_t memory_platform;
void init_memory_platform(memory_platform_dependent_methods_t* methods)
{
    memory_platform = *methods;
}
