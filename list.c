#include "dsa/list.h"

void print_data(void* data)  {
    printf("%d  ", *(int*)(data));
}
void main() {
    int i;
    list* l1 = list_create(sizeof(int));

    i = 0;
    list_push(l1, &i);
    i = 1;
    list_push(l1, &i);
    i = 2;
    list_push(l1, &i);
    i = 3;
    list_push(l1, &i);
    i = 4;
    list_push(l1, &i);

    printf("given list... \n");
    list_print(l1, print_data);

    int a1[] = {9, 8, 7, 6, 5};

    printf("given array... \n");
    for(int i = 0; i<5; i++)
        printf("%d  ",a1[i]);

    int* a2 = list_to_array(l1);

    printf("\narray from list.. \n");
    for(int i = 0; i<5; i++)
        printf("%d  ",a2[i]);
    
    list* l2 = list_from_array(a1, 5, sizeof(int));
    
    printf("\nlist from array... \n");
    list_print(l2, print_data);
}