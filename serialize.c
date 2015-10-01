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
    
    fprintf(fp,"%s:%s*",j->key,j->value);
    j=NULL;
    }

}

void deSerialize(FILE *fp){
       int c;
       char key[20];
       char value[MAXSIZE];

       while (fscanf(fp, "%s:%s*",key,value)==2) { 
           printf("%s:%s",key,value);
       }
}

int main(){
    node *n = new_node("key","value");
    add_node(n,"isaac","cool person");
    add_node(n,"key13","value");
     
    char str[5];
    int i; 
    for (i=0;i<2;i++){

         sprintf(str,"key%d",i);
         printf("%s",str);
    }
    update_node(n,"key9","newavalue2");
    delete_node(n,"key");
    FILE *fp;
    fp = fopen("test.db","w+");
    /*serialize(fp,n);
    node *j;*/
    printf("%s: %s\n","key9",get_node(n,"key9"));
    deSerialize(fp);
    close(fp);

}
