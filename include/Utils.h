#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void afficher_tableau(int t[], int n);
int entier_aleatoire(int min, int max);
void genererTableau(int min, int max, int taille, int t[]);

void test_utils();

#endif