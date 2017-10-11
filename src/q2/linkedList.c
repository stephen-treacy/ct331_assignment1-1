#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

listEl* createEl(char* data, size_t size) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//if there's an error
		return NULL; //indicates an error
	}
	char* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		//if there's an error
		free(e); //free the memory
		return NULL; //indicates an error.
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}

//adds an element after the given one and returns the new pointer
listElement* insertAfter(listElement* el, char* data, size_t size) {
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newElement->next = next;
	el->next = newEl;
	return newEl;
}


//deletes an element
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//frees memory after malloc
	free(delete->data);
	free(delete);
}

int length(listElement* list)
{
	listElement* current = list;
	int num = 0;
	while (current != NULL)
	{
		num++;
		current = current->next;
	}
	return num;
}

listElement* pop(listElement** list)
{
	listElement* temp = *list;
	*list = (*list)->next;
	return temp;
}

void push(listElement** list, char* data, size_t size)
{
	listElement* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

void enqueue(listElement** list, char* data, size_t size)
{
	listElement* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

listElement* dequeue(listElement* list)
{
	listElement* current = list;
	listElement* temp;
	while (current != NULL)
	{
		if (current->next->next == NULL)
		{
			temp = createEl(current->next->data, current->next->size);
			free(current->next->data);
			free(current->next);
			current->next = NULL;
		}
		current = current->next;
	}
	return temp;
}
