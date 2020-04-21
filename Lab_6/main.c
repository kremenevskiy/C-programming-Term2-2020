#include <stdio.h>
#include "TripleTree.h"

int count_depth(struct Node * root);
int max(int a, int b, int c);

int main() {

    struct Node * root = NULL;

    int i;
    int x;
    printf("Inserted items: ");
    for(i = 0; i < 10; i++){
        x = rand() % 20;
        Insert(&root, x);
        printf("%i ", x);
    }
    printf("\n");
    Insert(&root, 13);
    //fflush(stdout);

    for(i = 0; i < 5; i++){
        x = rand() % 20;
        if(Search(root, x))
            printf("__SUCCESS__\nElement with value -- %i -- has been found\n", x);
        else{
            printf("No element with value -- %i -- in the tree\n", x);
        }
    }
    x = 0;
    int Depth = count_depth(root);
    printf("Numbers of tree's levels is -- %i\n", Depth);



    return 0;
}


int countTreeLevels(struct Node * root){
    static int l = 0, m = 0, r = 0;

    if (root->left){
        l++;
        return countTreeLevels(root->left);
    }
    if (root->middle){
        m++;
        return countTreeLevels(root->middle);
    }
    if(root->right){
        r++;
        return countTreeLevels(root->right);
    }

}


int max(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}


int count_depth(struct Node * root){
    if (!(root->left) && !(root->middle) && !(root->right)){
        return 1;
    }
    else
        return 1 + max(count_depth(root->left), count_depth(root->middle), count_depth(root->right));
}