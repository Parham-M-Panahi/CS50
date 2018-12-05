// declaration for linked list
// call init before any other calls

#include <stdbool.h>

#include "dictionary.h"

// a list is referenced by a pointer to the first node in list called 'head'.
typedef struct node
{
	char word[LENGTH + 1];
	struct node* next;
}
node;

// initializes list, call before any other function.
void initList(node** head);

// prints the linked list(python style).
void printList(node* head);

// add items to the start of list O(1).
void addItemToList(char* word, node** head);

// returns true if found word in list.
bool findWordInList(const char* word, node* head);

// deletes the entire list pointed to by 'head'.
void deleteList(node* head);
