#include "TriRapide.h"
// #define DEBUG


void permuter(int *i, int *j) {
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



int median(int t[],int i,int j,int k){
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


void partition(int t[],int i,int j,int *k){
    /**
    * \brief Effectue le partionnement autour du pivot qui se trouve à la fin à l'indice k
    * 
    * \param t Le tableau
    * \param i La borne minimale du tableau
    * \param j La borne maximale du tableau
    * \param k Le pivot
    */


    permuter(&t[i],&t[median(t,i,j,(i+j)/2)]);

    int l = i+1;
    int pivot = j;

    while(l <= pivot){
        while (l <= pivot && t[pivot] > t[i])
        {
            pivot--;
        }

        while (l <= pivot && t[l]<= t[i] )
        {
            l++;
        }


        if(l < pivot){
            permuter(&t[l],&t[pivot]);
            l++;
            pivot--;
        }
    }
    permuter(&t[i],&t[pivot]);
    *k = pivot;
}






void tri_rapide(int tab[],int i,int j){
    /**
    * \brief Implémentation de l'algorithme de tri rapide.
    * 
    * \param tab Le tableau à trier
    * \param i La borne minimale du tableau
    * \param j La borne maximale du tableau
    */
   

    if(i < j){
        int k;
        partition(tab,i,j,&k);
        
        #ifdef DEBUG
        printf("Pivot : %d\n",k);
        #endif
        
        tri_rapide(tab,i,k-1);
        tri_rapide(tab,k+1,j);
    }


}


void test_rapide(){
    /**
     * \brief Tests de la librairie Rapide.
     */
    printf("========================== Tri rapide ==========================\n\n");

    //Tableau avec 5 éléments
    int tab[5] = {2,1,3,6,5};
    printf("Tableau de 5 éléments:\n\n");
    printf("entrée :");
    afficher_tableau(tab,5);
    tri_rapide(tab,0,4);
    printf("sortie :");
    afficher_tableau(tab,5);
   
    printf("\n\n");

    //Tableau avec 1 élément
    int tab2[1] = {1};
    printf("Tableau d'un élément:\n\n");
    printf("entrée :");
    afficher_tableau(tab2,1);
    tri_rapide(tab2,0,0);
    printf("sortie :");
    afficher_tableau(tab2,1);

    printf("\n\n");

    //Tableau avec 10 éléments
    int tab3[10] = {2,1,4,3,8,6,5,7,10,9};
    printf("Tableau de 10 éléments avec un tri des éléments 0 à 4 :\n\n");
    printf("entrée :");
    afficher_tableau(tab3,10);
    tri_rapide(tab3,0,5); //Tri seulement les éléments 0 à 5
    printf("sortie :");
    afficher_tableau(tab3,10);

}
