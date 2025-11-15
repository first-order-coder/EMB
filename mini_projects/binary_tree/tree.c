// any form of data that is hierarchycal
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value; //each nnode will have a value attached to it
    struct treenode *left; // each node can have two branches
    struct treenode *right;
} treenode;

treenode *createnode(int value) {
    treenode *result = malloc(sizeof(treenode)); // allocate on the heap a new treenode
    if (result != NULL) { // only initialize the node if allocation worked
        result->left = NULL; // this node start as a leaf both child pointers = NULL
        result->right = NULL; // (*result).left = NULL 
        result->value = value; 
    }
    return result; // return the pointer.
}

void printtabs(int numtabs) {
    for (int i=0; i < numtabs; i++){
        printf("\t");
    }
}

void printtree_recursive(treenode *root, int level) {
    if (root == NULL) {
        printtabs(level);
        printf("---<empty tree>---");
        return;
    }
    
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    printf("left\n");

    printtree_recursive(root->left, level+1);
    printtabs(level); 
    printf("right\n");

    printtree_recursive(root->right, level+1);

    printtabs(level);
    printf("done\n");

}

void printtree(treenode *root) {
    printtree_recursive(root,0);
}

int main(){
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printtree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}