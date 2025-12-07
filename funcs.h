#ifndef FUNCS_H
#define FUNCS_H

#include <stdbool.h>

typedef struct mode
{
    char fname[50];
    char lname[50];
    bool isConsession;
    bool hasPaid;
    float amountPaid;
    struct node *next;
} node_t;

node_t *createGuest(float standardPrice, float concessionPrice);
node_t *addGuestToHead(node_t *head, node_t *newNode);
node_t *autoPopList(node_t *head);
node_t *deleteHead(node_t *head);
void deleteGuestFromPosition(node_t *head, int pos);
node_t *deleteGuest(node_t *head);
void printStats(node_t *head, float standardPrice, float consessionPrice);
void printAllData(node_t *head, float standardPrice, float consessionPrice);

#endif // FUNCS_H
