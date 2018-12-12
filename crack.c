#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _XOPEN_SOURCE

char **hash();

int main(int argc, char *argv[])
{

    // Check to see if we even need to run.
    if ((argc - 1) > 1 || (argv[1] == NULL))
    {
        printf("Give me a hashed password plz. \n");
        exit(1);
    }
    // Get the hashed password from argv[1]
    char *hashed_pw = *(&argv[1]);

    printf("%s\n", hashed_pw);

return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char **hash(char *hash_MD5[])
{
    for (char **arg = hash_MD5; *arg; ++arg)
    {
        // for argv[1]
        //for (x = 0; x < )
        int i;
        //for (char *x = *arg, i = 0; *x; ++x, i++)
        for (i = 0; i < strlen(*arg); i++)
        {
            hash_MD5[i] = (*arg + i);
        }
    }
    return hash_MD5;
}
