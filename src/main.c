// #define DEBUG
#define TAILLE 100000

#include <string.h>

#include "TriDenombrement.h"
#include "TriRapide.h"
#include "TriRapideHybride.h"
#include "Utils.h"


void calcul_temps(const int entierMax, int tableau[TAILLE])
{
    // -------------- Dénombrement --------------
    clock_t debutDenombrement = clock();

    int s[TAILLE];

    tri_denombrement(tableau, s, entierMax, TAILLE);

    clock_t finDenombrement = clock();
    
    float tempsDenombrement = (float)(finDenombrement - debutDenombrement) / CLOCKS_PER_SEC;
    printf("Temps de traitement du tri par dénombrement : %f.\n", tempsDenombrement);


    // -------------- Rapide --------------
    clock_t debutRapide = clock();

    int tableau_rapide[TAILLE];
    memcpy(tableau_rapide, tableau, TAILLE * sizeof(int));
    tri_rapide(tableau_rapide, 0, TAILLE-1);

    clock_t finRapide = clock();
    
    float tempsRapide = (float)(finRapide - debutRapide) / CLOCKS_PER_SEC;
    printf("Temps de traitement du tri rapide : %f.\n", tempsRapide);


    // -------------- Rapide hybride --------------
    clock_t debutRapideHybride = clock();

    tri_hybride(tableau, 0, TAILLE-1, TAILLE / 10);

    clock_t finRapideHybride = clock();
    
    float tempsRapideHybride = (float)(finRapideHybride - debutRapideHybride) / CLOCKS_PER_SEC;
    printf("Temps de traitement du tri rapide hybride : %f.\n", tempsRapideHybride);
}

void calculs_temps()
{
    // Premier test
    const int entierMaxTest1 = 10;

    int tableauTest1[TAILLE];
    genererTableau(1, entierMaxTest1, TAILLE, tableauTest1);

    printf("==========================================================================\n");
    printf("== Tri d'un tableau de %d valeurs avec des nombre de 1 à %d\n", TAILLE, entierMaxTest1);
    printf("==========================================================================\n");

    calcul_temps(entierMaxTest1, tableauTest1);


    // Deuxième test
    const int entierMaxTest2 = TAILLE;

    int tableauTest2[TAILLE];
    genererTableau(1, entierMaxTest2, TAILLE, tableauTest2);

    printf("==========================================================================\n");
    printf("== Tri d'un tableau de %d valeurs avec des nombre de 1 à %d\n", TAILLE, entierMaxTest2);
    printf("==========================================================================\n");

    calcul_temps(entierMaxTest2, tableauTest2);

    // Troisième test
    const int entierMaxTest3 = TAILLE;

    int tableauTest3[TAILLE];
    for (int i = 0; i < TAILLE; i++)
    {
        tableauTest3[i] = i+1;
    }
    
    printf("==========================================================================\n");
    printf("== Tri d'un tableau trié de %d valeurs avec des nombre de 1 à %d\n", TAILLE, entierMaxTest3);
    printf("==========================================================================\n");

    calcul_temps(entierMaxTest3, tableauTest3);
}


int main()
{
    srand(time(0)); // nouvelle seed (pour ne pas avoir toujours le meme nombre)

    #ifdef DEBUG
    test_utils();
    test_denombrement();
    test_rapide();
    test_rapide_hybride();
    #endif

    #ifndef DEBUG
    calculs_temps();
    #endif

    return 0;
}



