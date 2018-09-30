#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>

#define _XOPEN_SOURCE

string crack(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
	printf("Usage: ./crack hash\n");
	return 1;
    }

    string hash = argv[1];
    string key = crack(hash);

    printf("%s\n", key);

    free(key);

    return 0;
}

string crack(string hash)
{
    // get salt
    char salt[2];
    salt[0] = hash[0];
    salt[1] = hash[1];

    char *key = malloc(6 * sizeof(char));
    string crypt_result;
    int not_cracked = 1;

    while (not_cracked)
    {
	// generate next key
	// TODO

	// test key
        crypt_result = crypt(key, salt);
	not_cracked = strcpm(crypt_result, hash);
    }

    return key;
}
