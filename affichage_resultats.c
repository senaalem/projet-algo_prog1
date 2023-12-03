#include <stdio.h>
#include <stdlib.h>
#include "trouve_max.h"
#include "trouve_min.h"
#include "fin_jour.h"
#include "force_vent.h"
#include "prod_1eolienne.h"
#include "def_parametres.h"
#include "affichage_resultats.h"
#include <time.h>

void affichage_resultats(int nb_eolienne, int temps, float V[3][3], float cout_intervention, float prod[], int duree_intervention, float p, float *cout) /* Fonction qui fait la simulation et affiche ses résultats dans le terminal. */
{
	float *tab_des_prod_j = (float*) malloc(temps * sizeof(float)); /* Tableau des productions journalières, pour acquérir le max et le min. */
	float prod_total; /* Représente la production totale du parc (en MW). */
	float prod_du_jour; /* Représente la production du jour (en MW). */
	int fv = 0; /* Représente la force du vent : 0 pour faible, 1 pour moyen, 2 pour fort. */
	int eolienne_prete = nb_eolienne; /* Le nombre d'éoliennes en état de fonctionner. Au début de la simulation, il est égal au nombre d'éoliennes du parc. */
	int* maintenance = (int*) malloc(nb_eolienne * sizeof(int)); /* Tableau dont chaque case représente une éolienne ainsi que son état : 0 pour fonctionelle, 1 pour cassé, 2 cassé + 1 jour de maintenance etc */
	for (int i = 0; i < nb_eolienne; i++) {
		maintenance[i] = 0;	/* On intialise toutes nos éoliennes à l'état fonctionnel. */
	}

	int proba; /* Sert à utiliser les probabilités. */
	srand(time(NULL));

	for (int jour = 1; jour<=temps; jour++) { /* Boucle de la simulation. */
		for (int j = 0; j < jour; j++) {
			proba = (rand() % 100) + 1;
		}
		
		fv = force_vent(fv, proba, V); /* On acquiert la force du vent pour ce jour. */
		prod_du_jour = eolienne_prete * prod_1eolienne(fv, prod); /* La production pour ce jour est égale au nombre d'éoliennes fonctionelles multiplié par la production d'une seule éolienne. */
		tab_des_prod_j[jour] = prod_du_jour; /* On remplit le tableau des productions journalières avec la production de ce jour. */
		srand(jour);
		eolienne_prete = fin_jour(nb_eolienne, maintenance, fv, cout_intervention, cout, p, duree_intervention, jour); /* On actualise le nombre d'éoliennes fonctionelles. */
		prod_total = prod_total + prod_du_jour; /* On ajoute la production de ce jour à la production totale. */
	}

	float prod_moy = prod_total / temps; /* Production journalière moyenne. */

	printf("Coût de la maintenance du parc : %f k€\nProduction totale : %f MW\nProduction journalière moyenne : %f MW\nProduction maximale atteinte : %f MW\nProduction minimale atteinte : %f MW", *cout, prod_total, prod_moy, trouve_max(tab_des_prod_j, temps), trouve_min(tab_des_prod_j, temps)); /* On affiche tout les résultats dans la console. */
}

