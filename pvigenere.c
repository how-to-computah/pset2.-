#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define K_INT atoi(argv[argc - 1])
#define K_CHAR argv[argc - 1]
#define ASCII 65

char *get_msg();

int main(int argc, string argv[])
{
    char *msg_ptr = 0;
    int i, c, len, key_len = 0;
    int key_int = K_INT;
    char* key_char = K_CHAR;

    key_len = strlen(K_CHAR);
    for (i = 0; i < key_len; i++)
    {
        printf("%c",*(key_char + i));
    }

// We gots no key, get outta here!!
    if (argv[1] == NULL)
    {
        exit(1);
    }
    // Get message to be encrypted from user.
    msg_ptr = get_msg();
    len = strlen(msg_ptr);

    printf("ciphertext: ");

    for (i = 0; i < len; i++)
    {
        // Are you a letter?
        if (isalpha(*(msg_ptr + i)))
        {
            if (islower(*(msg_ptr + i)))
                // A = 65 ; Z = 90
            {
                toupper(*(msg_ptr +i));
                //do something.

            }
            else
                // a = 97 ; z = 122
            {
                //do something.
            }
            // wrap em.
            if (((*(msg_ptr + i) - ASCII) + key_int) > 26)
            {
                // c = (p + k) % 26
               c = ((((*(msg_ptr + i) - ASCII) + key_int) % 26) + ASCII);

                printf("%c", c);
            }
            // just add to em.
            else
            {
                printf("%c", (*(msg_ptr + i) + key_int));
            }

        }
        // Guess not, we won't mess with you.
        else
        {
            printf("%c", (*(msg_ptr + i)));
        }

    }

    printf("\n");

    return 0;
}

char *get_msg()
{
    static char *plain_text = "";
    int len = 0;

    plain_text = get_string("plaintext:  ");

    len = strlen(plain_text);

    return plain_text;
}
