#ifndef C_LANG_CLINTLIST_H
#define C_LANG_CLINTLIST_H

#include "Client.h"
#include <stdlib.h>
#include <stdio.h>

void PrintInfo(struct Client client);

struct ClientList {

    struct Node_Client* head;
    struct Node_Client* tail;

    struct Node_Client {
        struct Client *data;
        struct Node_Client *next;
        struct Node_Client *prev;
    };
};


struct Node_Client* NewClient(){
    struct Node_Client* newClient = (struct Node_Client*) malloc(sizeof(struct Node_Client));
    newClient->next = NULL;
    newClient->prev = NULL;
    return newClient;
}


void AddClient(struct ClientList* list, struct Client* client){

    struct Node_Client* newClient = NewClient();
    newClient->data = (struct Client*) malloc(sizeof(struct Client));
    newClient->data = client;

    if(list->head == NULL){
        list->head = newClient;
        list->tail = list->head;
        return;
    }

    list->head->prev = newClient;
    newClient->next = list->head;
    list->head = newClient;

}


void PrintClients(struct ClientList list){

    printf("\n____Printing Clients____\n");
    if(list.head == NULL){
        printf("Client List is empty!\n");
        return;
    }

    struct Node_Client* temp = list.head;
    while(temp != NULL){
        PrintInfo(*temp->data);
        temp = temp->next;
    }
    printf("________________________\n");
}


int PrintAllNames(struct ClientList list){

    printf("\n____Printing Clients By Name____\n");
    if(list.head == NULL){
        printf("Client List is empty!\n");
        return 0;
    }

    struct Node_Client* temp = list.head;
    int num = 1;
    while(temp != NULL){
        printf("%i. %s\n", num, temp->data->name);
        num ++;
        temp = temp->next;
    }
    printf("________________________\n");

    return num;

}


struct Node_Client* SearchClient(struct ClientList* list, struct Client* man){
    struct Node_Client *temp = list->head;

    while(temp->data != man){
        temp = temp->next;
    }

    if(temp->data == NULL){
        printf("No Client found\n");
        return NULL;
    }

    return temp;
}


struct Node_Client* SearchMan(struct ClientList* list, const char *name){
    struct Node_Client *temp = list->head;


    while(temp->data->name != name){
        temp = temp->next;
    }

    if(temp->data == NULL){
        printf("No Client found\n");
        return NULL;
    }

    return temp;
}



void DeleteClient(struct ClientList* list, struct Client* man){
    struct Node_Client* rmClient = SearchClient(list, man);

    if(rmClient == NULL){
        return;
    }

    if(rmClient == list->tail){
        list->tail->prev->next = NULL;
        list->tail = rmClient->prev;
    }
    else if(rmClient == list->head){
        list->head->next->prev = NULL;
        list->head = rmClient->next;
    }
    else {
        rmClient->next->prev = rmClient->prev;
        rmClient->prev->next = rmClient->next;
    }

    printf("Client %s deleted\n\n", rmClient->data->name);
    free(rmClient);
}


void PrintInfo(struct Client client){
    printf("\tClient: %s\nPassport: %s\n\n", client.name, client.Passport);
}


#endif //C_LANG_CLINTLIST_H
