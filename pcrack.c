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

    //If you want it the hard way.
    char *hashed_pw = *hash(*(&argv[1]));


    //hashed_pw = *(&argv[1]);

    printf("%s\n", hashed_pw);

return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


char **hash(char *hash_DES[])
{
    for (char **arg = hash_DES; *arg; ++arg)
    {
        int i;
        for (i = 0; i < strlen(*arg); i++)
        {
            hash_DES[i] = (*arg + i);
        }
    }
    return hash_DES;
}
