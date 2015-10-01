#include "kv.h"
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
    
    fprintf(fp,"%s*%s* ",j->key,j->value);
    j=NULL;
    }

}

node* deSerialize(FILE *fp){
       char key[20];
       char value[MAXSIZE];
       node *n = NULL;
       while (fscanf(fp, " %[^*]*%[^*]* ",key,value)==2){
           if (n){
               n = add_node(n,key,value);
       }
           else{
               n = new_node(key,value);
           }
       }
       return n;
}

