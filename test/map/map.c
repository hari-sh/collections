#include<stdio.h>
#include<stdlib.h>
#include "map.h"

int compare(void* data1, void* data2)   {
    char* d1 = *(char**)data1;
    char* d2 = *(char**)data2;
    //return (d1 > d2) ? 1 : (d1 < d2) ? -1 : 0;
    return strcmp(d1,d2);
}

void printd(void* data)   {
    printf("%s ", *(char**)data);
}

int main(void)  {

    bst* bst = bst_create(sizeof(char*), compare);
    char* data = "hari";
	bst_push(bst, &data);
    data = "rana";
	bst_push(bst, &data);
    data = "bhai";
	bst_push(bst, &data);
    data = "great";
	bst_push(bst, &data);
    data = "legend";
	bst_push(bst, &data);
    data = "suspect";
	bst_push(bst, &data);

	bst_print_preorder(bst, printd);
	printf("\n");
    bst_print_inorder(bst, printd);
	printf("\n");
    bst_print_postorder(bst, printd);
	printf("\n");

    return 0;
}
