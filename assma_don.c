#include "don.h"
#include<string.h>

int ajouter_don(char *don, don d)
{
   FILE *f=fopen(don,"a");
   if(f!=NULL)
   {
     fprintf(f,%d %s%d\n",d.id_donneur, d.type_sang,d.quantite_sang);
     fclose(f);
     return 1;
   }
   else return 0;
}
int modifier_don(char *don,char * id_donneur,don nouv)
{
    int tr=0;
    don d;
    FILE *f=fopen(don,"r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
       while(fscanf(f,"%d %s %d \n",&d.id_donneur,&d.type_sang,&d.quantite)!=EOF)
       {
         if(strcmp(d.id_donneur,id_donneur)==0)
         {
            fprintf(f2,"%d %S%d \n" ,nouv.id_donneur,nouv.type_sang,nouv.quantite);
            tr=1;
         }
         else 
           fprintf(f2,"%d %s %d \n",d. Id_donneur,d. type_sang,d.quantite);
      }
    }
    fclose(f);
    fclose(f2);
    remove(don);
    rename("nouv.txt",don);
    return tr;
}
int supprimer_don(char *don,char * id_donneur)
{
   int tr=0;
   don p;
   FILE *f=fopen(don,"r");
   FILE *f2=fopen("nouv.txt","w");
   if(f!=NULL && f2!=NULL)
   {
      while(fscanf(f,"%s %d %d\n",&d.id_donneur,&d.type_sang,&d.quantite)!=EOF)
      {
        if(strcmp(d.id_donneur,id_donneur)==0)
            tr=1;
        else
           fprintf(f2,"%d%s%d\n",d.id_donneur,d.type_sang,d.quantite);

      }
    }
    fclose(f);
    fclose(f2);
    remove(don);
    rename("nouv.txt",don);
    return tr;
}      
don chercher_don(char *don, char * id_donneur)
{
    don d;
    int tr=0;
    FILE *f=fopen(don,"r");
    if(f!=NULL)
    {
    while(tr==0&& fscanf(f,"%d%s %d \n",&d.id_donneur, & d.type_sang,&d.quantite)!=EOF)
       { 
         if(strcmp(d.id_donneur,id_donneur)==0)
            tr=1;
       }
    }
    fclose(f);
    if(tr==0)
       strcpy(d.id_donneur,"-1");
    return d;
}
