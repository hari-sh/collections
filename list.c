#include "dsa/list.h"

void print_data(void* data)  {
    if(data != NULL)
    printf("%d  ", *(int*)(data));
}

int compare(void* data1, void* data2)  {
    return (int*)(data1) > (int*)(data2) ? 1 : 0;
}

void main() {

    list* l = list_create(sizeof(int));

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

    list_print(l, print_data);

    /*
    int i;
    int pos;
    list* l1 = list_create(sizeof(int));

    i = 0; 
    pos = 0;
    printf("%d...", pos);
    list_insert(l1, pos, &i);
    list_print(l1, print_data);

    i = 1;
    pos = 1;
    printf("%d...", pos);
    list_insert(l1, pos, &i);
    list_print(l1, print_data);

    i = 2;
    pos = 0;
    printf("%d....", pos);
    list_insert(l1, pos, &i);
    list_print(l1, print_data);

    i = 3;
    pos = 2;
    printf("%d....", pos);
    list_insert(l1, pos, &i);
    list_print(l1, print_data);

    i = 4;
    pos = 3;
    printf("%d...", pos);
    list_insert(l1, pos, &i);
    list_print(l1, print_data);

    list_merge_sort(l1, compare);
    list_print(l1, print_data);
    list_rprint(l1, print_data);
    */

    /*
    pos = 1;
    printf("%d....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    pos = 0;
    printf("%d....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    pos = 1;
    printf("%d.....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    pos = 2;
    printf("%d.....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    pos = 1;
    printf("%d.....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    pos = 1;
    printf("%d....", pos);
    print_data(list_delete(l1,pos));
    printf("\n");
    list_print(l1, print_data);

    /*
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
    */
}