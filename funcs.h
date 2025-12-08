#ifndef FUNCS_H
#define FUNCS_H

#include <stdbool.h>

typedef struct Node
{
    char fName[50];
    char lName[50];
    bool isConcession;
    bool hasPaid;
    float amountPaid;
    struct Node *next;
} node_t;

node_t *createGuest(float standardPrice, float concessionPrice);
node_t *addGuestToHead(node_t *head, node_t *tmp);
node_t *deleteGuest(node_t *head);
void printStats(node_t *head, float standardPrice, float concessionPrice);
void printAllData(node_t *head, float standardPrice, float concessionPrice);
node_t *autoPopList(node_t *head, float standardPrice, float concessionPrice);

#endif // FUNCS_H
