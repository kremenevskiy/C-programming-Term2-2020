#ifndef C_LANG_GOODSLIST_H
#define C_LANG_GOODSLIST_H

#include "Goods.h"
#include <stdlib.h>
#include <stdio.h>

void PrintInfoGoods(struct Good good);

struct GoodsList {

//    struct Node_Good* head;
//    struct Node_Good* tail;

    struct Node_Good {
        struct Good *data;
        struct Node_Good *next;
        struct Node_Good *prev;
    } *head, *tail;
};


struct Node_Good* NewGood(){
    struct Node_Good* newGood = (struct Node_Good*) malloc(sizeof(struct Node_Good));
    newGood->next = NULL;
    newGood->prev = NULL;
    return newGood;
}


void AddGood(struct GoodsList* list, struct Good* good){

    struct Node_Good* newGood = NewGood();
    newGood->data = (struct Good*) malloc(sizeof(struct Good));
    newGood->data = good;

    if(list->head == NULL){
        list->head = newGood;
        list->tail = list->head;
        return;
    }

    list->head->prev = newGood;
    newGood->next = list->head;
    list->head = newGood;

}


void PrintGoods(struct GoodsList list){

    printf("\n____Printing Goods____\n");
    if(list.head == NULL){
        printf("Goods List is empty!\n");
        return;
    }

    struct Node_Good* temp = list.head;
    while(temp != NULL){
        PrintInfoGoods(*temp->data);
        temp = temp->next;
    }
    printf("________________________\n");
}


struct Node_Good* SearchGood(struct GoodsList* list, struct Good* man){
    struct Node_Good *temp = list->head;

    while(temp->data != man){
        temp = temp->next;
    }

    if(temp->data == NULL){
        printf("No such Good found\n");
        return NULL;
    }

    return temp;
}


void DeleteGood(struct GoodsList* list, struct Good* good){
    struct Node_Good* rmGood = SearchGood(list, good);

    if(rmGood == NULL){
        return;
    }

    if(rmGood == list->tail){
        list->tail->prev->next = NULL;
        list->tail = rmGood->prev;
    }
    else if(rmGood == list->head){
        list->head->next->prev = NULL;
        list->head = rmGood->next;
    }
    else {
        rmGood->next->prev = rmGood->prev;
        rmGood->prev->next = rmGood->next;
    }

    printf("Good: <%s> is deleted\n\n", rmGood->data->name);
    free(rmGood);
}


void PrintInfoGoods(struct Good good){
    printf("\tGood: %s\nClient taken ID: %s\nValue: %i$\nMoney for it: %i$\nDate taken: %s\nTaken for time: %s\n\n",
            good.name, good.clientID, good.value, good.money, good.date, good.timeKeeping);
}


#endif //C_LANG_GOODSLIST_H
