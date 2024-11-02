#include <stdio.h>
#include <math.h>

// Déclaration des variables globales
double precision = 0.000001;

// Fonction récursive pour évaluer un polynôme donné par ses coefficients
double evaluer_polynome(double P[], int n, double x) {
    if (n == 0)
        return P[0];
    return P[n] * pow(x, n) + evaluer_polynome(P, n - 1, x);
}

// Fonction récursive pour la recherche dichotomique
double recherche_dichotomique_recursive(double P[], int n, double min, double max) {
    // Vérification si f(min) et f(max) ont le même signe
    if (evaluer_polynome(P, n, min) * evaluer_polynome(P, n, max) >= 0) {
        printf("La fonction n'a pas de solution dans cet intervalle.\n");
        return 0;
    }

    // Calculer le point milieu
    double milieu = (min + max) / 2.0;

    // Vérifier si on est assez proche de zéro pour s'arrêter
    if ((max - min) < precision || evaluer_polynome(P, n, milieu) == 0) {
        return milieu;
    }

    // Réduction de l'intervalle selon le signe de f(milieu)
    if (evaluer_polynome(P, n, milieu) * evaluer_polynome(P, n, min) < 0) {
        return recherche_dichotomique_recursive(P, n, min, milieu);
    } else {
        return recherche_dichotomique_recursive(P, n, milieu, max);
    }
}

int main() {
    int n;
    printf("Entrez le degré du polynôme : ");
    scanf("%d", &n);

    double P[n + 1];
    printf("Entrez les coefficients du polynôme (du terme constant au terme de degré %d) :\n", n);
    for (int i = 0; i <= n; i++) {
        printf("Coefficient de x^%d : ", i);
        scanf("%lf", &P[i]);
    }

    double min, max;
    printf("Entrez la valeur de min : ");
    scanf("%lf", &min);

    printf("Entrez la valeur de max : ");
    scanf("%lf", &max);

    // Appeler la fonction de recherche dichotomique récursive
    double solution = recherche_dichotomique_recursive(P, n, min, max);

    // Afficher la solution
    if (evaluer_polynome(P, n, min) * evaluer_polynome(P, n, max) < 0) {
        printf("La solution est : %lf\n", solution);
    }
    return 0;
}
