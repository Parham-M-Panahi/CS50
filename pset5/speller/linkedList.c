// implementation for linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

void initList(node** head)
{
	*head = NULL;
}

void printList(node* head)
{
	node* ptr = head;
	
	printf("[");
	if (ptr == NULL)
	{
		printf("]\n");
		return;
	}
	
	while (ptr != NULL)
	{
		printf("\'%s\'", ptr -> word);

		if (ptr -> next != NULL)
		{
			printf(", ");
		}

		ptr = ptr -> next;
	}

		printf("]\n");
}

void addItemToList(char* word, node** head)
{
	node* ptr = (node *)malloc(sizeof(node));

	if (!ptr)
	{
		fprintf(stderr, "Could not allocate memory for item \'%s\'\n", word);
		free(ptr);
		return;
	}
	strcpy(ptr -> word, word);
	ptr -> next = *head;

	*head = ptr;
}

bool findWordInList(const char* word, node* head)
{
	node* ptr = head;

	while (ptr != NULL)
	{
		if (!strcmp(word, ptr -> word))
		{
			return true;
		}

		ptr = ptr -> next;
	}
	return false;
}

void deleteList(node* head)
{
	node* ptr = head;

	while (ptr != NULL)
	{
		node* freePtr = ptr;
		ptr = ptr -> next;
		free(freePtr);
	}
}

int countListItems(node* head)
{
	int count = 0;

	node* ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr -> next;		
	}
	return count;
}

/*

node* list;

int main(void)
{
	FILE* file = fopen("text.txt", "r");
	if (!file)
	{
		fprintf(stderr, "Could not open file text.txt.\n");
		//fclose(file);
		return 1;
	}

	char s[LENGTH + 1];

	

	initList(&list);

	printList(list);

	int c;
	int i = 0;
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
		{
			s[i] = '\0';
			addItemToList(s, &list);
			i = 0;
			continue;
		}
		
		s[i] = c;
		i++;
	}

	printList(list);

	puts("\n\n");

	
	if (findWordInList("cat", list))
	{
		printf("found \'cat\' in list.\n");
	}

	deleteList(list);

	return 0;
}

*/

