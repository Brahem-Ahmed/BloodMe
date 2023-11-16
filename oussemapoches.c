#include<stdio.h>
#include<string.h>
#include "fichier.h"



void ajouter(demande d)
{
    FILE *f = fopen("demande.txt", "a+");
    if (f != NULL)
    {
        fprintf(f, "%d %d %d %s %d %s %s\n", d.d_d.jour, d.d_d.mois, d.d_d.annee, d.id, d.NbrePoches, d.type, d.urgent);
    }
    fclose(f);
}

void modifier(demande nouv_d)
{
    int tr = 0;
    demande d;
    FILE *f, *f2;
    f = fopen("demande.txt", "r");
    f2 = fopen("nouv_d.txt", "w+");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %d %s %d %s %s\n", &d.d_d.jour, &d.d_d.mois, &d.d_d.annee, d.id, &d.NbrePoches, d.type, d.urgent) != EOF)
        {
            if (strcmp(d.id, nouv_d.id) == 0)
            {
                fprintf(f2, "%d %d %d %s %d %s %s\n", nouv_d.d_d.jour, nouv_d.d_d.mois, nouv_d.d_d.annee, nouv_d.id, nouv_d.NbrePoches, nouv_d.type, nouv_d.urgent);
                tr = 1;
            }
            else
                fprintf(f2, "%d %d %d %s %d %s %s\n", d.d_d.jour, d.d_d.mois, d.d_d.annee, d.id, d.NbrePoches, d.type, d.urgent);
        }
    }
    fclose(f);
    fclose(f2);
    remove("demande.txt");
    rename("nouv_d.txt", "demande.txt");
}

void supprimer(char id[20])
{
    int tr = 0;
    demande d;
    FILE *f = fopen("demande.txt", "r");
    FILE *f2 = fopen("nouv_d.txt", "w+");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %d %s %d %s %s\n", &d.d_d.jour, &d.d_d.mois, &d.d_d.annee, d.id, &d.NbrePoches, d.type, d.urgent) != EOF)
        {
            if (strcmp(d.id, id) == 0)
            {
                tr = 1;
            }
            else
                fprintf(f2, "%d %d %d %s %d %s %s\n", d.d_d.jour, d.d_d.mois, d.d_d.annee, d.id, d.NbrePoches, d.type, d.urgent);
        }
    }
    fclose(f);
    fclose(f2);
    remove("demande.txt");
    rename("nouv_d.txt", "demande.txt");
}
