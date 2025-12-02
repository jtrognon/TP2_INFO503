#include "TriDenombrement.h"
// #define DEBUG

int tri_denombrement(int t[], int s[], int k, int n)
{
    /**
     * \brief Implémentation de l'algorithme de tri par dénombrement.
     * \param t Tableau à trier.
     * \param s Tableau trié.
     * \param k Borne supérieure de l'intervale.
     * \param n Taille des tableaux 't' et 's'.
     */

    if (n > 0 && k > 0 && k <= n)
    {
        // Le language C ne contient pas de tableaux commençant à l'indice 1.
        // Ainsi, quand les valeurs du tableau 't' seront utilisées pour accéder au tableau 'aux', 
        // il faudra soustraire 1 et ajouter 1 lors de la récupération des valeurs.
        int aux[k];
        
        // Mise à zéro du tableau auxiliaire 'aux'.
        for (int i = 0; i < k; i++)
        {
            aux[i] = 0;
        }

        // Pour chaque case, on ajoute le nombre de valeurs égales à l'indice de celle-ci. 
        // Et on vérifie que la valeur contenue dans 't' est valide (entre 1 et k compris)
        for (int j = 0; j < n; j++)
        {
            // Vérifie la validité des valeurs
            if (t[j] < 1 || t[j] > k)
            {
                printf("Le tableau contient une valeur non-conforme (val < 1 ou val > k), k : %d, val : %d\n", k, t[j]);
                exit(EXIT_FAILURE);
            }

            aux[t[j]-1] += 1;
        }
        
        // Pour chaque case, on ajoute au résultat précédent le nombre de valeurs inférieures à l'indice de celle-ci. 
        for (int i = 1; i < k; i++)
        {
            aux[i] += aux[i-1];
        }
        
        // -------------
        // A présent, la valeur d'aux[t[j]] est l'indice le plus élevé où l'on peut trouver t[j] dans le tableau de sortie 's'.
        // -------------

        // Ajout à la bonne place de chaque valeur de t[j] dans le tableau 's'
        // On part de la fin pour préserver l'ordre des valeurs égales
        // les premières placées sont à droite des dernières 
        for (int j = n-1; j >= 0; j--)
        {
            #ifdef DEBUG
            printf("\t- i_départ : %d, val_t : %d, i_aux: %d, val_aux : %d, i_final : %d\n", j, t[j], t[j]-1, aux[t[j]-1], aux[t[j]-1]-1);
            #endif

            s[aux[t[j]-1]-1] = t[j]; // t[j] -1  car 1 <= t[j] <= n 
            aux[t[j]-1] -= 1; // nécéssaire pour les valeurs égales à t[j]
        }
    }
    else if (n != 0 || k != 0)
    {
        fprintf(stderr, "tri_denombrement: Les valeurs de 'k' et/ou 'n' ne sont pas correctes.\n\t- Valeur attendues : 'n' >= 1, 'k' >= 1\n\t- Valeur reçues : 'n' = %d, 'k' = %d\n", n, k);
        
        exit(EXIT_FAILURE);
    }
}

void test_denombrement()
{
    /**
     * \brief Tests de la librairie Denombrement.
     */

    printf("========================== Tri de dénombrement ==========================\n");

    int s[10];

    // Tableau de départ vide
    tri_denombrement(NULL, s, 0, 0);

    // k > taille max du tableau
    // tri_denombrement(NULL, s, 1, 0); // Erreur -> normal car incorrect

    // Valeur max = taille max du tableau
    int t1[10] = {6, 2, 4, 1, 10, 2, 4, 5, 7, 9};
    
    printf("entrée : ");
    afficher_tableau(t1, 10);
    
    tri_denombrement(t1, s, 10, 10);
    
    printf("sortie : ");
    afficher_tableau(s, 10);
    printf("\n");

    // Valeur max < taille max du tableau
    int t2[10] = {6, 2, 4, 1, 6, 2, 4, 5, 7, 9};
    
    printf("entrée : ");
    afficher_tableau(t2, 10);
    
    tri_denombrement(t2, s, 9, 10);
    
    printf("sortie : ");
    afficher_tableau(s, 10);

    // Valeur max > k
    // tri_denombrement(t2, s, 8, 10); // Erreur -> normal
}