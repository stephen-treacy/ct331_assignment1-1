#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct {
	char* data;
	size_t size;
	struct listElementStruct* next;
} listEl;

listEl* createEl(char* data, size_t size);

void traverse(listEl* start);

listEl* insertAfter(listEl* after, char* data, size_t size);

void deleteAfter(listEl* after);

int length(listEl* list);

void push(listEl** list, char* data, size_t size);

listEl* pop(listEl** list);

void enqueue(listEl** list, char* data, size_t size);

listEl* dequeue(listEl* list);
#endif
