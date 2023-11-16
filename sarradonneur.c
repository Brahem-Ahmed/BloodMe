#include "sarradonneur.h"

int ajouter(char * filename, donneur d )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %s %s \n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);
        fclose(f);
        return 1;
    }
    else return 0;
}



int modifier( char * filename, int id, donneur nouv )
{
    int tr=0;
    donneur d ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if((f!=NULL) && (f2!=NULL))
    {
        while(fscanf(f,"%s %s %d %d %s %s \n",d.nom,d.prenom,&d.cin,&d.age,d.sexe,d.typs)!=EOF)
        {
            if(d.cin == id)
            {
                fprintf(f2,"%s %s %d %d %s %s \n",nouv.nom,nouv.prenom,nouv.cin,nouv.age,nouv.sexe,nouv.typs);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %s %s \n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);

        }
    }
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt", filename);
return tr;

}


int supprimer(char * filename, int cin)
{
    int tr=0;
    donneur d ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s\n",d.nom,d.prenom,&d.cin,&d.age,d.sexe,d.typs)!=EOF)
        {
            if(d.cin == cin)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %s %s\n",d.nom,d.prenom,d.cin,d.age,d.sexe,d.typs);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}




donneur chercher(char * filename, int cin)
{
    donneur d;
    int tr=0 ;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %s %s\n",d.nom,d.prenom,&d.cin,&d.age,d.sexe,d.typs)!=EOF)
        {
            if(d.cin== cin)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        d.cin=-1;
    return d;

}



