#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum map_color map_color;
typedef struct map_node map_node;
typedef struct map map;
typedef struct map_data map_data;
typedef int (*map_compare)(void*, void*);
typedef void (*map_access_data)(map_data*);

enum map_color { RED, BLACK }; 

struct map_data	{
	char* key;
	char* value;
};

struct map_node {
map_data* data;
map_color color; 
map_node *left, *right, *parent; 
}; 

struct map { 
	map_node* root;
    int key_size;
	int value_size;
	int count;
	map_compare compare;
}; 

map* map_create(int key_size, int value_size, map_compare compare);
void map_push(map* map, void* key, void* value); 
void* map_pop(map* map, void* key);
void map_traverse(map* map, map_access_data map_access_data);
void* map_get(map* map, void* key);
void* map_values(map* map);
void* map_keys(map* map);
void map_clear(map* map);
void map_destroy(map* map);

map_node* map_new_node(void* key, void* value, int key_size, int value_size){
    map_node* temp = (map_node*)malloc(sizeof(map_node));
	temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL; 
	temp->color = RED;
    temp->data = malloc(sizeof(map_data));
    temp->data->key = malloc(sizeof(key_size));
    temp->data->value = malloc(sizeof(value_size));
	memcpy(temp->data->key, (char*)key, key_size);
	memcpy(temp->data->value, (char*)value, value_size);
    return temp;
} 

bool map_is_on_left(map_node* node) { return node == node->parent->left; } 

map_node *uncleNode(map_node* node) { 
	if (node->parent == NULL || node->parent->parent == NULL) 
	return NULL; 

	if (map_is_on_left(node->parent)) 
	return node->parent->parent->right; 
	else
	return node->parent->parent->left; 
}

map_node *map_sibling(map_node* node) { 
	if (node->parent == NULL) 
	return NULL; 

	if (map_is_on_left(node)) 
	return node->parent->right; 

	return node->parent->left; 
} 

void map_move_down(map_node* node, map_node *nParent) { 
	if (node->parent != NULL) { 
	if (map_is_on_left(node)) { 
		node->parent->left = nParent; 
	} else { 
		node->parent->right = nParent; 
	} 
	} 
	nParent->parent = node->parent; 
	node->parent = nParent; 
} 

bool map_has_red_child(map_node* node) { 
	return (node->left != NULL && node->left->color == RED) ||
		(node->right != NULL && node->right->color == RED); 
} 
void map_fix_double_black(map_node** root, map_node *x);

void map_left_rotate(map_node** root,map_node *x) { 
	map_node *nParent = x->right; 

	if (x == *root) 
	*root = nParent; 

	map_move_down(x,nParent); 

	x->right = nParent->left; 
	if (nParent->left != NULL) 
	nParent->left->parent = x; 

	nParent->left = x; 
} 

void map_right_rotate(map_node** root, map_node *x) { 
	map_node *nParent = x->left; 

	if (x == *root) 
	*root = nParent; 

	map_move_down(x,nParent); 

	x->left = nParent->right; 
	if (nParent->right != NULL) 
	nParent->right->parent = x; 

	nParent->right = x; 
} 

void map_swap_colors(map_node *x1, map_node *x2) { 
	map_color temp; 
	temp = x1->color; 
	x1->color = x2->color; 
	x2->color = temp; 
} 

void map_swap_values(map_node *u, map_node *v) {
	map_data* temp = u->data;
	u->data = v->data;
	v->data = temp;
} 

void map_fix_red_red(map_node** root, map_node *x) { 
	if (x == *root) { 
	x->color = BLACK; 
	return; 
	} 

	map_node* parent = x->parent; 
	map_node* grandparent = parent->parent; 
	map_node* uncle = uncleNode(x); 

	if (parent->color != BLACK) { 
	if (uncle != NULL && uncle->color == RED) { 
		parent->color = BLACK; 
		uncle->color = BLACK; 
		grandparent->color = RED; 
		map_fix_red_red(root, grandparent); 
	} else { 
		if (map_is_on_left(parent)) { 
		if (map_is_on_left(x)) { 
			map_swap_colors(parent, grandparent); 
		} else { 
			map_left_rotate(root, parent); 
			map_swap_colors(x, grandparent); 
		} 
		map_right_rotate(root, grandparent); 
		} else { 
		if (map_is_on_left(x)) { 
			map_right_rotate(root, parent); 
			map_swap_colors(x, grandparent); 
		} else { 
			map_swap_colors(parent, grandparent); 
		} 
		map_left_rotate(root, grandparent); 
		} 
	} 
	} 
}

map_node *map_replace(map_node *x) { 
	if (x->left != NULL && x->right != NULL)	{
		map_node* successor = x->right;
		while (successor->left != NULL)		{
			successor = successor->left; 
		}
		return successor; 
	}
	
	if (x->left == NULL && x->right == NULL) 
	return NULL; 

	if (x->left != NULL) 
	return x->left; 
	else
	return x->right; 
} 

void map_pop_util(map_node** root, map_node *v) { 
	map_node *u = map_replace(v); 

	bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK)); 
	map_node *parent = v->parent; 

	if (u == NULL) { 
	if (v == *root) { 
		*root = NULL; 
	} else { 
		if (uvBlack) { 
		map_fix_double_black(root, v); 
		} else { 
		if (map_sibling(v) != NULL) 
			map_sibling(v)->color = RED; 
		} 

		if (map_is_on_left(v)) { 
		parent->left = NULL; 
		} else { 
		parent->right = NULL; 
		} 
	} 
	free(v); 
	return; 
	} 

	if (v->left == NULL || v->right == NULL) { 
	if (v == *root) { 
		v->data->key = u->data->key; 
		v->left = v->right = NULL; 
		free(u); 
	} else { 
		if (map_is_on_left(v)) { 
		parent->left = u; 
		} else { 
		parent->right = u; 
		} 
		free(v); 
		u->parent = parent; 
		if (uvBlack) { 
		map_fix_double_black(root, u); 
		} else { 
		u->color = BLACK; 
		} 
	} 
	return; 
	} 

	map_swap_values(u, v); 
	map_pop_util(root, u); 
} 

