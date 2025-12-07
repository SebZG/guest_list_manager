#include "funcs.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t *createGuest(float standardPrice, float concessionPrice)
{
    char fName[50] = {0};
    char lName[50] = {0};
    bool isConcession = false;
    bool hasPaid = false;
    float amountPaid = 0.00f;

    char inputTmp[10] = {0};
    char c;

    node_t *newGuest = (node_t *)malloc(sizeof(node_t));
    if (!newGuest)
    {
        perror("malloc");
        return NULL;
    }

    printf("\nGuest's first name: ");
    if (scanf("%49s", fName) != 1)
    {
        free(newGuest);
        return NULL;
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nGuest's last name: ");
    if (scanf("%49s", lName) != 1)
    {
        free(newGuest);
        return NULL;
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    bool validInput = false;
    do
    {
        printf("\nIs concession? (true/false): ");
        if (scanf("%9s", inputTmp) != 1)
        {
            printf("Error reading input. Please try again.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (strcmp(inputTmp, "true") == 0)
        {
            isConcession = true;
            validInput = true;
        }
        else if (strcmp(inputTmp, "false") == 0)
        {
            isConcession = false;
            validInput = true;
        }
        else
        {
            printf("Invalid input. Please enter 'true' or 'false'.\n");
        }
    } while (!validInput);

    validInput = false;
    do
    {
        printf("\nHas paid? (true/false): ");
        if (scanf("%9s", inputTmp) != 1)
        {
            printf("Error reading input. Please try again.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (strcmp(inputTmp, "true") == 0)
        {
            hasPaid = true;
            validInput = true;
            isConcession ? (amountPaid = concessionPrice) : (amountPaid = standardPrice);
        }
        else if (strcmp(inputTmp, "false") == 0)
        {
            hasPaid = false;
            validInput = true;
            amountPaid = 0.00f;
        }
        else
        {
            printf("Invalid input. Please enter 'true' or 'false'.\n");
        }
    } while (!validInput);

    strcpy(newGuest->fName, fName);
    strcpy(newGuest->lName, lName);
    newGuest->isConcession = isConcession;
    newGuest->hasPaid = hasPaid;
    newGuest->amountPaid = amountPaid;

    newGuest->next = NULL;

    return newGuest;
}

node_t *addGuestToHead(node_t *head, node_t *tmp)
{
    tmp->next = head;
    return tmp;
}
