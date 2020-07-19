#include "list.h"

typedef struct student student;
struct student  {
    int id;
    char* name;
    int total;
};

student* init_student(int id, char* name, int total)    {
    student* temp = malloc(sizeof(student));
    temp->id = id;
    temp->name = name;
    temp->total = total;
    return temp;
}

void print_data(void* s)    {
    if(s != NULL)   {
        
        printf("student data....  ");
        printf("%d   ",((student*)s)->id);
        printf("%s   ",((student*)s)->name);
        printf("%d\n",((student*)s)->total);
        
    }
}

int compare(void* d1, void* d2)  {
    return (((student*)d1)->id > ((student*)d2)->id) ? 1 : 0;
}

int  isequal(void* data) {
    return (((student*)data)->total == 98) ? 1 : 0;
}

void main() {
    list* l = list_create(sizeof(student));
    list_add(l,init_student(1,"a",88));
    list_add(l,init_student(4,"d",61));
    list_print(l, &print_data);
    
    list_add(l,init_student(2,"b",91));
    list_add(l,init_student(9,"h",98));
    list_add(l,init_student(6,"f",98));
    list_add(l,init_student(3,"c",70));
    list_add(l,init_student(5,"e",52));

    list* lcopy = list_copy(l);
    list_concat(l,lcopy);
    list_print(l, print_data);

    list_print(l, print_data);
    printf("First entry with score 98\n");
    print_data(list_first(l, isequal));
    printf("\nAll entries/entry with score 98\n");
    list* lselect = list_select(l, isequal);
    list_print(lselect, print_data);
    list_print(lcopy, print_data);

    list* lmerge = list_merge(l,lcopy);
    list_print(lmerge, print_data);
    
}