#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MSG_LEN strlen(plain_text);
#define KEY argv[argc - 1]
//ci=(pi+k)mod26

char *get_msg();

int main(int argc, string argv[])
{
    char *msg_ptr = 0;
    int i = 0;
    int len = 0;

    // Get message to be encrypted from user.
    msg_ptr = get_msg();
    len = strlen(msg_ptr);

    char p_text [len];

    for (i = 0; i < len; i++)
    {
        p_text [i] = *(msg_ptr + i);
    }

    for (i = 0; i < len; i++)
    {
        printf("%c", p_text[i]);
    }

    printf("\n");
    printf("%d\n", argc);

    return 0;
}

char *get_msg()
{
    static char *plain_text = "";
    int len = 0;

    plain_text = get_string("plaintext: ");

    len = strlen(plain_text);

    return plain_text;
}
