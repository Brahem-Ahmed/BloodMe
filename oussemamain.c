#include <stdio.h>
#include <stdlib.h>
#include "crud.c"

int main()
{
    demande d1 = {{1, 1, 2023}, "ABC123", 5, "A", "No"};
    demande d2 = {{2, 2, 2023}, "XYZ789", 3, "B", "Yes"};

    ajouter(d1);
    ajouter(d2);

    printf("Demandes avant modification :\n");
    // Afficher les demandes avant modification
    FILE *f = fopen("demande.txt", "r");
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    fclose(f);

    // Modifier la demande avec l'ID "ABC123"
    demande nouv_d = {{3, 3, 2023}, "ABC123", 8, "C", "Yes"};
    modifier(nouv_d);

    printf("\n\nDemandes après modification :\n");
    // Afficher les demandes après modification
    f = fopen("demande.txt", "r");
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    fclose(f);

    // Supprimer la demande avec l'ID "XYZ789"
    supprimer("XYZ789");

    printf("\n\nDemandes après suppression :\n");
    // Afficher les demandes après suppression
    f = fopen("demande.txt", "r");
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    fclose(f);

    return 0;
}