void map_fix_double_black(map_node** root, map_node *x) { 
	if (x == *root) 
	return; 

	map_node *sibling = map_sibling(x), *parent = x->parent; 
	if (sibling == NULL) { 
	map_fix_double_black(root, parent); 
	} else { 
	if (sibling->color == RED) { 
		parent->color = RED; 
		sibling->color = BLACK; 
		if (map_is_on_left(sibling)) { 
		map_right_rotate(root, parent); 
		} else { 
		map_left_rotate(root, parent); 
		} 
		map_fix_double_black(root, x); 
	} else { 
		if (map_has_red_child(sibling)) { 
		if (sibling->left != NULL && sibling->left->color == RED) { 
			if (map_is_on_left(sibling)) { 
			sibling->left->color = sibling->color; 
			sibling->color = parent->color; 
			map_right_rotate(root, parent); 
			} else { 
			sibling->left->color = parent->color; 
			map_right_rotate(root, sibling); 
			map_left_rotate(root, parent); 
			} 
		} else { 
			if (map_is_on_left(sibling)) { 
			sibling->right->color = parent->color; 
			map_left_rotate(root, sibling); 
			map_right_rotate(root, parent); 
			} else { 
			sibling->right->color = sibling->color; 
			sibling->color = parent->color; 
			map_left_rotate(root, parent); 
			} 
		} 
		parent->color = BLACK; 
		} else { 
		sibling->color = RED; 
		if (parent->color == BLACK) 
			map_fix_double_black(root, parent); 
		else
			parent->color = BLACK; 
		} 
	} 
	} 
} 

void map_traverse_util(map_node *x, map_access_data map_access_data) { 
	if (x == NULL)	{
		return;
	}
	map_traverse_util(x->left, map_access_data); 
	map_access_data(x->data);
	map_traverse_util(x->right, map_access_data); 
}

map_node* map_search(map* map, void* n) { 
	map_node *temp = map->root; 
	while (temp != NULL) { 
		if (map->compare(n, temp->data->key) == -1) { 
			if (temp->left == NULL) 
			break; 
			else
			temp = temp->left; 
		} else if (map->compare(n, temp->data->key) == 0) { 
			break; 
		} else { 
			if (temp->right == NULL) 
			break; 
			else
			temp = temp->right;
		} 
	}
	return temp; 
} 

void map_traverse(map* map, map_access_data map_access_data)	{
	map_traverse_util(map->root, map_access_data);
}

void map_push(map* map, void* key, void* value) { 
	map_node 
	*newNode = map_new_node(key, value, map->key_size, map->value_size);
	if (map->root == NULL) { 
		newNode->color = BLACK; 
		map->root = newNode;
		(map->count)++;
	} else { 
	map_node *temp = map_search(map, key); 

	if (temp->data->key == key) { 
		return; 
	} 

	newNode->parent = temp; 

	if (map->compare(key, temp->data->key) == -1) 
		temp->left = newNode; 
	else
		temp->right = newNode; 
	(map->count)++;
	map_fix_red_red(&(map->root), newNode);
	} 
} 

void* map_pop(map* map, void* key) { 
	if (map->root == NULL) 
	return NULL; 

	map_node *v = map_search(map, key), *u; 

	if (map->compare(v->data->key, key) != 0) {
	return NULL; 
	}
	void* value = v->data->value;
	map_pop_util(&(map->root), v);
	(map->count)--;
	return value;
}

map* map_create(int key_size, int value_size, map_compare compare)	{
	map* temp = malloc(sizeof(map));
	temp->root = NULL;
	temp->key_size = key_size;
	temp->count = 0;
	temp->value_size = value_size;
	temp->compare = compare;
	return temp;
}

void* map_get(map* map, void* key)	{
	void* value = NULL;
	map_node* node = map_search(map, key);
	if(node != NULL)	{
		value = node->data->value;
	}
	return value;
}

void map_values_util(map_node *x, char* arr, int* iter, int size) { 
	if (x == NULL)	{
		return;
	}
	map_values_util(x->left, arr, iter, size);
	memcpy(arr+(((*iter)++)* size), x->data->value, 4);
	map_values_util(x->right, arr, iter, size); 
}

void map_keys_util(map_node *x, char* arr, int* iter, int size) { 
	if (x == NULL)	{
		return;
	}
	map_keys_util(x->left, arr, iter, size);
	memcpy(arr+(((*iter)++)* size), x->data->key, size);
	map_keys_util(x->right, arr, iter, size); 
}

void* map_values(map* map)	  {
	char* arr = (char*)malloc(map->value_size * map->count);
	int iter = 0;
	map_values_util(map->root, arr, &iter, map->value_size);
	return arr;
}

void* map_keys(map* map)	  {
	char* arr = (char*)malloc(map->key_size * map->count);
	int iter = 0;
	map_keys_util(map->root, arr, &iter, map->key_size);
	return arr;
}

void map_clear_util(map_node *x, int* count) { 
	if (x == NULL)	{
		return;
	}
	map_clear_util(x->left, count); 
	map_clear_util(x->right, count);
	free(x);
	x = NULL;
	(*count)--;
}

void map_clear(map* map)	{
	map_clear_util(map->root, &(map->count));
}

void map_destroy(map* map)	{
	map_clear_util(map->root, &(map->count));
	free(map);
	map = NULL;
}

