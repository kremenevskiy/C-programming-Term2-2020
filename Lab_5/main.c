#include "Stack.h"

//Stack invert_stack(Stack stack);


int main(){

    struct Node *obj = NULL;
    push(&obj, 34);
    push(&obj, 232);
    push(&obj, 1000);

    for(int i = 0; i < 4; i++){
        printf("%i \n", pop(&obj));
    }


}


//Stack invert_stack(Stack stack){
//
//    Stack tempStack;
//
//    int x = stack.pop();
//    while(x){
//        tempStack.push(x);
//        x = stack.pop();
//    }
//
//    return tempStack;
//
//}
