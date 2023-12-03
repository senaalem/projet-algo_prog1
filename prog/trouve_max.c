// trouve_max.c
#include "trouve_max.h"

float trouve_max(float tab[], int taille)
{
    float maxi = tab[0];
    for (int i = 0; i < taille; i++) {
        if (tab[i] > maxi)
            maxi = tab[i];
    }
    return maxi;
}

