#ifndef TRI_RAPIDE_H

#define TRI_RAPIDE_H

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"



void permuter(int *i,int *j);
int median(int t[],int i,int j,int k);
void partition(int t[],int i,int j,int *k);
void tri_rapide(int tab[],int i,int j);
void test_rapide();

#endif