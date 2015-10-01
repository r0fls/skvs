#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

/*dbj4*/
unsigned long hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c;
        return hash;
    }

typedef struct node {
    struct node* left;
    struct node* right;
    char *key;
    char *value;
    unsigned long hash;
} node;

node* new_node(char *key, char *value) {
    struct node* result = malloc(sizeof(struct node));
    memset(result, 0, sizeof(struct node));
    result->key = key;
    result->hash = hash(key);
    result->value = value;
    result->left = result->right = NULL;
    return result;
}

node* add_node(node* tree, char *key, char *value ){
    unsigned long h = hash(key);
	if(tree==NULL)
	    return new_node(key,value);
    if(h<tree->hash)
		tree->left = add_node(tree->left,key,value);
	if(h>tree->hash)
		tree->right = add_node(tree->right,key,value);
	    return tree;
};

char* get_node(node* tree,char *key){

    if(tree == NULL)
        return NULL;
    
    unsigned long h = hash(key);
    if(tree->hash==h)
	    return tree->value;
    if(h<tree->hash && tree->left != NULL)
		return get_node(tree->left,key);
	if(h>tree->hash && tree->right !=NULL)
		return get_node(tree->right,key);
	}

void update_node(node* tree, char *key,char *value){

    if(tree == NULL)
        return;
    
    unsigned long h = hash(key);
    if(tree->hash==h)
	    tree->value = value;
    if(h<tree->hash && tree->left != NULL)
		update_node(tree->left,key,value);
	if(h>tree->hash && tree->right != NULL)
		update_node(tree->right,key,value);
}

node *minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

node *_delete_node(node* root, char *key)
{
    unsigned long h = hash(key);
    if (root == NULL) return root;
 
    if (h < root->hash)
        root->left = _delete_node(root->left, key);
 
    else if (h > root->hash)
        root->right = _delete_node(root->right, key);
 
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
 
        node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = _delete_node(root->right, temp->key);
    }
    return root;
}

void* delete_node(node* tree, char* key){
    tree = _delete_node(tree,key);
}


