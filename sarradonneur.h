#ifndef SARRADONNEUR_H
#define SARRADONNEUR_H
#include <stdio.h>
typedef struct
{
    char nom [20],prenom [20],sexe[6],typs[20];
    int cin, age;
} donneur;

int ajouter(char *, donneur );
int modifier( char *, int, donneur );
int supprimer(char *, int );
donneur chercher(char *, int);
#endif
