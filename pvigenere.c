#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define K_CHAR argv[argc - 1]
#define U_ASCII 65
#define L_ASCII 97

bool why_no(char *argv[]);
int why_function();
int why_another();
int main(int argc, char* argv[])
{
    int i, j, meaningful_variable, key_int, ascii_int;
    char* key_char = K_CHAR;
    char* plain_text = 0;
    bool number;

    number = why_no(&argv[1]);

    if ((argc - 1) > 1 || (argv[1] == NULL) || number == true)
    {
        printf("We dont take kindly to that 'round here.\n");
        exit(0);
    }
    // Get message to be encrypted from user.
    plain_text = get_string("plaintext:  ");

    printf("ciphertext: ");

//----------------------------------------------------------------------------------------------------------------------------------
    for (i = 0, j = 0; i < strlen(plain_text); i++, j++)
    {
         //End of key index, reset.
        if(j == strlen(key_char))
        {
            j = 0;
        }

        meaningful_variable = *(plain_text + i);

        key_int = why_function(j, key_char);

        ascii_int = why_another(meaningful_variable);

        // Are you a letter?
        if (isalpha(meaningful_variable))
        {
            meaningful_variable = (((meaningful_variable - ascii_int) + key_int) % 26) + ascii_int;
            plain_text[i] = meaningful_variable;
        }
        else
        {
            //Not a letter, keep the key index the same for next iteration.
            j -= 1;
        }
    }

    printf("%s\n", plain_text);

    return 0;
}

int why_function(int j, char* key_char)
{
    int got_key;
    //Get the right integer value dependent on the key case.
    if (islower(*(key_char +j)))
    {
        got_key = *(key_char + j)- L_ASCII;
    }
    else
    {
        got_key = *(key_char + j)- U_ASCII;
    }

    return got_key;

}

int why_another(meaningful_variable)
{
    int good_job;
    //Tell me I did a good job.
    if (islower(meaningful_variable))
    {
         good_job = L_ASCII;
    }
    else
    {
        good_job = U_ASCII;
    }

    return good_job;
}

bool why_no(char *argv[])
{
    for (char **arg = argv; *arg; ++arg)
    { // for each arg
        for (char *x = *arg; *x; ++x)
        { // for each character
            if (isdigit(*x))
            {
            return true;
            }
        }
    }
    return false;
}
