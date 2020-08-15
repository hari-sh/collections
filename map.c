#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum map_color map_color;
typedef struct map_node map_node;
typedef struct map_tree map_tree;
typedef struct map_data map_data;

enum map_color { RED, BLACK }; 

int compare(void* data1, void* data2)   {
    int d1 = *(int*)data1;
    int d2 = *(int*)data2;
    return (d1 > d2) ? 1 : (d1 < d2) ? -1 : 0;
    //return strcmp(d1,d2);
}

struct map_data	{
	char* key;
	char* value;
};

struct map_node {
map_data* data;
map_color color; 
map_node *left, *right, *parent; 
}; 

struct map_tree { 
	map_node* root;
    int key_size;
	int value_size;
}; 

void printd(map_data* data)   {
    printf("key: %d  value: %d \n", *(int*)data->key, *(int*)data->value);
}

map_node* createNewNode(void* key, void* value){
	int key_size = 4;
	int value_size = 4;
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

bool isOnLeft(map_node* node) { return node == node->parent->left; } 

map_node *uncleNode(map_node* node) { 
	if (node->parent == NULL || node->parent->parent == NULL) 
	return NULL; 

	if (isOnLeft(node->parent)) 
	return node->parent->parent->right; 
	else
	return node->parent->parent->left; 
}

map_node *siblingNode(map_node* node) { 
	if (node->parent == NULL) 
	return NULL; 

	if (isOnLeft(node)) 
	return node->parent->right; 

	return node->parent->left; 
} 

void moveDown(map_node* node, map_node *nParent) { 
	if (node->parent != NULL) { 
	if (isOnLeft(node)) { 
		node->parent->left = nParent; 
	} else { 
		node->parent->right = nParent; 
	} 
	} 
	nParent->parent = node->parent; 
	node->parent = nParent; 
} 

bool hasRedChild(map_node* node) { 
	return (node->left != NULL && node->left->color == RED) ||
		(node->right != NULL && node->right->color == RED); 
} 
void fixDoubleBlack(map_node** root, map_node *x);

void leftRotate(map_node** root,map_node *x) { 
	map_node *nParent = x->right; 

	if (x == *root) 
	*root = nParent; 

	moveDown(x,nParent); 

	x->right = nParent->left; 
	if (nParent->left != NULL) 
	nParent->left->parent = x; 

	nParent->left = x; 
} 

void rightRotate(map_node** root, map_node *x) { 
	map_node *nParent = x->left; 

	if (x == *root) 
	*root = nParent; 

	moveDown(x,nParent); 

	x->left = nParent->right; 
	if (nParent->right != NULL) 
	nParent->right->parent = x; 

	nParent->right = x; 
} 

void swapColors(map_node *x1, map_node *x2) { 
	map_color temp; 
	temp = x1->color; 
	x1->color = x2->color; 
	x2->color = temp; 
} 

void swapValues(map_node *u, map_node *v) {
	map_data* temp = u->data;
	u->data = v->data;
	v->data = temp;
} 

void fixRedRed(map_node** root, map_node *x) { 
	if (x == *root) { 
	x->color = BLACK; 
	return; 
	} 

	map_node *parent = x->parent, *grandparent = parent->parent, 
		*uncle = uncleNode(x); 

	if (parent->color != BLACK) { 
	if (uncle != NULL && uncle->color == RED) { 
		parent->color = BLACK; 
		uncle->color = BLACK; 
		grandparent->color = RED; 
		fixRedRed(root, grandparent); 
	} else { 
		// Else perform LR, LL, RL, RR 
		if (isOnLeft(parent)) { 
		if (isOnLeft(x)) { 
			// for left right 
			swapColors(parent, grandparent); 
		} else { 
			leftRotate(root, parent); 
			swapColors(x, grandparent); 
		} 
		rightRotate(root, grandparent); 
		} else { 
		if (isOnLeft(x)) { 
			rightRotate(root, parent); 
			swapColors(x, grandparent); 
		} else { 
			swapColors(parent, grandparent); 
		} 
		leftRotate(root, grandparent); 
		} 
	} 
	} 
} 

map_node *successor(map_node *x) { 
	map_node *temp = x; 

	while (temp->left != NULL) 
	temp = temp->left; 

	return temp; 
} 

map_node *BSTreplace(map_node *x) { 
	if (x->left != NULL && x->right != NULL) 
	return successor(x->right); 
	
	if (x->left == NULL && x->right == NULL) 
	return NULL; 

	if (x->left != NULL) 
	return x->left; 
	else
	return x->right; 
} 

void deleteNode(map_node** root, map_node *v) { 
	map_node *u = BSTreplace(v); 

	bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK)); 
	map_node *parent = v->parent; 

	if (u == NULL) { 
	if (v == *root) { 
		*root = NULL; 
	} else { 
		if (uvBlack) { 
		fixDoubleBlack(root, v); 
		} else { 
		if (siblingNode(v) != NULL) 
			siblingNode(v)->color = RED; 
		} 

		if (isOnLeft(v)) { 
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
		if (isOnLeft(v)) { 
		parent->left = u; 
		} else { 
		parent->right = u; 
		} 
		free(v); 
		u->parent = parent; 
		if (uvBlack) { 
		fixDoubleBlack(root, u); 
		} else { 
		u->color = BLACK; 
		} 
	} 
	return; 
	} 

	swapValues(u, v); 
	deleteNode(root, u); 
} 

