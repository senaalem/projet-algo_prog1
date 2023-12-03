// force_vent.c
#include "force_vent.h"

int force_vent(int ventprec, int proba, float mat[3][3]) /* Fonction qui renvoie la force du vent du jour i en fonction de la force du vent du jour i - 1 grâce à la matrice de transition V. */
{
	switch(ventprec) {
		case 0:
			if (proba <= 100 * mat[0][0])
				return 0;
			else if (proba > 100 * (mat[0][0]+mat[0][1]))
				return 2;
			else 
				return 1;
			break;
		case 1:
			if (proba <= 100 * mat[1][0])
				return 0;
			else if (proba > 100 * (mat[1][0]+mat[1][1]))
				return 2;
			else 
				return 1;
			break;
		case 2:
			if (proba <= 100 * mat[2][0])
				return 0;
			else if (proba > 100 * (mat[2][0]+mat[2][1]))
				return 2;
			else 
				return 1;
			break;
	}return 1;
}	
