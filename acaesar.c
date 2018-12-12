//Simple encyption.  When program is called integer offsets all alphabetical characters entered by that value.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //ci=(pi+k)mod26
    if (argc != 2)
    {
        printf("Must enter one integer for the key.\n");
        return 1;
    }
    //Integer value to offset character value by.
    int key = atoi(argv[1]);
    string plaintext = 0;
    do
    {
        //Get plaintext to offset from user.
        plaintext = get_string("plaintext: ");
    }
    while (plaintext == 0);

    //Checks each value if it's an alphabetical character. If it is, it offsets it by integer amount.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] + key - 65) % 26 + 65;
            }

            else if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] + key - 97) % 26 + 97;
            }
        }
    }

    /*for each character in the string
    *    if alphabetic isalpha()
    *      preserve case isupper()
    *      shift plaintext character by key
    *print ciphertext
    */

    //return "plaintext" to the user which is now ciphertext.
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