void fixDoubleBlack(map_node** root, map_node *x) { 
	if (x == *root) 
	return; 

	map_node *sibling = siblingNode(x), *parent = x->parent; 
	if (sibling == NULL) { 
	fixDoubleBlack(root, parent); 
	} else { 
	if (sibling->color == RED) { 
		// Sibling red 
		parent->color = RED; 
		sibling->color = BLACK; 
		if (isOnLeft(sibling)) { 
		// left case 
		rightRotate(root, parent); 
		} else { 
		// right case 
		leftRotate(root, parent); 
		} 
		fixDoubleBlack(root, x); 
	} else { 
		if (hasRedChild(sibling)) { 
		if (sibling->left != NULL && sibling->left->color == RED) { 
			if (isOnLeft(sibling)) { 
			sibling->left->color = sibling->color; 
			sibling->color = parent->color; 
			rightRotate(root, parent); 
			} else { 
			sibling->left->color = parent->color; 
			rightRotate(root, sibling); 
			leftRotate(root, parent); 
			} 
		} else { 
			if (isOnLeft(sibling)) { 
			sibling->right->color = parent->color; 
			leftRotate(root, sibling); 
			rightRotate(root, parent); 
			} else { 
			sibling->right->color = sibling->color; 
			sibling->color = parent->color; 
			leftRotate(root, parent); 
			} 
		} 
		parent->color = BLACK; 
		} else { 
		sibling->color = RED; 
		if (parent->color == BLACK) 
			fixDoubleBlack(root, parent); 
		else
			parent->color = BLACK; 
		} 
	} 
	} 
} 

void inorder(map_node *x) { 
	if (x == NULL)	{
		return;
	}
	inorder(x->left); 
	printd(x->data);
	inorder(x->right); 
} 

map_node* search(map_node* root, void* n) { 
	map_node *temp = root; 
	while (temp != NULL) { 
		if (compare(n, temp->data->key) == -1) { 
			if (temp->left == NULL) 
			break; 
			else
			temp = temp->left; 
		} else if (compare(n, temp->data->key) == 0) { 
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

void insert(map_tree* rbt, void* key, void* value) { 
	map_node *newNode = createNewNode(key, value);
	if (rbt->root == NULL) { 
		newNode->color = BLACK; 
		rbt->root = newNode;
	} else { 
	map_node *temp = search(rbt->root, key); 

	if (temp->data->key == key) { 
		return; 
	} 

	newNode->parent = temp; 

	if (compare(key, temp->data->key) == -1) 
		temp->left = newNode; 
	else
		temp->right = newNode; 

	fixRedRed(&(rbt->root), newNode); 
	} 
} 

void delete(map_tree* rbt, void* key) { 
	if (rbt->root == NULL) 
	return; 

	map_node *v = search(rbt->root, key), *u; 

	if (compare(v->data->key, key) != 0) {
	return; 
	}

	deleteNode(&(rbt->root), v); 
}

map_tree* map_create(int key_size, int value_size)	{
	map_tree* temp = malloc(sizeof(map_tree));
	temp->root = NULL;
	temp->key_size = key_size;
	temp->value_size = value_size;
	return temp;
}

void main() { 

map_tree* rbt  = map_create(4,4);
int key;
int value;
key = 7;
value = 1;

insert(rbt, &key, &value); 
key = 3;
value = 2;
insert(rbt, &key, &value); 
key = 18;
value = 3;
insert(rbt, &key, &value); 
key = 10;
value = 4;
insert(rbt, &key, &value); 
key = 22;
value = 5;
insert(rbt, &key, &value); 
key = 8;
value = 6;
insert(rbt, &key, &value); 
key = 11;
value = 7;
insert(rbt, &key, &value); 
key = 26;
value = 8;
insert(rbt, &key, &value); 
key = 2;
value = 9;
insert(rbt, &key, &value); 
key = 6;
value = 10;
insert(rbt, &key, &value); 
key = 13;
value = 11;
insert(rbt, &key, &value); 

inorder(rbt->root); 

printf("\nDeleting 18, 11, 3, 10, 22\n"); 

key = 18;
delete(rbt, &key); 
key = 11;
delete(rbt, &key); 
key = 3;
delete(rbt, &key); 
key = 10;
delete(rbt, &key); 
key = 22;
delete(rbt, &key);

inorder(rbt->root);
} 
