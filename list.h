#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct list_node list_node;
typedef struct list list;
typedef void (*list_print_data)(void* data);

list* list_create(int size);
list_node* list_new_node(void* data, int size);

void list_print(list*, list_print_data);
void list_push(list*, void* data);
void list_add(list*, void* data);
void* list_pop(list* tail);
void* list_remove(list*);
void list_reverse(list*);
void list_insert(list*, int, void* data);
void* list_delete(list* ,int);
void* list_data(list* list,int index);
void list_clear(list* list);
void list_merge_sort(list* list, int (*list_comparator)(void* data1, void* data2));
void list_swap(list_node** n1, list_node** n2);
void* list_first(list* list, int (*list_comparator)(void* data));
list* list_select(list* list, int (*list_comparator)(void* data));
int (*list_comparator)(void* data, ...);
list* list_copy(list* l);
void list_concat(list* list1, list* list2);
list* list_merge(list* list1, list* list2);
void* mcopy(void* src, int size);

struct list_node   {
    void* data;
    list_node *next;
};

struct list {
    list_node* head;
    list_node* tail;
    int size;
    int count;
};

void* mcopy(void* src, int size)    {
    void* dest = malloc(size);
    memcpy (dest, src, size);
    return dest;
}

list_node* list_new_node(void* data, int size)    {
    list_node *temp = malloc(sizeof(list_node));
    temp->data = mcopy(data, size);
    temp->next = NULL;
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

void list_print(list* l, void (*list_print_data)(void*))  {
    list_node *p = l->head;
    while (p != NULL)   {
        list_print_data(p->data);
        p = p->next;
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
        (l->tail)->next = new_node;
        (l->tail) = (l->tail)->next;
    }
    (l->count)++;
}

void* list_pop(list* l)  {
    void* res = NULL;
    if (l->head != NULL)    {
        if (l->head->next == NULL)    {
            res = (l->head)->data;
            (l->head) = NULL;
            (l->tail) = NULL;
        }
        else    {
            res = (l->tail)->data;
            list_node *p = (l->head);
            while (p->next->next != NULL)
                p = p->next;
            free(p->next);
            p->next = NULL;
            (l->tail) = p;
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
        (l->head) = new_node;
    }
    (l->count)++;
}

void* list_remove(list* l)  {
    void* res = NULL;
    if ((l->head) != NULL)  {
        if (l->head == l->tail) {
            res = (l->head)->data;
            (l->head) = NULL;
            (l->tail) = NULL;            
        }
        else    {
            res = (l->head)->data;
            (l->head) = (l->head)->next;
        }
        (l->count)--;
    }
    return res;
}

void list_insert(list* l, int pos, void* n)    {
    if(pos <= l->count)  {
        if(pos==0)
            list_add(l,n);
        else if(pos==(l->count))
            list_push(l,n);
        else  {
            list_node *temp = l->head;
            list_node *new_node = list_new_node(n, l->size);
            for(int i=0; i<(pos-1); i++)
                temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
            (l->count)++;
        }
    }
}

void* list_delete(list* l, int pos)   {
    void* res = NULL;
    if((pos < l->count) && (l->head != NULL))   {
        if (pos == 0)
            res = list_remove(l);
        else    {
            list_node *temp = l->head;
            for(int i=0; i<(pos-1); i++)
                temp = temp->next;
            res = temp->next->data;
            temp->next = temp->next->next;
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

void list_merge_sort(list* l, int (*list_comparator)(void*, void*)) 
{ 
    list_node** head = &(l->head);
	int len = l->count;

	if (*head == NULL) 
		return; 
	list_node* start1 = NULL, *end1 = NULL; 
	list_node* start2 = NULL, *end2 = NULL; 
	list_node* prevend = NULL; 

	for (int gap = 1; gap < len; gap = gap*2) { 
		start1 = *head; 
		while (start1) { 
			bool isFirstIter = 0; 
			if (start1 == *head) 
				isFirstIter = 1; 

			int counter = gap; 
			end1 = start1; 
			while (--counter && end1->next) 
				end1 = end1->next; 

			start2 = end1->next; 
			if (!start2) 
				break; 
			counter = gap; 
			end2 = start2; 
			while (--counter && end2->next) 
				end2 = end2->next; 

			list_node* temp = end2->next; 

            list_node* temp1 = NULL; 
            if (list_comparator(start1->data,start2->data)) { 
                list_swap(&start1, &start2); 
                list_swap(&end1, &end2); 
            } 

            list_node* astart = start1, *aend = end1; 
            list_node* bstart = start2, *bend = end2; 
            list_node* bendnext = (end2)->next; 
            while (astart != aend && bstart != bendnext) { 
                if (list_comparator(astart->next->data, bstart->data)) { 
                    temp1 = bstart->next;
                    bstart->next = astart->next; 
                    astart->next = bstart; 
                    bstart = temp1; 
                } 
                astart = astart->next; 
            } 
            if (astart == aend) 
                astart->next = bstart; 
            else
                end2 = end1; 

            if (isFirstIter) 
                *head = start1; 
            else
                prevend->next = start1; 

            prevend = end2; 
            start1 = temp; 
        } 
        prevend->next = start1; 
	}
    list_node* p = *head;
    while(p->next != NULL)  {
        p = p -> next;
    }
    l->tail = p;
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
    list1->tail = list2->tail; 
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