// trouve_min.c
#include "trouve_min.h"

float trouve_min(float tab[], int taille) 
{
    float mini = tab[0];
    for (int i = 0; i < taille; i++) {
        if (tab[i] <= mini)
            mini = tab[i];
    }
    return mini;
}

