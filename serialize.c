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

node *deSerialize(FILE *fp){
       int c;
       char key[20];
       char value[MAXSIZE];
       node *n = NULL;
       while (fscanf(fp, " %[^*]*%[^*]* ",key,value)!=EOF) { 
           if (n){
               n = add_node(n,key,value);
       }
           else{
               n = new_node(key,value);
           }
       }
       return n;
}

int main(){
    node *n = new_node("key","value");
    n = add_node(n,"isaac","cool person");
    n = add_node(n,"key13","value");
    n = add_node(n,"key14","value");
    n = add_node(n,"key15","value");
    n = add_node(n,"key16","value");
    n = add_node(n,"key17","value");
    n = add_node(n,"key18","value");
    n = add_node(n,"key19","value");
    update_node(n,"key11","newavalue2");
    printf("%s,%s","key19",get_node(n,"key19"));
    n=_delete_node(n,"key");
    FILE *fp,*fp2;
    fp = fopen("test.db","r");
    /*serialize(fp,n);
    node *j;*/
    node *j = deSerialize(fp);
    close(fp);
    fp2 = fopen("test2.db","w");
    serialize(fp2,j);
}
