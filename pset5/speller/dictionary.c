// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

#include "linkedList.h"

// global reference to dict list
node* dict;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
	//turn all word to lowercase
	char s[LENGTH + 1];
	char c;
	int i = 0;
	while ((c = word[i]) != '\0')
	{
		c = tolower(c);
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	return findWordInList(s, dict);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
	// open dict file
	FILE* dictFile = fopen(dictionary, "r");
	if (!dictFile)
	{
		printf("Could not open %s.\n", dictionary);
		return false;
	}

	printf("** loading dictionary into memory **\n");

	// init dictList
	initList(&dict);

	// buffer for string and char to store
	char s[LENGTH + 1];
	int c;
	int i = 0;
	while ((c = fgetc(dictFile)) != EOF)
	{
		if (c == '\n')
		{
			s[i] = '\0';
			addItemToList(s, &dict);
			i = 0;
			continue;
		}

		s[i] = c;
		i++;
	}
	
	puts("\n\n");	
	printList(dict);
	puts("\n\n");

	fclose(dictFile);
	return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return countListItems(dict);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
	// TODO: make deleteListAPI check succsess
	deleteList(dict);
	return true;
}
