#include <stdio.h>
#include <string.h>


int main()
{

    char key_str [] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

    for (char *string = *(&key_str); *string; ++string)
    {
        printf("%s\n", string);
    }
    return 0;
}
