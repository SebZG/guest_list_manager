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

node_t *deleteGuest(node_t *head)
{
    if (head == NULL)
    {
        printf("\nNo Guests in the list.\n");
        return head;
    }

    node_t *tmp = head;
    node_t *prev = NULL;
    char fName[50] = {0};
    char lName[50] = {0};
    int idx = 0;
    char c;

    printf("\nGuest's first name: ");
    if (scanf("%49s", fName) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return head;
    }

    printf("\nGuest's last name: ");
    if (scanf("%49s", lName) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return head;
    }

    while (tmp != NULL)
    {
        if (strcmp(tmp->fName, fName) == 0 && strcmp(tmp->lName, lName) == 0)
        {
            printf("\nGuest found...\n");
            if (idx == 0)
            {
                head = head->next;
                free(tmp);
                printf("Guest Deleted.\n");
                break;
            }
            else
            {
                prev->next = tmp->next;
                free(tmp);
                printf("Guest Deleted.\n");
                break;
            }
        }
        prev = tmp;
        tmp = tmp->next;
        idx++;
    }

    if (tmp == NULL)
        printf("\nGuest not found.\n");

    return head;
}

void printStats(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;

    int totalGuests = 0;
    float totalPaid = 0;
    float totalOwed = 0;

    if (tmp == NULL)
    {
        printf("\nNo guests in the list.\n");
        return;
    }

    while (tmp != NULL)
    {
        totalGuests++;

        if (!tmp->hasPaid)
            if (tmp->isConcession)
                totalOwed += concessionPrice;
            else
                totalOwed += standardPrice;
        else
            totalPaid += tmp->amountPaid;

        tmp = tmp->next;
    }

    printf("\n--------------------------------\n");
    printf("Total GUESTS:   %15d\n", totalGuests);
    printf("Total OWED:     %15.2f\n", totalOwed);
    printf("Total PAID:     %15.2f\n", totalPaid);
    printf("Total EXPECTED: %15.2f\n", totalPaid + totalOwed);
    printf("--------------------------------\n");
}

void printAllData(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;

    int totalGuests = 0;
    float totalPaid = 0;
    float totalOwed = 0;

    char *isTrue = "true";
    char *isFalse = "false";

    if (tmp == NULL)
    {
        printf("\nNo guests in the list.\n");
        return;
    }

    printf("\n--------------------------------");
    while (tmp != NULL)
    {
        printf("\nFirst name:     %15s", tmp->fName);
        printf("\nLast name:      %15s", tmp->lName);
        printf("\nIs concession:  %15s", tmp->isConcession ? isTrue : isFalse);
        printf("\nHas paid:       %15s", tmp->hasPaid ? isTrue : isFalse);
        printf("\nAmount paid:    %15.2f\n", tmp->amountPaid);

        totalGuests++;

        if (!tmp->hasPaid)
        {
            if (tmp->isConcession)
            {
                totalOwed += concessionPrice;
            }
            else
            {
                totalOwed += standardPrice;
            }
        }
        else
        {
            totalPaid += tmp->amountPaid;
        }

        tmp = tmp->next;
    }

    printf("--------------------------------\n");
    printf("Total GUESTS:   %15d\n", totalGuests);
    printf("Total OWED:     %15.2f\n", totalOwed);
    printf("Total PAID:     %15.2f\n", totalPaid);
    printf("Total EXPECTED: %15.2f\n", totalPaid + totalOwed);
    printf("--------------------------------\n");
}
