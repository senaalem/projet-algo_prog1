# README

## Générer l'exécutable
Une fois l'ensemble des fichiers téléchargés, se placer dans le répertoire "prog" et taper `make` dans la console.

## Exécuter le programme
Écrire `./main` dans la console (toujours dans le répertoire "prog").  
L'opérateur devra alors choisir s'il veut exécuter la simulation avec des paramètres par défaut où s'il veut les définir (tout se fait dans la console). Le programme affichera les résultats suivants :
- Le coût total de la maintenance du parc (en k€)
- La production totale du parc (en MW)
- La production journalière moyenne (en MW)
- La production maximale atteinte sur un jour (en MW)
- La production minimale atteinte sur un jour (en MW)  

## Le découpage en modules
Il y a un total de sept modules :
- `<affichage_resultats.h>` : contient la fonction `affichage_resultats` qui effectue la simulation et affiche ses résultats dans la console. 
- `<def_parametres.h>` : contient la fonction `def_parametres` qui permet à l'opérateur de définir (ou non) les paramètres de la simulation.
- `<fin_jour.h>` : contient la fonction `fin_jour` qui gère chacune des éoliennes et leur état, et qui renvoie le nombre d'éoliennes en état de marche à la fin du jour.
- `<force_vent.h>` : contient la fonction `force_vent` qui renvoie la force du vent pour le jour $j$ en fonction de celle du jour $j-1$.
- `<prod_1eolienne.h>` : contient la fonction `prod_1eolienne` qui renvoie la production (en MW) d'une (1) éolienne du parc.
- `<trouve_max.h>` : contient la fonction `trouve_max` qui renvoie l'élément le plus grand d'une liste de flottants.
- `<trouve_min.h>` : contient la fonction `trouve_min` qui renvoie l'élément le plus petit d'une liste de flottants.

## Choix techniques
Pour gérer l'état des éoliennes, il a été décidé d'utiliser une variable globale `int* maintenance`, définie dans la fonction `affichage_resultats`. Chaque case de ce tableau correspond à une éolienne. Son état est representé par un entier : $0$ pour fonctionelle, et $i$ pour $i-1$ jours de maintenance effectués.  
La fonction `fin_jour` va prendre en paramètre l'adresse de `maintenance` et actualiser ses valeurs en fonction de la force du vent et des jours qu'elle aura passé en maintenance, etc. puis compter les cases à $0$ pour renvoyer le nombre d'éoliennes encore en état de marche.

La simulation se fait dans `affichage_resultats` via une boucle `for` (chaque itération correspond à un jour). À la fin de la boucle, la simulation est finie et on affiche les résultats.
