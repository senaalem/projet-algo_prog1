#include <stdio.h>
#include "def_parametres.h"

void def_parametres(int *nb_eolienne, int *temps, float V[3][3], float *cout_intervention, float prod[], int *duree_intervention, float *p) 
{
    /* Fonction qui permet à l'utilisateur de définir les paramètres de la simulation s'il le souhaite. */
	int choix; /* Représente le choix de l'utilisateur. */
	printf("Tapez 0 pour lancer la simulation par défaut ou 1 pour modifier les paramètres.\n > ");
	scanf("%d", &choix); /* On acquiert ce choix. */
	
	if(choix == 1) { /* On modifie l'intégralité des paramètres si l'utilisateur le souhaite. */
		printf("Saisissez le nombre d'éoliennes du parc. > ");
		scanf("%d", nb_eolienne);
		
		printf("Saisissez le temps de simulation (en jours). > ");
		scanf("%d", temps);
		
		printf("Saisissez p la probabilité pour une éolienne de tomber en panne. > ");
		scanf("%f", p);
		
		printf("Saisissez la durée d'une intervention (en jours). > ");
		scanf("%d", duree_intervention);
		
		printf("Saisissez le coût d'une intervention (en €). > ");
		scanf("%f", cout_intervention);
		
		printf("Saisissez prod le vecteur ligne des trois entiers qui définissent la production d'un éolienne en MW en fonction de la force du vent. > ");
		for(int k = 0; k < 3; k++) {
			printf("prod[%d] = ", k);
			scanf("%f", &prod[k]);
		}
		
		printf("Saisissez V la matrice de transition de la force du vent. ");
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				printf("V[%d][%d] = ", i, j);
				scanf("%f", &V[i][j]);
			}
		}
		
	}
}


