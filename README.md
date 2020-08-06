# list

## list_push
```
void list_push(list* l, void* data);
```
<centre>
| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

</centre>
## list_pop
```
void* list_pop(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   |  data to be deleted|

## list_add
```
void list_add(list* l, void* data);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   | 1. a list <br> 2. desired data to be inserted |
| output   |  void |

## list_remove
```
void* list_remove(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   |  data to be deleted|

## list_reverse
```
void list_reverse(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list|
| output   | void|

## list_insert
```
void list_insert(list* l, int p, void* data);
```

| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the indexition of insertion <br> 3. data to be inserted |
| output   |  void|

## list_delete
```
void* list_delete(list* l, int p);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the indexition of insertion|
| output   |  data to be deleted|

## list_data
```
void* list_data(list* l,int index);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.the index of the required data|
| output   |  data at the given index |


## list_clear
```
void list_clear(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list |
| output   |  void|


## list_first
```
void* list_first(list* l, int (*list_comparator)(void* data));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  the first occuring data |


## list_select
```
list* list_select(list* l, int (*list_comparator)(void* data));
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  list contaning all data for the given condition |

## list_copy
```
list* list_copy(list* l);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | a list |
| output   |  new copied list |

## list_concat
```
void list_concat(list* l1, list* l2);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   |1. a list <br> 2.function pointer of the comparator function that is written by the user|
| output   |  the first occuring data |

## list_merge
```
list* list_merge(list* l1, list* l2);
```
| parameter          | value                              |
| ---                |    ---                             |
| input   | two lists|
| output   |  the merged list |
