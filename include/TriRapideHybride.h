#ifndef TRI_RAPIDE_HYBRIDE_H

#define TRI_RAPIDE_HYBRIDE_H

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"

void tri_hybride(int t[],int i,int j,int seuil);
void tri_insertion(int t[],int i,int j);
void permuter_h(int *i,int *j);
int median_h(int t[],int i,int j,int k);
void partition_h(int t[],int i,int j,int *k);
void test_rapide_hybride();

#endif