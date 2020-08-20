#include "list.h"

void print_data(void* data)  {
    if(data != NULL)
    printf("%d  ", *(int*)(data));
}

int compare(void* data1, void* data2)  {
    return (int*)(data1) > (int*)(data2) ? 1 : 0;
}

void main() {

    int i;
    int index;
    list* l1 = list_create(sizeof(int));

    i = 0; 
    index = 0;
    printf("%d...", index);
    list_insert(l1, index, &i);
    list_traverse(l1, print_data);
    printf("\nreverse traverse \n");
    list_rtraverse(l1, print_data);

    i = 1;
    index = -1;
    printf("%d...", index);
    list_insert(l1, index, &i);
    list_traverse(l1, print_data);
    printf("\nreverse traverse \n");
    list_rtraverse(l1, print_data);

    i = 2;
    index = 2;
    printf("%d....", index);
    list_insert(l1, index, &i);
    list_traverse(l1, print_data);
    printf("\nreverse traverse \n");
    list_rtraverse(l1, print_data);

    i = 3;
    index = 0;
    printf("%d....", index);
    list_insert(l1, index, &i);
    list_traverse(l1, print_data);
    printf("\nreverse traverse \n");
    list_rtraverse(l1, print_data);

    i = -1;
    index = -2;
    printf("%d...", index);
    list_insert(l1, index, &i);

    list_traverse(l1, print_data);
    printf("\nreverse traverse \n");
    list_rtraverse(l1, print_data);
 
    index = 1;
    printf("%d....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);

    index = 0;
    printf("%d....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);

    index = 1;
    printf("%d.....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);

    index = 2;
    printf("%d.....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);

    index = 1;
    printf("%d.....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);

    index = 1;
    printf("%d....", index);
    print_data(list_delete(l1,index));
    printf("\n");
    list_traverse(l1, print_data);
}
    /*
    printf("given list... \n");
    list_traverse(l1, print_data);

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
    list_traverse(l2, print_data);

    int i = 5;
    list_push(l, &i);
    i = 4;
    list_push(l, &i);
    i = 1;
    list_push(l, &i);
    i = 2;
    list_push(l, &i);
    i = 7;
    list_push(l, &i);
    i = 3;
    list_push(l, &i);
    i = 6;
    list_push(l, &i);
    i = 8;
    list_push(l, &i);

    list_traverse(l, print_data)
    */