#include <stdio.h>
#include <cs50.h>
#include <string.h>

#include "helpers.h"

int main(void)
{
    string s = get_string("input: ");
    printf("%i\n", frequency(s));
    return 0;
}
