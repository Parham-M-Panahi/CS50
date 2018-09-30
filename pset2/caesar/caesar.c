#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string encrypt_caesar(string, int);

int main(int argc, string argv[])
{
    // check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int key = atoi(argv[1]);

    // get the plaintext from user
    string plaintext = get_string("plaintext: ");

    string ciphertext = encrypt_caesar(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}

// encrypts plaintext with caesar algorithm ci = (pi + k) mod 26
string encrypt_caesar(string plaintext, int key)
{
    // allocate ciphertext;
    char *ciphertext = malloc(strlen(plaintext) * sizeof(char));

    // compute the ciphertext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
	    ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }
	else if (isalpha(plaintext[i]) && islower(plaintext[i]))
	{
	    ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
	}
	else
	{
	    ciphertext[i] = plaintext[i];
	}
    }

    return ciphertext;
}
