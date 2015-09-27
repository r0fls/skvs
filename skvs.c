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

int main()
{
node *n = new_node("key","value");
add_node(n,"key2","value2");
node *a = find_node(n,"key2");
printf("%s:%s\nhash value: %lu\n",n->key,n->value,n->hash);
printf("%s:%s\nhash value: %lu\n",a->key,a->value,a->hash);
}
