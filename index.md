# list

## list_create
```
list* list_create(int size);
```
creates and return an empty **list** of the given **size**

| parameter          | value                              |
| ---                |    ---                             |
| input   | size of the datatype to be inserted in the list |
| output   |  list |

## list_push
```
void list_push(list* l, void* data);
```
pushes the given **data** into the **end** of the give **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

## list_pop
```
void* list_pop(list* l);
```
pops the **data** from **end** of the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   |  data to be deleted|

## list_add
```
void list_add(list* l, void* data);
```
pushes the given **data** into the **beginning** of the give **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

## list_remove
```
void* list_remove(list* l);
```
pops the **data** from **beginning** of the given **list**

| parameter | value |
| ---       |  ---  |
| input   | a list|
| output   |  data to be deleted|


## list_insert
```
void list_insert(list* l, int index, void* data);
```
pushes the given **data** at the given **index** of the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the indexition of insertion <br> 3. data to be inserted |
| output   |  void|

## list_delete
```
void* list_delete(list* l, int index);
```
pops the **data** from given **index** of the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the indexition of insertion|
| output   |  data to be deleted|

## list_reverse
```
void list_reverse(list* l);
```
reverse the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   | void|

## list_data
```
void* list_data(list* l,int index);
```
peeks the **data** from the given index of the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the index of the required data|
| output   |  data at the given index |

## list_clear
```
void list_clear(list* l);
```
clears out all the data from the given **list**

| parameter          | value                              |
| ---                |    ---                             |
| input   |a list |
| output   |  void|

## list_destroy
```
void list_clear(list* l);
```
deletes the given **list** 

| parameter          | value                              |
| ---                |    ---                             |
| input   |a list |
| output   |  void|


## list_first
```
void* list_first(list* l, int (*list_comparator)(void* data));
```
returns the first occuring match of the given **list**. The **comparator** function have to be made should be passed as an argument of the function. Based on the comparator function the first occuring match would be found

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user based on which the first occurance of the condition met will occur|
| output   |  the first occuring data |


## list_select
```
list* list_select(list* l, int (*list_comparator)(void* data));
```
returns all the matches of the given **list**. The **comparator** function have to be made should be passed as an argument of the function. Based on the comparator function a list will be made with the matched values and returned from the function

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user based on which selection will occur|
| output   |  list contaning all data for the given condition |

## list_copy
```
list* list_copy(list* l);
```
copies the given **list** to a newly created list and is returned

| parameter          | value                              |
| ---                |    ---                             |
| input   | a list |
| output   |  new copied list |

## list_concat
```
void list_concat(list* l1, list* l2);
```
concatenates the second list to the end of first list

| parameter          | value                              |
| ---                |    ---                             |
| input   |two lists|
| output   |  void |

## list_merge
```
list* list_merge(list* l1, list* l2);
```
creates a new list and copies **l1** and **l2** to it one after another and returns the new list

| parameter          | value                              |
| ---                |    ---                             |
| input   | two lists|
| output   |  the merged list |


## list_traverse
```
void list_traverse(list* l, list_traverse_data);
```
traverse the **list** from head to tail. A function is to be made on what need to be done the traversal and passed as an argument to this function

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1.a list <br> 2. function pointer of the fuction which decided what needs to be done while traversing|
| output   |  void |

## list_rtraverse
```
void list_traverse(list* l, list_traverse_data);
```
traverse the **list** from tail to head. A function is to be made on what need to be done the traversal and passed as an argument to this function

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1.a list <br> 2. function pointer of the fuction which decided what needs to be done while traversing in reverse direction|
| output   |  void |

# heap

## heap_build
```
void heap_build(heap*);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | a heap |
| output   |  void |


## heap_push
```
void heap_push(heap*, void*);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a heap <br> 2. data to be inserted |
| output   |  void |

## heap_pop
```
void* heap_pop(heap*);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | a heap  |
| output   | poped out data |

## heap_print
```
void heap_print(heap*, void (*print_element)(void*));
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a heap <br> 2.function pointer of the print function which would print a single element |
| output   | void |


# map

## map_create
```
map* map_create(int key_size, int value_size, map_compare compare);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. size of key <br> 2.size of value <br> 3. function pointer of the comparator |
| output   |  map |

## map_push
```
void map_push(map* map, void* key, void* value); 
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a map <br> 2. key to be inserted <br> 3. value to be inserted |
| output   |  void |

## map_pop
```
void* map_pop(map* map, void* key);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a map <br> 2. key for which the corresponding value to be found |
| output   |  value |

## map_traverse
```
void map_traverse(map* map, map_access_data map_access_data);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a map <br> 2. function pointer of the function which decides what needs to be done on the traversal |
| output   |  void |

## map_get
```
void* map_get(map* map, void* key);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a map <br> 2. key for which the corresponding value to be found |
| output   |  value |


## map_values
```
void* map_values(map* map);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | a map |
| output   |  an array of values |

## map_keys
```
void* map_keys(map* map);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | a map |
| output   |  an array of keys |

## map_clear
```
void map_clear(map* map);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | a map |
| output   |  void |

## map_destroy
void map_destroy(map* map);

| parameter          | value                              |
| ---                |    ---                             |
| input   | a map |
| output   |  void |

