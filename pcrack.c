#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _XOPEN_SOURCE

char *parsley();

/*Get the command line arugment.
parse the string.
char *crypt (const char *key, const char *salt);
    Upon successful completion, crypt() returns a pointer to the encoded string.
    The first two characters of the returned value are those of the salt argument.
    Otherwise it returns a null pointer and sets errno to indicate the error.
brute force up to a length of 5 or until the hash matches the one provide with the key you passed to it.
*/

int main(int argc, char *argv[])
{
    char salt [3];
    char *user_hash;
    int index = 0;
    
    // Check to see if we even need to run.
    if ((argc - 1) > 1 || (argv[1] == NULL))
    {
        printf("Give me a hashed password plz. \n");
        exit(1);
    }
    // Get the hashed password from argv[1]
    char *hashed_pw = *(&argv[1]);

    // Don't ever do this again.
    strncpy(salt, (user_hash = parsley(hashed_pw, index)), 2);
    salt[2] = '\0'; // strncpy doen't add the NULL terminator.
    
    //remove the salt from the hash.
    index = 2;
    user_hash = parsley(hashed_pw, index);

    printf("%s\n", user_hash);
    printf("%s\n", salt);
    /*
    for(; ;)
    {
        if (strcmp(user_hash, force_hash) == 0)
        {
            printf("%s\n", force_hash);

            break;
        }
    }
    */
return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char *parsley(char *cmd_line, int index)
{
    static char hash [16];
    for (char *col = cmd_line; *col; ++col)
    {
        if (*col == ':')
        {
            // index past the colon or salt.
            ++col;
            if (index == 2)
            {
                col += 2;
            }
            for (int i = 0; *col; ++col, i++)
            {
                hash[i] = (*col);
            }
            break;
        }
    }
    return hash;
}
