//encrypts user input with key word provided at program call.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check for proper number of arguments
    if (argc != 2)
    {
        printf("Must enter one word for the key.\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);

    //Check for proper key syntax.
    for (int i = 0; i < keylen; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must contain only letters.\n");
            return 1;
        }
    }

    //Formatting key argument for proper encryption.
    for (int j = 0; j < keylen; j++)
    {
        key[j] = tolower(key[j]);
        key[j] -= 97;
    }

    //Prompt user for text to encrypt
    string plaintext = 0;
    do
    {
        plaintext = get_string("plaintext: ");
    }
    while (plaintext == 0);
    int k = 0;

    //Encrypting user input one letter at a time.
    for (int l = 0; l < strlen(plaintext); l++)
    {
        if (isalpha(plaintext[l]))
        {
            //Magic number 65 is for A in ASCII.  26 is for number of letters in the alphabet.
            if (isupper(plaintext[l]))
            {
                plaintext[l] = (plaintext[l] + key[k] - 65) % 26 + 65;
                k++;
            }

            //Magic number 97 is for a in ASCII.  26 is for number of letters in the alphabet.
            else if (islower(plaintext[l]))
            {
                plaintext[l] = (plaintext[l] + key[k] - 97) % 26 + 97;
                k++;
            }
            if (k == keylen)
            {
                k = 0;
            }
        }
    }

    //Return ciphertext to user.
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
