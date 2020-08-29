#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct heap heap;

void heap_up(heap*, int);
void heap_down(heap*, int);
void heap_build(heap*);
void heap_push(heap*, void*);
void* heap_pop(heap*);
void heap_print(heap*, void (*print_element)(void*));

struct heap {
    char* heap;
    int* count;
    int size;
    int (*compare)(void* a, void* b);
};

void swap(char* a, char* b, int size)  {
    char* temp = malloc(sizeof(size));
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

heap* heap_create(void* array, int* count, int size, void* compare)   {
    heap* h = (heap*)malloc(sizeof(heap));
    h->heap = (char*)array;
    h->count = count;
    h->size = size;
    h->compare = compare;
}

void heap_build(heap* h)	{
    int n = *(h->count);
    for (int i = n/2-1; i >= 0; i--) 
        heap_down(h, i);
}

void heap_down(heap* h, int c)  {
  int size = h->size;
  int l = (2*c+1);
  int r = (2*c+2);
  int n = *(h->count);
  char* heap = h->heap;
  if(l<n) {
		if((r<n) && (h->compare(&(heap[r * size]), &(heap[l * size])))) {
			if(h->compare(&(heap[r * size]), &(heap[c * size])))  {
		  	swap(&(heap[r * size]),&(heap[c * size]), size);
		  }
		  heap_down(h,r);
		}  	
		else	{
		if(h->compare(&(heap[l * size]), &(heap[c * size])))  {
		  	swap(&(heap[l * size]), &(heap[c * size]), size);
		  }
		  heap_down(h,l);
		}
	}
	else
		return;		
}

void* heap_pop(heap* h)  {
    char* temp = malloc(sizeof(h->size));
    memcpy(temp, h->heap, h->size);
    int* n = (h->count);
    memcpy(&((h->heap)[0]), &((h->heap)[(*n-1)*h->size]), h->size);
	(*n)--;
	heap_down(h,0);
	return (void*)temp;
}

void heap_print(heap* h, void (*print_element)(void*))  {
	for(int i=0; i<*(h->count); i++) {
        print_element(&(h->heap[i*h->size]));
	}
	printf("\n");
}

void heap_push(heap* h, void* data)  {
    int n = *(h->count);
    memcpy(&(h->heap[n*h->size]), data, h->size);
    *(h->count)++;
    heap_up(h, (*h->count)-1);
}

void heap_up(heap* h, int c)  {
	if(c == 0)
		return;
	int p = (c-1)/2;
	if(h->compare(&(h->heap[c*h->size]),&(h->heap[p*h->size])))
		swap(&(h->heap[c*h->size]),&(h->heap[p*h->size]), h->size);
	heap_up(h, p);
}

void heap_sort(heap* h, void (*print_element)(void*))    {
    heap_build(h);
    int temp = *(h->count);
    for (int i=temp-1; i>0; i--) 
    {
        print_element(&h->heap[0]);
        print_element(&h->heap[i*h->size]);
        printf("\n");
        swap(&(h->heap[0]), &(h->heap[i*h->size]), h->size);
        (*h->count)--;
        heap_down(h, 0);
        heap_print(h, print_element);
    }
    *(h->count) = temp;
}
