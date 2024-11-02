/******************************************************************************

EXERCICE 3 NOMBRE PREMIER
Lire un entier N strictement positif et imprimer tous les nombres premiers compris entre 1 et N.
   nombre premier n'a que 2 diviseurs, cad 1 ou 2 max, pas plus que 2 diviseurs, chercher le nombre de diviseurs
Etape 1 :
1) Demander à l'utilisateur un entier positif
2) Vérifie que l'utilisateur entre bien un entier strictement positif. Si ce n'est pas le cas, redemande l'entrée.

Etape 2 :
1) Boucle pour parcourir les nombres : Utiliser une boucle pour parcourir tous les entiers de 1 à N.
2) Vérification si chaque nombre est premier : Pour chaque nombre dans cette plage, appelle la fonction est_premier pour déterminer s'il est premier.

*******************************************************************************/

#include <stdio.h>

// Prototype de la fonction
int est_premier(int n);

int main()
{
    int N;
    // Lire un nombre positif
    printf("Entrez un nombre positif : ");
    scanf("%d", &N);

    // Vérifier si le nombre est positif
    if (N < 1)
    {
        printf("Veuillez entrer un nombre positif.\n");
        return 1; // Sortie en cas d'entrée invalide
    }

    // Verifie si le nombre i est premier et Affiche les nombres premiers entre 1 et N
    printf("Les nombres premiers entre 1 et %d sont : ", N);
    for (int i = 1; i <= N; i++)
    { // itere de 1 à N
        if (est_premier(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

// Fonction pour vérifier si un nombre est premier
int est_premier(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0; // n est divisible, donc ce n'est pas un premier
        }
    }
    return 1; // n est un nombre premier
}
