#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define KEY atoi(argv[argc - 1])

char *get_msg();

int main(int argc, string argv[])
{
    char *msg_ptr = 0;
    int i, c, len = 0;
    int k = KEY;
    int ASCII_offset = 0;

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
            if (isupper(*(msg_ptr + i)))
                // A = 65 ; Z = 90
            {
                ASCII_offset = 64;
            }
            else
                // a = 97 ; z = 122
            {
                ASCII_offset = 96;
            }
            // wrap em.
            if (((*(msg_ptr + i) - ASCII_offset) + k) > 26)
            {
                // c = (p + k) % 26
                c = ((((*(msg_ptr + i) - ASCII_offset) + k) % 26) + ASCII_offset);

                printf("%c", c);
            }
            // just add to em.
            else
            {
                printf("%c", (*(msg_ptr + i) + k));
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
