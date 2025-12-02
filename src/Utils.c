#include "Utils.h"

void afficher_tableau(int t[], int n)
{
    /**
     * \brief Affiche le tableau donné.
     * \param t Le tableau à afficher.
     * \param n La taille du tableau à afficher.
     */
    if (n > 0 && t != NULL)
    {
        printf("[ ");
        
        // Le dernier élément n'est pas affiché dans cette boucle car son affichage est différent des autres 
        for (int i = 0; (i+1) < n; i++)
        {
            printf("%d, ", t[i]);
        }

        printf("%d ]\n", t[n-1]);
    }
    else
    {
        printf("tableau vide.\n");
    }
}

int entier_aleatoire(int min, int max)
{
    return rand() % (max - min + 1) + min;
}


void test_utils()
{
    /**
     * \brief La fonction de test de la librairie Utils.
     */
    printf("========================== Utils ==========================\n");

    int * tVide = NULL;
    int tNonVide[3] = {1, 2, 3};

    afficher_tableau(tVide, 0);

    afficher_tableau(tNonVide, 3);
}

void genererTableau(int min, int max, int taille, int t[])
{
    for (int i = 0; i < taille; i++)
    {
        t[i] = entier_aleatoire(min, max);
    }    
}