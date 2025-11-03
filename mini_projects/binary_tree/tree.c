// any form of data that is hierarchycal
#include <stdio.h>

typedef struct treenode {
    int value; //each nnode will have a value attached to it
    struct treenode *left; // each node can have two branches
    struct treenode *right;
} treenode;

treenode *createnode(int value) {
    treenode* result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

int main(){
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);
}