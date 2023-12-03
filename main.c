#include "trouve_max.h"
#include "trouve_min.h"
#include "fin_jour.h"
#include "force_vent.h"
#include "prod_1eolienne.h"
#include "def_parametres.h"
#include "affichage_resultats.h"
#include <time.h>
#include <stdlib.h>

int main() 
{
    srand(time(NULL));

    int nb_eolienne = 100;
    int temps = 365;
    float p = 0.15;
    float prod[3] = {0, 0.4, 0.65};
    float cout_intervention = 150;
    int duree_intervention = 3;
    float V[3][3] = {{0.2, 0.73, 0.07}, {0.11, 0.74, 0.15}, {0.04, 0.61, 0.35}};

    float cout = 0;

    def_parametres(&nb_eolienne, &temps, V, &cout_intervention, prod, &duree_intervention, &p);
    affichage_resultats(nb_eolienne, temps, V, cout_intervention, prod, duree_intervention, p, &cout);

    return 0;
}