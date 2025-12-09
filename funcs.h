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

typedef enum MenuOption
{
    MENU_ADD_GUEST = 1,
    MENU_UPDATE_GUEST = 2,
    MENU_DELETE_GUEST = 3,
    MENU_PRINT_STATS = 4,
    MENU_PRINT_GUESTS = 5,
    MENU_PRINT_ALL = 6,
    MENU_AUTO_POPULATE = 7,
    MENU_QUIT = 8
} MenuOption;

typedef enum UpdateGuest
{
    UPDATE_FNAME = 1,
    UPDATE_LNAME = 2,
    UPDATE_CONCESSION = 3,
    UPDATE_PAID = 4,
    UPDATE_QUIT = 5
} UpdateGuest;

node_t *createGuest(float standardPrice, float concessionPrice);
node_t *addGuestToHead(node_t *head, node_t *tmp);
node_t *updateGuest(node_t *head, char *fName, char *lName, float standardPrice, float concessionPrice);
node_t *deleteGuest(node_t *head, char *fName, char *lName, float standardPrice, float concessionPrice);
node_t *op(node_t *(*action)(node_t *, char *, char *, float, float),
           node_t *head,
           float standardPrice,
           float concessionPrice);
void printStats(node_t *head, float standardPrice, float concessionPrice);
void printGuests(node_t *head, float standardPrice, float concessionPrice);
void printAllData(node_t *head, float standardPrice, float concessionPrice);
node_t *autoPopList(node_t *head, float standardPrice, float concessionPrice);

#endif // FUNCS_H
