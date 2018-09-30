#include <stdio.h>
#include <cs50.h>

#define MAX_DIGITS 16

int isvalid_luhn(int *);
int isamex(int *);
int isvisa(int *);
int ismaster_card(int *);
int *get_digits(long long);
int sum_digits(int *, int);
int *array_init(int);
void array_kill(int *);

// prompts for a credit card number and checks for crecit card validity and credit card company
int main(void)
{
    // get credit card number
    long long number;
    do
    {
	number = get_long_long("Number: ");
    }while (number <= 0);

    // turn input number to an array of digits
    int *digits = get_digits(number);

    // check for credit card validity
    if (isvalid_luhn(digits) == 1)
    {
	// check for credit card models
	if (isamex(digits) == 1)
	{
	    printf("AMEX\n");
	}
	else if (isvisa(digits) == 1)
	{
	    printf("VISA\n");
	}
	else if (ismaster_card(digits) == 1)
	{
	    printf("MASTERCARD\n");
	}
	else
	{
	    printf("VALID\n");
	}
    }
    else
    {
	printf("INVALID\n");
    }

    array_kill(digits);

    return 0;
}

// checks for luhn validity on credit card digits return 1 on succsess
int isvalid_luhn(int digits[])
{
    int luhn_sum = 0;

    // compute luhn sum
    for (int i = 0; i < MAX_DIGITS; i++)
    {
	if (i % 2 == 1)
	{
	    int *temp = get_digits(2 * digits[i]);
	    luhn_sum += sum_digits(temp, MAX_DIGITS);
	    array_kill(temp);
	}
	else
	{
	    luhn_sum += digits[i];
	}
    }

    // check for luhn validity
    if (luhn_sum % 10 == 0)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}


// check for credit card models return 1 on match
int isamex(int digits[])
{
    // amex uses 15-digit numbers
    // start with 34 or 37
    if (digits[14] == 3)
    {
	if (digits[13] == 4 || digits[13] == 7)
	{
	    return 1;
	}
    }
    return 0;
}

int isvisa(int digits[])
{
    // visa uses 13-digit and 16-digit numbers
    // start with 4
    if (digits[15] == 4)
    {
	return 1;
    }
    else if (digits[12] == 4 && digits[13] == 0 && digits[14] == 0 && digits[15] == 4)
    {
	return 1;
    }
    return 0;
}

int ismaster_card(int digits[])
{
    // master_card uses 16-digit numbers
    // start with 51, 52, 53, 54, 55
    if (digits[15] == 5)
    {
	if (digits[14] == 1 || digits[14] == 2 || digits[14] == 3 || digits[14] == 4 || digits[14] == 5)
	{
	    return 1;
	}
    }
    return 0;
}

// return a dynamically allocatd array of digits of the number entered
int *get_digits(long long number)
{
    int *digits = array_init(MAX_DIGITS);
    for (int i = 0; number/10.0 > 0; number /= 10)
    {
	digits[i] = number % 10;
	i++;
    }
    return digits;
}

// returns the sum of the digits of attay of integer
int sum_digits(int array[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
	sum += array[i];
    }
    return sum;
}

// create and return pointer to a dynamically allocated interger array
int *array_init(int size)
{
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
	array[i] = 0;
    }
    return array;
}

// free any memory used up by array
void array_kill(int *array)
{
    free(array);
}

