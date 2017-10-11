#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

listEl* createEl(char* data, size_t size) {
	listEl* e = malloc(sizeof(listEl));
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
	listEl* current = start;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}

//adds an element after the given one and returns the new pointer
listEl* insertAfter(listEl* el, char* data, size_t size) {
	listEl* newEl = createEl(data, size);
	listEl* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//deletes an element
void deleteAfter(listEl* after) {
	listEl* delete = after->next;
	listEl* newNext = delete->next;
	after->next = newNext;
	//frees memory after malloc
	free(delete->data);
	free(delete);
}

int length(listEl* list)
{
	listEl* current = list;
	int num = 0;
	while (current != NULL)
	{
		num++;
		current = current->next;
	}
	return num;
}

listEl* pop(listEl** list)
{
	listEl* temp = *list;
	*list = (*list)->next;
	return temp;
}

void push(listEl** list, char* data, size_t size)
{
	listEl* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

void enqueue(listEl** list, char* data, size_t size)
{
	listEl* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

listEl* dequeue(listEl* list)
{
	listEl* current = list;
	listEl* temp;
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
