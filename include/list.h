#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct list_node list_node;
typedef struct list list;
typedef void (*list_traverse_data)(void* data);

list* list_create(int size);
list_node* list_new_node(void* data, int size);

void list_traverse(list* l, list_traverse_data);
void list_push(list* l, void* data);
void list_add(list* l, void* data);
void* list_pop(list* l);
void* list_remove(list* l);
void list_reverse(list* l);
void list_insert(list* l, int index, void* data);
void* list_delete(list* l, int index);
void* list_data(list* l, int index);
void list_clear(list* l);
void list_swap(list_node** n1, list_node** n2);
void* list_first(list* l, int (*list_comparator)(void* data));
list* list_select(list* l, int (*list_comparator)(void* data));
list* list_copy(list* l);
void list_concat(list* l1, list* l2);
list* list_merge(list* l1, list* l2);
void* list_mcopy(void* src, int size);

struct list_node   {
    void* data;
    list_node *next;
    list_node *prev;
};

struct list {
    list_node* head;
    list_node* tail;
    int size;
    int count;
};

void* list_mcopy(void* src, int size)    {
    void* dest = malloc(size);
    memcpy (dest, src, size);
    return dest;
}

list_node* list_new_node(void* data, int size)    {
    list_node *temp = malloc(sizeof(list_node));
    temp->data = list_mcopy(data, size);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

list* list_create(int size) {
    list* l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->count = 0;
    l->size = size;
    return l;
}

void list_traverse(list* l, void (*list_traverse_data)(void*))  {
    list_node *p = l->head;
    while (p != NULL)   {
        list_traverse_data(p->data);
        p = p->next;
    }
    printf("\n");
}

void list_rtraverse(list* l, void (*list_traverse_data)(void*))  {
    list_node *p = l->tail;
    while (p != NULL)   {
        list_traverse_data(p->data);
        p = p->prev;
    }
    printf("\n");
}

void list_reverse(list* l)    {
    list_node *currn = (l->head);
    list_node *prevn = NULL;
    list_node *nextn = NULL;
    while (currn != NULL)   {
        nextn = currn->next;
        currn->next = prevn;
        prevn = currn;
        currn = nextn;
    }
    (l->head) = prevn;
}

void list_push(list* l, void* data)  {
    list_node *new_node = list_new_node(data, l->size);
    if ((l->head) == NULL)  {
        (l->head) = new_node;
        (l->tail) = (l->head);
    }
    else    {
        new_node->prev = l->tail;
        (l->tail)->next = new_node;
        (l->tail) = (l->tail)->next;
    }
    (l->count)++;
}

void* list_pop(list* l)  {
    void* res = NULL;
    if ((l->head) != NULL)  {
        res = (l->tail)->data;
        if (l->head == l->tail) {
            free(l->head);
            (l->head) = NULL;
            (l->tail) = NULL;         
        }
        else    {
            (l->tail) = (l->tail)->prev;
            free(l->tail->next);
            l->tail->next = NULL;
        }
        (l->count)--;
    }
    return res;
}

void list_add(list* l, void* data)   {
    list_node *new_node = list_new_node(data, l->size);
    if ((l->head) == NULL)  {
        (l->head) = new_node;
        (l->tail) = (l->head);
    }
    else   {
        new_node->next = (l->head);
        (l->head)->prev = new_node;
        (l->head) = new_node;
    }
    (l->count)++;
}

void* list_remove(list* l)  {
    void* res = NULL;
    if ((l->head) != NULL)  {
        res = (l->head)->data;
        if (l->head == l->tail) {
            free(l->head);
            (l->head) = NULL;
            (l->tail) = NULL;         
        }
        else    {
            (l->head) = (l->head)->next;
            free(l->head->prev);
            l->head->prev = NULL;
        }
        (l->count)--;
    }
    return res;
}

void list_insert(list* l, int index, void* n)    {
    if(index <= l->count)  {
        if(index==0)
            list_add(l,n);
        else if(index==(l->count))
            list_push(l,n);
        else  {
            list_node *temp = l->head;
            list_node *new_node = list_new_node(n, l->size);
            for(int i=0; i<(index-1); i++)
                temp = temp->next;
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            (l->count)++;
        }
    }
}

void* list_delete(list* l, int index)   {
    void* res = NULL;
    if((index < l->count) && (l->head != NULL))   {
        if (index == 0)
            res = list_remove(l);
        else if(index==(l->count)-1)
            res = list_pop(l);
        else    {
            list_node *temp = l->head;
            for(int i=0; i<(index-1); i++)
                temp = temp->next;
            res = temp->next->data;
            temp->next = temp->next->next;
            free(temp->next->prev);
            temp->next->prev = temp;
            (l->count)--;
        }
    }
    return res;
}

void list_clear(list* l) 
{ 
   list_node* current = l->head; 
   list_node* next; 
  
   while (current != NULL)  
   { 
       next = current->next; 
       free(current); 
       current = next; 
   } 
    l->head = NULL;
    l->tail = NULL;
}

void list_destroy(list* l) 
{ 
   list_clear(l);
   free(l);
   l = NULL;
}

void* list_data(list* l,int n)    {
    if(n < l->count) {
        list_node *p = l->head;
        for (int i=0; i<n; i++) {
            p = p->next;
        }
        return p->data;
    }
    return NULL;
}

void list_swap(list_node** n1, list_node** n2) {
    list_node* temp = *n1;
    *n1 = *n2;
    *n2 = temp; 
}

void* list_first(list* l, int (*list_comparator)(void*)) {
    list_node* p = l->head;
    void * data = NULL;
    while(!(list_comparator)(p->data) && p != NULL)    {
        p = p->next;
    }
    if(p != NULL)   {
        data = p->data;
    }
    return data;
}

list* list_select(list* l, int (*list_comparator)(void*)) {
    list* res = list_create(l->size);
    list_node* p = l->head;
    while(p != NULL)    {
        if(list_comparator(p->data))    {
            list_push(res,p->data);
        }
        p = p->next;
    }
    return res;
}

list* list_copy(list* l) {
    list* res = list_create(l->size);
    list_node* p = l->head;
    while(p != NULL)    {
        list_push(res,p->data);
        p = p->next;
    }
    return res;
}

list* list_merge(list* list1, list* list2) {
    list* res = list_create(list1->size);
    list_node* p = list1->head;
    while(p != NULL)    {
        list_push(res,p->data);
        p = p->next;
    }
    p = list2->head;
    while(p != NULL)    {
        list_push(res,p->data);
        p = p->next;
    }
    return res;
}

void list_concat(list* list1, list* list2) {
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
    list1->tail = list2->tail;
    list2->head = NULL;
    list2->tail = NULL;
}

void* list_to_array(list* l)   {
    char* res = malloc(sizeof(l->count * l->size));
    list_node* p = l->head;
    for(int i=0; i<l->count; i++)   {
        memcpy(res + i*l->size, p->data, l->size);
        p = p->next;
    }
    return res;
}

list* list_from_array(void* arr, int length, int size)   {
    list* res = list_create(size);
    for(int i=0; i<length; i++)  {
        list_push(res,((char*)arr + i*size));
    }
    return res;
}
