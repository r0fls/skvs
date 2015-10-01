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

int main(){
    node *n = new_node("key","value00");
    /*
    int i;
    char *str;
    for (i=0;i<10;i++){
        memset(str,0,strlen(str));
        sprintf(str,"key%d",i);
        n = add_node(n,strdup(str),strdup(str));
    }
    */
    n = add_node(n,"test","value");
    n = add_node(n,"key13","value2");
    n = add_node(n,"key14","value3");
    n = add_node(n,"key15","value4");
    n = add_node(n,"key16","value5");
    n = add_node(n,"key17","value6");
    n = add_node(n,"key18","value76");
    n = add_node(n,"key19","value7");
    update_node(n,"key11","newavalue2");
    n=_delete_node(n,"key");
    FILE *fp,*fp2;
    fp = fopen("test.db","r");
    /*serialize(fp,n);
    close(fp);*/
    node *j = NULL;
    j = deSerialize(fp);
    printf("%s",j->key);
    close(fp);
    fp2 = fopen("test2.db","w");
    serialize(fp2,j);
    close(fp2);
}
