/******************************************************************************
EXERCICE 5 ALGORITHME DE HORNER
    // P est un tableau des coefficients du polynôme (P[0], P[1], ..., P[n])
    // n est le degré du polynôme
    // x est la valeur à laquelle on souhaite évaluer le polynôme
*******************************************************************************/
#include <stdio.h>

// Prototype de la fonction
int fonction_horner(int n, int P[], int x);

int main() {
    int n; // Degré du polynôme

    printf("Entrez le degré du polynôme: ");
    scanf("%d", &n);
    int P[n + 1]; // Tableau pour les coefficients du polynôme

    // Saisie des coefficients
    printf("Entrez les coefficients du polynôme (du terme constant au terme de plus haut degré) :\n");
    
    for (int i = 0; i <= n; i++) {
        printf("Coefficient de x^%d : ", i);
        scanf("%d", &P[i]);
    }

    char choix = 'o'; // Variable pour stocker le choix de l'utilisateur
    int x, resultat;
    // Boucle pour demander à l'utilisateur s'il veut évaluer le polynôme
    while (choix == 'o') {

        printf("Voulez-vous évaluer le polynôme ? (o/n) : \n");
        fflush(stdin); // Vider le buffer de lecture avant la saisie d'un caractère
        scanf(" %c", &choix); 

        if (choix == 'o') {
            printf("Entrez la valeur de x: ");
            scanf("%d", &x);

            // Appel de la fonction Horner pour évaluer le polynôme
            resultat = fonction_horner(n, P, x);
            printf("La valeur du polynôme pour x = %d est : %d\n", x, resultat);
        } else if(choix == 'n'){
            printf("Fin du programme.\n");
        } 
         else{
            printf("Choix invalide. Veuillez entrer 'o' pour oui ou 'n' pour non.\n");
         }   
    }
    return 0;
}

// Fonction qui implémente l'algorithme de Horner
int fonction_horner(int n, int P[], int x) {

    int resultat = P[n]; // Initialisation avec le coefficient du plus haut degré
    // Parcourir les coefficients du polynôme depuis (n-1) jusqu'à 0
    for (int i = n - 1; i >= 0; i--) {
        resultat = resultat * x + P[i]; // Correction ici
    }
    return resultat;

}
