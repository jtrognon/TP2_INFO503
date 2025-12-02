#include "TriRapideHybride.h"
// #define DEBUG

void permuter_h(int *i, int *j) {
    /**
    * \brief Permutte deux valeurs
    * 
    * \param i Première valeur
    * \param j Deuxième valeur
    */
    int tmp = *i;
    
    *i = *j;
    
    *j = tmp;
}



int median_h(int t[],int i,int j,int k){
    /**
    * \brief Calcule la valeur médiane 
    * 
    * \param t Le tableau
    * \param i La borne minimale
    * \param j La borne maximale
    * \param k Le borne intermédiaire
    * \return int Le médian
    */
    int median;

    int a = t[i];
    int b = t[j];
    int c = t[k];

    if((a <= b && b <= c) || (a >= b && b >= c)){
        median = j;
    }

    else if ((a >= b && a <= c) || (a <= b && a >= c))
    {
        median = i;
    }

    else if ((c >= a && c <= b) || (c >= b && c <= a))
    {
        median = k;
    }
    
    
    

    return median;
    
  
}


void partition_h(int t[],int i,int j,int *k){
    /**
    * \brief Effectue le partionnement autour du pivot qui se trouve à la fin à l'indice k
    * 
    * \param t Le tableau
    * \param i La borne minimale du tableau
    * \param j La borne maximale du tableau
    * \param k Le pivot
    */


    permuter_h(&t[i],&t[median_h(t,i,j,(i+j)/2)]);

    int l = i+1;
    int pivot = j;

    while(l <= pivot){
        while (t[pivot] > t[i] && l <= pivot)
        {
            pivot--;
        }

        while (t[l]<= t[i] && l <= pivot)
        {
            l++;
        }


        if(l < pivot){
            permuter_h(&t[l],&t[pivot]);
            l++;
            pivot--;
        }
    }
    permuter_h(&t[i],&t[pivot]);
    *k = pivot;
}

void tri_insertion(int t[],int i,int j){
    /**
    * \brief Implémentation de l'algorithme de tri par insertion séquentielle
    * 
    * \param t Le tableau à trier
    * \param i La borne minimale
    * \param j La borne maximale
    */
   

    if(i < j){
        int k = 0;
        int x;
        tri_insertion(t,i,j-1);

        k = j-1;
        x = t[j];

        while (k >= i && t[k] > x)
        {
            t[k+1] = t[k];
            k--;
        }

        t[k+1] = x;
     }
        

    
}

void tri_hybride(int t[],int i,int j,int seuil){
    /**
    * \brief Implémentation de l'algorithme de tri rapide hybride
    * 
    * \param t Le tableau à trier
    * \param i La borne minimale du tableau
    * \param j La borne maximale du tableau
    * \param seuil La taille minimale d’une partition pour appliquer le tri rapide
    */
   

    if(i < j){
        if(j - i > seuil){
            int k;
            
            #ifdef DEBUG
            printf("-- Utilisation du tri rapide --\n");
            #endif
            
            partition_h(t,i,j,&k);
            tri_hybride(t,i,k-1,seuil);
            tri_hybride(t,k+1,j,seuil);
            
            #ifdef DEBUG
            afficher_tableau(t,j-i+1);
            #endif

        }else{
            
            #ifdef DEBUG
            printf("-- Utilisation du tri par insertion --\n");
            #endif
            
            tri_insertion(t,i,j);
            
            #ifdef DEBUG
            afficher_tableau(t,j-i+1);
            #endif
        }
    }




}



void test_rapide_hybride(){
    /**
     * \brief Tests de la librairie RapideHybride.
     */
    printf("========================== Tri rapide hybride ==========================\n\n");

    //Tableau avec 5 éléments
    int tab[5] = {2,1,3,6,5};
    printf("entrée :");
    afficher_tableau(tab,5);
    tri_hybride(tab,0,4,5);
    printf("sortie :");
    afficher_tableau(tab,5);
   
    printf("\n\n");

    //Tableau avec 1 élément
    int tab2[1] = {1};
    printf("entrée :");
    afficher_tableau(tab2,1);
    tri_hybride(tab2,0,0,5);
    printf("sortie :");
    afficher_tableau(tab2,1);

    printf("\n\n");

    //Tableau avec 10 éléments
    int tab3[10] = {2,1,4,3,8,6,5,7,10,9};
    printf("entrée :");
    afficher_tableau(tab3,10);
    tri_hybride(tab3,0,9,5);
    printf("sortie :");
    afficher_tableau(tab3,10);
}