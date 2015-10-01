#include "serialize.h"

int main(){
    FILE *fp,*fp2;
    fp = fopen("test.db","r");
    node *j = NULL;
    j = deSerialize(fp);
    close(fp);
    update_node(j,"key13","newavalue2");
    update_node(j,"key14","newavalue2");
    update_node(j,"key15","newavalue2");
    update_node(j,"key16","newavalue2");
    update_node(j,"key17","newavalue2");
    fp2 = fopen("test2.db","w");
    serialize(fp2,j);
    close(fp2);
}

