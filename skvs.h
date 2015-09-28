#include <stdio.h>
#include <stdlib.h>

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

node* find_node(node* tree,char *key){
    unsigned long h = hash(key);
    if(tree->hash==h)
	    return tree;
    if(h<tree->hash)
		find_node(tree->left,key);
	if(h>tree->hash)
		find_node(tree->right,key);
	if(tree == NULL)
        return NULL;
}

node *minValueNode(struct node* node)
{
    struct node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}

node *delete_node(node* root, char *key)
{
    unsigned long h = hash(key);
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (h < root->hash)
        root->left = delete_node(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (h > root->hash)
        root->right = delete_node(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
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
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void update_node(node* tree, char *key,char *value){
    node *t = find_node(tree,key);
    t->value=value;
}

