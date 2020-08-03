# libdsa
libdsa is a generic data structure library for c language
  - Can be used for any data types like int, float etc..
  - applicable for user defined data types using struct

# Available data structures
  - list
  - heap
  - bst

# functions
## list


list_add
```
void list_add(list* l, void* data);
```
|        |           |
| input  | 1. a list |
|        | 2. desired data to be inserted |
|------  |-----------|
| output | void      |

|        |           |
---     |    ---
input   | 1. a list |
|       | 2. desired data to be inserted |
output   |  void |

list_push
```
void list_push(list* l, void* data);
```

list_pop
```
void* list_pop(list* l);
```

list_remove
```
void* list_remove(list* l);
```

list_reverse
```
void list_reverse(list* l);
```

list_insert
```
void list_insert(list* l, int p, void* data);
```

list_delete
```
void* list_delete(list* l, int p);
```

list_data
```
void* list_data(list* l,int index);
```

list_clear
```
void list_clear(list* l);
```


list_first
```
void* list_first(list* l, int (*list_comparator)(void* data));
```


list_select
```
list* list_select(list* l, int (*list_comparator)(void* data));
```

list_copy
```
list* list_copy(list* l);
```

list_concat
```
void list_concat(list* l1, list* l2);
```

list_merge
```
list* list_merge(list* l1, list* l2);
```

list_mcopy
```
void* list_mcopy(void* src, int size);
```

## bst

bst_create
```
bst* bst_create(int, void*, void*, void*);
```

bst_push
```
void bst_push(bst*, void*);
```

bst_pop
```
void bst_pop(bst*, void*);
```

bst_print_preorder
```
void bst_print_preorder(bst* ,void (*print_data)(void*));
```

bst_print_postorder
```
void bst_print_postorder(bst* ,void (*print_data)(void*));
```

bst_print_inorder
```
void bst_print_inorder(bst*, void (*print_data)(void*));
```

## heap
heap_build
```
void heap_build(heap*);
```

heap_push
```
void heap_push(heap*, void*);
```

heap_pop
```
void* heap_pop(heap*);
```

heap_print
```
void heap_print(heap*, void (*print_element)(void*));
```
