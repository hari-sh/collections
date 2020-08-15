#include "map.h"

int comparer(void* data1, void* data2)   {
    int d1 = *(int*)data1;
    int d2 = *(int*)data2;
    return (d1 > d2) ? 1 : (d1 < d2) ? -1 : 0;
    //return strcmp(d1,d2);
}

void printd(map_data* data)   {
    printf("key: %d  value: %d \n", *(int*)data->key, *(int*)data->value);
}

void main() { 

map* map  = map_create(4,4, comparer);
int key;
int value;
key = 7;
value = 1;

map_push(map, &key, &value); 
key = 3;
value = 2;
map_push(map, &key, &value); 
key = 18;
value = 3;
map_push(map, &key, &value); 
key = 10;
value = 4;
map_push(map, &key, &value); 
key = 22;
value = 5;
map_push(map, &key, &value); 
key = 8;
value = 6;
map_push(map, &key, &value); 
key = 11;
value = 7;
map_push(map, &key, &value); 
key = 26;
value = 8;
map_push(map, &key, &value); 
key = 2;
value = 9;
map_push(map, &key, &value); 
key = 6;
value = 10;
map_push(map, &key, &value); 
key = 13;
value = 11;
map_push(map, &key, &value); 

map_traverse(map, printd);
printf("\ncount.. %d\n", map->count);
printf("\nDeleting 18, 11, 3, 10, 22\n"); 

key = 18;
map_pop(map, &key); 
key = 11;
map_pop(map, &key); 
key = 3;
map_pop(map, &key); 
key = 10;
map_pop(map, &key); 
key = 22;
map_pop(map, &key);

map_traverse(map, printd);
printf("\ncount.. %d\n", map->count);

key = 26;
printf("\n%d\n",*(int*)map_get(map, &key));

int* keys = (int*)map_keys(map);

printf("keys: \n");
for(int i=0; i<map->count; i++) {
    printf("%d ", keys[i]);
}

int* values = (int*)map_values(map);

printf("values: \n");
for(int i=0; i<map->count; i++) {
    printf("%d ", values[i]);
}

map_clear(map);
printf("%d", map->count);
}