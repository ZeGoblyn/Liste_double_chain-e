#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct mesh     //Création du type mesh
{
    int id;
}mesh;

typedef struct element  //Création du type élément contenant la mesh et les pointeurs de repérages
        {
                mesh gear;
                struct element *preced;
                struct element *suiv;
        } element ;


typedef struct          //Création de la liste et de ces pointeurs
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


void Init(liste *x)             //Initialisation des extremité de la liste
{
   x->prems = NULL;
   x->dernier = NULL;
}


void insertBas(liste *x, int val)
{
   element *nouv = malloc(sizeof(element));         //allocation espace mémoire

   if(!nouv)
   {
        exit(EXIT_FAILURE);
   }

   nouv->gear.id = val;                                //insertion de la valeur d'identification de la mesh
   nouv->preced = x->dernier;                          //Le pointeur vers l'élement précédent prend l'élément qui était le dernier
   nouv->suiv = NULL;                                  //Etant le dernier de la liste, il pointe vers NULL

   if(x->dernier)
   {
       x->dernier->suiv = nouv;
   }
    else
    {
        x->prems = nouv;
    }

    x->dernier = nouv;                                  //Le nouvelle élément est pointer comme dernier de la liste

}

void insertHaut(liste *x, int val)
{
   element *nouv = malloc(sizeof(element));

   if(!nouv)
    {
        exit(EXIT_FAILURE);
    }

   nouv->gear.id = val;                                 //insertion de la valeur d'identification de la mesh
   nouv->suiv = x->prems;                               //Le pointeur vers l'élement suivant prend l'élément qui était le premier
   nouv->preced = NULL;                                 //Etant le premier de la liste, il pointe vers NULL

   if(x->prems)
   {
       x->prems->preced = nouv;
   }
   else
   {
       x->dernier = nouv;
   }

   x->prems= nouv;                                      //Le nouvelle élément est pointer comme premier de la liste
}


void affichage(liste x)
{
   element *Xelem = x.prems;
   while(Xelem)
   {
     printf("%d\n",Xelem->gear.id);                     //Affichage de l'identifiant de la mesh
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
        element *aSupprimer = x->prems;   //pointe le premier element, désigner comme à supprimer
        x->prems = x->prems->suiv;
        x->prems->preced = NULL;          //le nombre qui le suivait deviens le premier
        free(aSupprimer);                 //la fonction (free) directement intégrer au C supprime la valeure
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
        element *aSupprimer = x->dernier;   //pointe le dernier element, désigner comme à supprimer
        x->dernier = x->dernier->preced;
        x->dernier->suiv = NULL;            //le nombre qui le precède deviens le dernier
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
