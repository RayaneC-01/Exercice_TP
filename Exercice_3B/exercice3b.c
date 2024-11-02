/******************************************************************************
EXERCICE 3A NOMBRE PREMIER AVEC PROTOTYPE
*******************************************************************************/


#include <stdio.h> 
#include <math.h> 

// Prototypage de la fonction est_premier
int est_premier(int n);

// Déclaration des variables
int N, i;

int main()
{
        // Lire la valeur saisie par l'utilisateur et vérifier si c'est un entier valide
    while (1){
        printf("Entrez un nombre positif : ");
        if (scanf("%d", &N) != 1 || N < 1) {
            printf("Erreur : Veuillez entrer un entier strictement positif.\n");
            while (getchar() != '\n');
        } else {
            break; 
        }
    }

    printf("Les nombres premiers entre 1 et %d sont : ", N);
    // Boucle pour itérer sur chaque nombre de 1 à N
    for (i = 1; i <= N; i++){
        // Appel de la fonction est_premier pour vérifier si le nombre est premier
        if (i == 1) printf("1 ");
        else if (est_premier(i)) printf("%d ", i); 
    }
    printf("\n"); 
    return 0; 

}

// Fonction pour vérifier si un nombre est premier
int est_premier(int n)
{
    // Vérifie si n est inférieur à 2
    if (n < 2) return 0;
    // Vérifie si n est égal à 2
    if (n == 2) return 1;
    // Vérifie si n est un nombre pair
    if (n % 2 == 0) return 0;

    // Boucle pour vérifier les diviseurs de 3 à la racine carrée de n, Incrémente de 2 pour vérifier uniquement les nombres impairs

    for (i = 3; i <= sqrt(n); i += 2) { 
        // Vérifie si n est divisible par i
        if (n % i == 0) return 0;// Si n est divisible par i, alors ce n'est pas un nombre premier
    }
    
    return 1;
}
