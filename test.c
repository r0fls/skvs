#include "skvs.h"
void serialize(FILE *fp, node *n){
    node *j = n;
    while (j){
        while(j->left){
            serialize(fp,j->left);
            j->left=NULL;
    }
        while(j->right){
            serialize(fp,j->right);
            j->right=NULL;
}
fprintf(fp,"%lu:%s:%s\n",j->hash,j->key,j->value);
j=NULL;
}
close(fp);
}

int main(){
    node *n = new_node("key","value");
    add_node(n,"isaac","cool person");
    add_node(n,"key2","value2");
    add_node(n,"key3","value3");
    add_node(n,"anotherkey","value3");
    add_node(n,"ahappykey","value3");
    add_node(n,"morekey","value17");
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
    node *a = find_node(n,"isaac");
    update_node(n,"key2","newavalue2");
    printf("%s\t%s\t\thash value: %lu\n",n->key,n->value,n->hash);
    printf("%s\t%s\t\thash value: %lu\n",a->key,a->value,a->hash);
    delete_node(n,"key");
    printf("%s\t%s\t\thash value: %lu\n",n->key,n->value,n->hash);
    FILE *fp;
    fp = fopen("db.txt","w");
    serialize(fp,n);
}
