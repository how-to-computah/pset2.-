#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define _XOPEN_SOURCE

char *force(char *hashed_pw, char *force_hash, char salt);
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
    char *force_hash;
    char *key = 0;
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
    /*key = force();
    char *force_hash = crypt(key, salt);

    printf("%s\n", user_hash);
    printf("%s\n", salt);
    printf("%s\n", hashed_pw);
    */

    char *new_salt = *(&salt);

    force_hash = crypt("rofl", "50");
    printf("%s\n", force_hash);
    key = force(hashed_pw, force_hash, *new_salt);

    /*for(int y = 0; y < 1024 ; y ++)
    {
        key = force();

        force_hash = crypt(key, salt);

        if (strcmp(hashed_pw, force_hash) == 0)
        {
            printf("%s\n", key);

            break;
        }
    }

    printf("%s", key);

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
            if (index == 2)
            {
                col += 2;
                strcpy(hash, col);

                break;
            }
            else
            {
                for (int i = 0; i < 2; ++col, i++)
                {
                    hash[i] = (*col);
                }
                break;
            }

    }
    return hash;
}

char *force(char *hashed_pw, char *force_hash, char salt)
{
    const char *key_str = "abcdefghijklmnopqrstuvwxyz\
                           ABCDEFGHIJKLMNOPQRSTUVWXYZ\
                           0123456789./";
    static char key [6] = {};
    static int i, j, k, l, m;

    for (; *key_str; ++key_str, i++)
    {
        key[0] = *(key_str);

        if (i == strlen(key_str))
        {
            key[1] = *(key_str + j);
            j++;
        }
        if (j == strlen(key_str))
        {
            key[2] = *(key_str + k);
            k++;
        }
        if (k == strlen(key_str))
        {
            key[3] = *(key_str + l);
            l++;
        }
        if (l == strlen(key_str))
        {
            key[4] = *(key_str + m);
            m++;
        }

        force_hash = crypt(key, &salt);

        if (strcmp(hashed_pw, force_hash) == 0)
        {
            printf("%s\n", key);

            break;
        }



    }
    return key;
    //continue;
}
