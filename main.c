#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct mesh
{
    int id;
}mesh;

typedef struct element
        {
                mesh gear;
                struct element *preced;
                struct element *suiv;
        } element ;


typedef struct
        {
          element *prems;
          element *dernier;
        }liste;


void Init(liste *);

void insertBas(liste *, int val);

void insertHaut(liste *, int val);

void affichage(liste x);

void supressionHaut(liste *);

void supressionBas(liste *);

//void InsertionCentre(liste *, int val);


//---------------------------------------------------------------------------//

int main()
{
    liste listeBase;

    Init(&listeBase);

    printf("Insertion de mesh en servant de leur id(voir type structure).\n");
    printf("On insere en haut l'id 4, en bas l'id 12, encore en bas, l'id 8 et on insere en haut l'id 6. \n");

    insertHaut(&listeBase,4);
    insertBas(&listeBase,12);
    insertBas(&listeBase,8);
    insertHaut(&listeBase,6);

    affichage(listeBase);

    printf("\n");

    printf("Supression de la mesh du haut.\n");

    supressionHaut(&listeBase);

    affichage(listeBase);

    printf("\n");

    printf("Supression de la mesh du bas.\n");

    supressionBas(&listeBase);

    affichage(listeBase);

    printf("\n");

    printf("Insertion d une mesh en bas.\n");

    insertBas(&listeBase,24);

    affichage(listeBase);

    //InsertionCentre(&listeBase,2);

    return 0;
}


//---------------------------------------------------------------------------//


void Init(liste *x)
{
   x->prems = NULL;
   x->dernier = NULL;
}


void insertBas(liste *x, int val)
{
   element *nouv = malloc(sizeof(element));

   if(!nouv)
   {
        exit(EXIT_FAILURE);
   }

   nouv->gear.id = val;
   nouv->preced = x->dernier;
   nouv->suiv = NULL;

   if(x->dernier)
   {
       x->dernier->suiv = nouv;
   }
    else
    {
        x->prems = nouv;
    }

    x->dernier = nouv;

}

void insertHaut(liste *x, int val)
{
   element *nouv = malloc(sizeof(element));

   if(!nouv)
    {
        exit(EXIT_FAILURE);
    }

   nouv->gear.id = val;
   nouv->suiv = x->prems;
   nouv->preced = NULL;

   if(x->prems)
   {
       x->prems->preced = nouv;
   }
   else
   {
       x->dernier = nouv;
   }

   x->prems= nouv;
}


void affichage(liste x)
{
   element *Xelem = x.prems;
   while(Xelem)
   {
     printf("%d\n",Xelem->gear.id);
     Xelem = Xelem->suiv;
   }
}

void supressionHaut(liste *x)
{
    if (x==NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (x->prems != NULL)
    {
        element *aSupprimer = x->prems;   //pointe le premier de la pile qui est à supprimer
        x->prems = x->prems->suiv;
        x->prems->preced = NULL;          //le nombre qui le suivait deviens le premier
        free(aSupprimer);                   //la fonction (free) directement intégrer au C supprime la valeure
    }
}

void supressionBas(liste *x)
{
    if (x == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (x->dernier != NULL)
    {
        element *aSupprimer = x->dernier;
        x->dernier = x->dernier->preced;
        x->dernier->suiv = NULL;
        free(aSupprimer);
    }
}

/*void InsertionCentre(liste *x, int val)   //Tentative d'insertion au centre
{
    int i;

    element *nouv = malloc(sizeof(element));

   for(i=0;i<liste/2;i++)
   {
       if(!nouv)
        {
            exit(EXIT_FAILURE);
        }

       nouv->gear.id = val;
       nouv->suiv = x->suiv;
       nouv->preced = x->preced;
   }

}*/
