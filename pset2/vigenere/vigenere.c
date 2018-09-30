#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string encrypt_vigenere(string, string);

int main(int argc, string argv[])
{
    // checking commanline arguments
    if (argc != 2)
    {
	printf("Usage: ./vigenere k\n");
	return 1;
    }

    string keyword = argv[1];
    // checking if keyword is alphabetical
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
	if (!isalpha(keyword[i]))
	{
	    printf("Usage: ./vigenere k\n");
	    return 1;
	}
    }

    // get plaintext and encrypt it
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt_vigenere(plaintext, keyword);

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}

string encrypt_vigenere(string plaintext, string keyword)
{

    // turn keyword into an array on integer keys
    int keys_len = strlen(keyword);

    char upper_keyword[keys_len];
    for (int i = 0; i < keys_len; i++)
    {
	if (islower(keyword[i]))
	{
	    upper_keyword[i] = toupper(keyword[i]);
	}
	else
	{
	    upper_keyword[i] = keyword[i];
	}
    }

    int keys[keys_len];
    for (int i = 0; i < keys_len; i++)
    {
	keys[i] = upper_keyword[i] - 'A';
    }


    // compute ciphertext
    char *ciphertext = malloc((strlen(plaintext) + 1) * sizeof(char));
    for (int i = 0, n = strlen(plaintext), j = 0; i < n; i++)
    {
	if (isalpha(plaintext[i]) && isupper(plaintext[i]))
	{
	    ciphertext[i] = ((plaintext[i] - 'A' + keys[j % keys_len]) % 26) + 'A';
	    j++;
	}
	else if (isalpha(plaintext[i]) && islower(plaintext[i]))
	{
	    ciphertext[i] = ((plaintext[i] - 'a' + keys[j % keys_len]) % 26) +'a';
	    j++;
	}
	else
	{
	    ciphertext[i] = plaintext[i];
	}
    }

    return ciphertext;
}
