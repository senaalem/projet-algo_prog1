// fin_jour.c
#include "fin_jour.h"
#include <stdlib.h>
#include <time.h>
int fin_jour(int n, int *maintenance, int force_vent, float cout_intervention, float *cout, float P, int duree_intervention, int jour) /* Fonction qui renvoie le nombre d'éoliennes fonctionelles à la fin d'une journée de simuation tout en modifiant le tableau des états des éoliennes */
{ 
 	int op = 0;
 	srand(jour + time(NULL)); //a fonction revient plusieurs fois, si on veut pas les même proba chaque jour, il fallait qu'on réactualise la seed
 	int nb; //notre propa utile pour cette fonction

 	if (force_vent == 2) {	//cas vent fort
	 	for (int i = 0; i < n; i++) {	//on parcourt notre tableau des états des éoliennes
	 		if (maintenance[i] == 0) {	//si y a des éoliennes en marche on regarde si elle se casse
		 		nb = (rand() % 100) + 1;
		 		if (nb <=100*P) {
		 			*cout = *cout + cout_intervention;	//le cout augment pour chaque intervention
		 			maintenance[i] = 1; //l'état 1 des éoliennes est l'état cassé + 0 jours de maintenance
		 		}
		 	}
	 	}
	} else {
	 	for (int i = 0; i < n; i++) {
	 		if (maintenance[i] != 0) //on regarde les éoliennes cassées
	 			maintenance[i] = maintenance[i] + 1; //on ajoute un jour d'intervention
	 		if (maintenance[i] == (duree_intervention + 1)) //LA DURÉE d'une intervention + 1 = éolienne réparé
	 			maintenance[i] = 0;
	 	}
	}

	for (int i = 0; i < n; i++) {
		if (maintenance[i] == 0) //on compte le nombre d'éolienne en marche
	 		op = op + 1;
	}

	return op;
}

