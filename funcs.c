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
    int c;

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

node_t *updateGuest(node_t *head, char *fName, char *lName, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;

    int c;
    char input[10];

    while (tmp != NULL)
    {
        if (strcmp(tmp->fName, fName) == 0 && strcmp(tmp->lName, lName) == 0)
        {
            printf("\nGuest found.\n");
            while (1)
            {
                printf("\n'%d' to: update first name", UPDATE_FNAME);
                printf("\n'%d' to: update last name", UPDATE_LNAME);
                printf("\n'%d' to: update is concession", UPDATE_CONCESSION);
                printf("\n'%d' to: update has paid", UPDATE_PAID);
                printf("\n'%d' to: quit to main menu\n", UPDATE_QUIT);

                int userSelect;
                if (scanf("%d", &userSelect) != 1)
                {
                    printf("Please enter a number.\n");
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    continue;
                }
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                switch (userSelect)
                {
                case UPDATE_FNAME:
                    printf("\nFirst name: ");
                    if (scanf("%49s", tmp->fName) != 1)
                    {
                        printf("Error reading input.\n");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                    }
                    else
                    {
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                        printf("First name updated.\n");
                    }
                    break;
                case UPDATE_LNAME:
                    printf("\nLast name: ");
                    if (scanf("%49s", tmp->lName) != 1)
                    {
                        printf("Error reading input.\n");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                    }
                    else
                    {
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                        printf("Last name updated.\n");
                    }
                    break;
                case UPDATE_CONCESSION:
                    printf("\nIs concession (true/false): ");
                    if (scanf("%9s", input) != 1)
                    {
                        printf("Error reading input.\n");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                    }
                    else
                    {
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                        if (strcmp(input, "true") == 0)
                        {
                            tmp->isConcession = true;
                            // If they've already paid, update the amount
                            if (tmp->hasPaid)
                            {
                                tmp->amountPaid = concessionPrice;
                                printf("Concession status updated. Amount adjusted to: %.2f\n", tmp->amountPaid);
                            }
                            else
                            {
                                printf("Concession status updated.\n");
                            }
                        }
                        else if (strcmp(input, "false") == 0)
                        {
                            tmp->isConcession = false;
                            // If they've already paid, update the amount
                            if (tmp->hasPaid)
                            {
                                tmp->amountPaid = standardPrice;
                                printf("Concession status updated. Amount adjusted to: %.2f\n", tmp->amountPaid);
                            }
                            else
                            {
                                printf("Concession status updated.\n");
                            }
                        }
                        else
                            printf("Invalid input. Keeping current value.\n");
                    }
                    break;
                case UPDATE_PAID:
                    printf("\nHas paid (true/false): ");
                    if (scanf("%9s", input) != 1)
                    {
                        printf("Error reading input.\n");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                    }
                    else
                    {
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                        if (strcmp(input, "true") == 0)
                        {
                            tmp->hasPaid = true;
                            // Update amount based on concession status
                            if (tmp->isConcession)
                                tmp->amountPaid = concessionPrice;
                            else
                                tmp->amountPaid = standardPrice;
                            printf("Payment status updated. Amount: %.2f\n", tmp->amountPaid);
                        }
                        else if (strcmp(input, "false") == 0)
                        {
                            tmp->hasPaid = false;
                            tmp->amountPaid = 0.0f;
                            printf("Payment status updated. Amount: %.2f\n", tmp->amountPaid);
                        }
                        else
                            printf("Invalid input. Keeping current value.\n");
                    }
                    break;
                case UPDATE_QUIT:
                    printf("Returning to main menu...\n");
                    return head;
                default:
                    printf("\nInvalid Selection.\n");
                }
            }
        }

        tmp = tmp->next;
    }

    if (tmp == NULL)
        printf("\nGuest not found.\n");

    return head;
}

