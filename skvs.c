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

node* find_node(node* tree,char *key){
    if(tree == NULL)
        return NULL;
    
    unsigned long h = hash(key);
    if(tree->hash==h)
	    return tree;
    if(h<tree->hash && tree->left != NULL)
		find_node(tree->left,key);
	if(h>tree->hash && tree->right !=NULL)
		find_node(tree->right,key);
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

void* delete(node* tree, char* key){
    tree = delete_node(tree,key);
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

int main()
{
node *n = new_node("key","value");
add_node(n,"key1","value");
add_node(n,"key2","value");
add_node(n,"key3","value");
add_node(n,"key4","value");
add_node(n,"key5","value");
add_node(n,"key6","value");
add_node(n,"key7","value");
add_node(n,"key8","value");
add_node(n,"key9","value");
add_node(n,"key11","value");
add_node(n,"key12","value");
add_node(n,"key13","value");
node *a = find_node(n,"key");
update_node(n,"key","newavalue2");
printf("%s:%s\nhash value: %lu\n",n->key,n->value,n->hash);
printf("%s:%s\nhash value: %lu\n",a->key,a->value,a->hash);
delete(n,"key");
printf("%s:%s\nhash value: %lu\n",n->key,n->value,n->hash);
}
