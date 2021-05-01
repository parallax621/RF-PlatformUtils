#ifndef CUSTOM_STRING_C
#define CUSTOM_STRING_C
#include "custom_string.h"


rfInt rf_strcmp(const char* string1, const char* string2 )
{
    for (rfUint32 i = 0; ; i++)
    {
        if (string1[i] == '\0')
        {
            return 0;
        }

        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

    }
}

rfSize rf_strlen(const char *s) {
    if (s != NULL)
    {
        rfSize i;
        for (i = 0; s[i] != '\0'; i++);
        return i;
    }else
        return 0;
}

#endif // CUSTOM_STRING_C