node_t *deleteGuest(node_t *head, char *fName, char *lName, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;
    node_t *prev = NULL;
    int idx = 0;
    // int c;

    char *isTrue = "true";
    char *isFalse = "false";

    while (tmp != NULL)
    {
        if (strcmp(tmp->fName, fName) == 0 && strcmp(tmp->lName, lName) == 0)
        {
            printf("\nFirst name:     %15s", tmp->fName);
            printf("\nLast name:      %15s", tmp->lName);
            printf("\nIs concession:  %15s", tmp->isConcession ? isTrue : isFalse);
            printf("\nHas paid:       %15s", tmp->hasPaid ? isTrue : isFalse);
            printf("\nAmount paid:    %15.2f\n", tmp->amountPaid);

            // Perform deletion
            if (idx == 0)
            {
                head = head->next;
                free(tmp);
                printf("Guest Deleted.\n");
                break;
            }

            prev->next = tmp->next;
            free(tmp);
            printf("Guest Deleted.\n");
            break;
        }
        prev = tmp;
        tmp = tmp->next;
        idx++;
    }

    if (tmp == NULL)
        printf("\nGuest not found.\n");

    return head;
}

node_t *op(node_t *(*action)(node_t *, char *, char *, float, float),
           node_t *head,
           float standardPrice,
           float concessionPrice)
{
    if (head == NULL)
    {
        printf("\nNo Guests in the list.\n");
        return head;
    }

    char fName[50] = {0};
    char lName[50] = {0};
    int c;

    printf("\nGuest's first name: ");
    if (scanf("%49s", fName) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return head;
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nGuest's last name: ");
    if (scanf("%49s", lName) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return head;
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    return action(head, fName, lName, standardPrice, concessionPrice);
}

void printStats(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;
    if (tmp == NULL)
    {
        printf("\nNo guests in the list.\n");
        return;
    }

    int totalGuests = 0;
    float totalPaid = 0;
    float totalOwed = 0;

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

void printGuests(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;
    if (tmp == NULL)
    {
        printf("\nNo guests in the list.\n");
        return;
    }

    int totalGuests = 0;
    float totalPaid = 0;
    float totalOwed = 0;

    char *isTrue = "true";
    char *isFalse = "false";

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
}

void printAllData(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *tmp = head;
    if (tmp == NULL)
    {
        printf("\nNo guests in the list.\n");
        return;
    }

    printGuests(head, standardPrice, concessionPrice);
    printStats(head, standardPrice, concessionPrice);
}

node_t *autoPopList(node_t *head, float standardPrice, float concessionPrice)
{
    node_t *newGuest;
    // node_t *tmp = head;

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName1");
    strcpy(newGuest->lName, "lName1");
    newGuest->isConcession = true;
    newGuest->hasPaid = true;
    newGuest->amountPaid = newGuest->isConcession ? concessionPrice : standardPrice;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName2");
    strcpy(newGuest->lName, "lName2");
    newGuest->isConcession = false;
    newGuest->hasPaid = false;
    newGuest->amountPaid = 0.00f;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName3");
    strcpy(newGuest->lName, "lName3");
    newGuest->isConcession = false;
    newGuest->hasPaid = true;
    newGuest->amountPaid = newGuest->isConcession ? concessionPrice : standardPrice;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName4");
    strcpy(newGuest->lName, "lName4");
    newGuest->isConcession = true;
    newGuest->hasPaid = false;
    newGuest->amountPaid = 0.00f;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName5");
    strcpy(newGuest->lName, "lName5");
    newGuest->isConcession = false;
    newGuest->hasPaid = true;
    newGuest->amountPaid = newGuest->isConcession ? concessionPrice : standardPrice;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    newGuest = (node_t *)malloc(sizeof(node_t));

    strcpy(newGuest->fName, "fName6");
    strcpy(newGuest->lName, "lName6");
    newGuest->isConcession = true;
    newGuest->hasPaid = true;
    newGuest->amountPaid = newGuest->isConcession ? concessionPrice : standardPrice;
    newGuest->next = NULL;
    head = addGuestToHead(head, newGuest);

    return head;
}
