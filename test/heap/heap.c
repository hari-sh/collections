#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int comparator(void* a, void* b) {
    return (*(int*)a > *(int*)b)? 1 : 0;
}

void print_element(void* element)    {
    printf("%d ", *(int*)element);
}

void main() {
    int* p;
    p =(int[9]){8,5,4,7,9,2,6,3,1};
    int n = 9;
    
    heap* h = heap_create(p, &n, sizeof(int), comparator);
    heap_build(h);
    heap_print(h, print_element);

    heap_sort(h, print_element);

    heap_print(h, print_element);
    
}
