/******************************************************************************

EXERCICE 2 MATRICE DE HILBERT

*******************************************************************************/

#include <stdio.h>

void matriceHilbert();

// Déclaration des variables globales
int i, j;

int main()
{
    matriceHilbert(); // Appel de la fonction
    return 0;
}

void matriceHilbert()
{
    int n;
    double value;

    // Saisie d'un nombre entier compris entre 1 et 6
    do
    {
        printf("Veuillez entrer un entier compris entre 1 et 6 : ");
        scanf("%d", &n);
        if (n < 1 || n > 6)
        {
            printf("Valeur invalide ! Veuillez entrer un entier compris entre 1 et 6.\n");
        }

    } while (n < 1 || n > 6);

    printf("Votre valeur est : %d\n", n);

    // Deux boucles imbriquées pour parcourir les lignes (i) et les colonnes (j) de la matrice
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            // Calcul de la valeur de l'élément a_ij selon la formule de la matrice de Hilbert
            value = 1.0 / (i + j + 1);

            //%7.4f affiche avec 7 caractères et 4 décimales
            printf("%7.4f ", value);
        }
        printf("\n");
    }
}
