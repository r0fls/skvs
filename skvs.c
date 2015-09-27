#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

typedef struct node {
    struct node* left;
    struct node* right;
    char *key;
    char *value;
} node;

node* new_node(char *key, char *value) {
    struct node* result = malloc(sizeof(struct node));
    result->key = key;
    result->value = value;
    result->left = result->right = NULL;
    return result;
}

int main()
{
node *n = new_node("key","value");
printf("%s:%s\n",n->key,n->value);
}
