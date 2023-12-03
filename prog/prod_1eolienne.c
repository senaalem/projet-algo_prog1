// prod_1eolienne.c
#include "prod_1eolienne.h"

float prod_1eolienne(int force, float prod[]) /* Fonction qui renvoie la production (en MW) d'une éolienne en fonction de la force du vent et du vecteur prod. */
{
	switch(force) {
		case 0:
			return prod[0];
			break;
		case 1:
			return prod[1];
			break;
		case 2:
			return prod[2];
			break;
	}return 0;
}

