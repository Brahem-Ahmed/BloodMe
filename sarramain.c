#include <stdio.h>
#include <string.h>
#include"sarradonneur.h"

int main()
{
donneur d1={"ali","makni","homme","O+",14562389,22},d2={"emna","ouesleti","femme","O+",13124565,23},d3;
int x ;
x= ajouter("donneur.txt",d1 );

if(x==1)
        printf("\najout de point avec succés");
    else printf("\nechec ajout");


x=modifier("donneur.txt",14562389,d2 );
if(x==1)
        printf("\nModification de point avec succés");
    else printf("\nechec Modification");


x=supprimer("donneur.txt",13124565);
    if(x==1)
        printf("\nSuppression de point avec succés");
    else printf("\nechec Suppression");


d3=chercher("donneur.txt",14562389);
    if(d3.cin==-1)
        printf("introuvable");
    return 0;
}
