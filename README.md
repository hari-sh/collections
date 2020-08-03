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


### list_add
```
void list_add(list* l, void* data);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

### list_push
```
void list_push(list* l, void* data);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

### list_pop
```
void* list_pop(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   |  data to be deleted|

### list_remove
```
void* list_remove(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   |  data to be deleted|

### list_reverse
```
void list_reverse(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   | void|

### list_insert
```
void list_insert(list* l, int p, void* data);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the position of insertion <br> 3. data to be inserted |
| output   |  void|

### list_delete
```
void* list_delete(list* l, int p);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the position of insertion|
| output   |  data to be deleted|

### list_data
```
void* list_data(list* l,int index);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the index of the required data|
| output   |  data at the given index |


### list_clear
```
void list_clear(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list |
| output   |  void|


### list_first
```
void* list_first(list* l, int (*list_comparator)(void* data));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  the first occuring data |


### list_select
```
list* list_select(list* l, int (*list_comparator)(void* data));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  list contaning all data for the given condition |

### list_copy
```
list* list_copy(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list |
| output   |  new copied list |

### list_concat
```
void list_concat(list* l1, list* l2);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  the first occuring data |

### list_merge
```
list* list_merge(list* l1, list* l2);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | two lists|
| output   |  the merged list |


## bst

### bst_create
```
bst* bst_create(int, void*, void*, void*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1.size of the data type <br> 2. lesser than function <br> 3. greater than function <br> 4.equal to function |
| output   | the created bst |


### bst_push
```
void bst_push(bst*, void*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a bst  <br> 2. data to be inserted|
| output   | void |


### bst_pop
```
void bst_pop(bst*, void*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a bst |
| output   | data to be deleted |

### bst_print_preorder
```
void bst_print_preorder(bst* ,void (*print_data)(void*));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a bst <br> 2.function pointer of the function that determines what to be done while traversing |
| output   |void|

### bst_print_postorder
```
void bst_print_postorder(bst* ,void (*print_data)(void*));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a bst <br> 2.function pointer of the function that determines what to be done while traversing |
| output   |void|

### bst_print_inorder
```
void bst_print_inorder(bst*, void (*print_data)(void*));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a bst <br> 2.function pointer of the function that determines what to be done while traversing |
| output   |void|

## heap
### heap_build
```
void heap_build(heap*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |a heap |
| output   | void |

### heap_push
```
void heap_push(heap*, void*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a heap <br>  2. data to be deleted |
| output   | void |

### heap_pop
```
void* heap_pop(heap*);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a heap |
| output   | data to be deleted |


### heap_print
```
void heap_print(heap*, void (*print_element)(void*));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a heap <br> 2.function pointer of the function that determines what to be done while traversing |
| output   |void|
