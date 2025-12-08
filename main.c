#include "funcs.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    node_t *tmp = NULL;
    node_t *head = NULL;

    float standardPrice = 0.00f;
    float concessionPrice = 0.00f;

    char c;

    bool validInput = false;
    do
    {
        printf("Set standard price: ");
        if (scanf("%f", &standardPrice) != 1 || standardPrice < 0)
        {
            printf("Invalid input. Please enter a positive amount.\n\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else
        {
            validInput = true;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    } while (!validInput);

    validInput = false;
    do
    {
        printf("Set concession price: ");
        if (scanf("%f", &concessionPrice) != 1 || concessionPrice < 0)
        {
            printf("Invalid input. Please enter a positive amount.\n\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else if (concessionPrice >= standardPrice)
        {
            printf("Concession price cannot exceed standard price.\n\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else
        {
            validInput = true;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    } while (!validInput);

    while (1)
    {
        printf("\n'%d' to: Add a guest", MENU_ADD_GUEST);
        printf("\n'%d' to: Update a guest", MENU_UPDATE_GUEST);
        printf("\n'%d' to: Delete a guest", MENU_DELETE_GUEST);
        printf("\n'%d' to: Print stats", MENU_PRINT_STATS);
        printf("\n'%d' to: Print guests & stats", MENU_PRINT_ALL);
        printf("\n'%d' to: Auto populate list", MENU_AUTO_POPULATE);
        printf("\n'%d' to: Quit\n", MENU_QUIT);

        int userSelect;
        if (scanf("%d", &userSelect) != 1)
        {
            printf("Please enter a number.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        switch (userSelect)
        {
        case MENU_ADD_GUEST:
            tmp = createGuest(standardPrice, concessionPrice);
            head = addGuestToHead(head, tmp);
            break;
        case MENU_UPDATE_GUEST:
            head = op(updateGuest, head, standardPrice, concessionPrice);
            break;
        case MENU_DELETE_GUEST:
            head = op(deleteGuest, head, standardPrice, concessionPrice);
            break;
        case MENU_PRINT_STATS:
            printStats(head, standardPrice, concessionPrice);
            break;
        case MENU_PRINT_ALL:
            printAllData(head, standardPrice, concessionPrice);
            break;
        case MENU_AUTO_POPULATE:
            head = autoPopList(head, standardPrice, concessionPrice);
            break;
        case MENU_QUIT:
            printf("\nQuitting program...\n");
            while (head)
            {
                node_t *tmp = head;
                head = head->next;
                free(tmp);
            }
            return 0;
        default:
            printf("\nInvalid Seleciton.\n");
        }
    }

    return 0;
}
