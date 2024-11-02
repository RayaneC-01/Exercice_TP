/******************************************************************************
EXERCICE 4  RECHERCHE DICHOTOMIQUE
1) variables GLoables
2) Fonction
Étape 1 : Déclarer le prototype de la fonction f(double x) -> return (x * x * x) - a;
*******************************************************************************/
#include <stdio.h>

// declaration variables globale
double a;
double precision = 0.000001;
double min, max;
double f(double x){ 
    return (x * x * x) - a;
}

// Fonction pour la recherche dichotomique
double recherche_dichotomique(double min, double max){
    // Verification si f((min) et f(max) ont le meme signe
    if (f(min) * f(max) >= 0) printf("La fonction n'a pas de solution dans cet intervalle");

    // Declaration variable point sur le milieu
    double milieu;

    while ((max - min) > precision) {
        // Calculer le point du milieu
        milieu = (max + min) / 2.0;

        // Verifier si f(milieu) est proche de zero
        if (f(milieu) == 0) return milieu; // Retourner la valeur si f(milieu) est zéro
       
        else if (f(milieu) * f(min) < 0)
            // Si f(milieu) et f(min) ont des signes différents, la solution est entre min et milieu
            max = milieu;
        
        else{ min = milieu;  // Sinon, la solution est entre milieu et max 
        }
    }
    return milieu;
}

int main()
{

    // Demander à l'utilisateur d'entrer les valeurs de min et max
    printf("Entrez la valeur de a : ");
    scanf("%lf", &a);

    printf("Entrez la valeur de min : ");
    scanf("%lf", &min); 

    printf("Entrez la valeur de max : ");
    scanf("%lf", &max);

    // Appeler la fonction de recherche dichotomique
    double solution = recherche_dichotomique(min, max);
    // Afficher la solution
    if (f(min) * f(max) < 0) printf("La solution est : %lf", solution);
    return 0;
}
