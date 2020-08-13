#include<stdio.h>
#include<stdlib.h>
#include "map.h"

int compare(void* data1, void* data2)   {
    int d1 = *(int*)data1;
    int d2 = *(int*)data2;
    return (d1 > d2) ? 1 : (d1 < d2) ? -1 : 0;
}

void printd(void* data)   {
    printf("%d ", *(int*)data);
}

int main(void)  {

    bst* bst = bst_create(sizeof(int), compare);
    int data = 5;
	bst_push(bst, &data);
    data = 3;
	bst_push(bst, &data);
    data = 6;
	bst_push(bst, &data);
    data = 1;
	bst_push(bst, &data);
    data = 7;
	bst_push(bst, &data);
    data = 4;
	bst_push(bst, &data);

	bst_print_preorder(bst, printd);
	printf("\n");
    bst_print_inorder(bst, printd);
	printf("\n");
    bst_print_postorder(bst, printd);
	printf("\n");

    data = 5;
	bst_pop(bst, &data);
    data = 4;
	bst_pop(bst, &data);
    data = 1;
	bst_pop(bst, &data);

	bst_print_preorder_util(bst->root, printd);
	printf("\n");

    printf("%d",strcmp("a","a"));
	printf("\n");
    printf("%d",strcmp("aab","aaba"));
	printf("\n");
    printf("%d",strcmp("bb","aa"));
	printf("\n");
    
    return 0;
}
