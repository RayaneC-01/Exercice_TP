/******************************************************************************

EXERCICE 6 ALGORITHME TRI DE TAS
    => i est l'indice actuel
    => n est la taille du tas
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
// Fonction pour obtenir l'indice du fils gauche d'un noeud i
int FilsG(int i) {
    return 2 * i;
}

// Fonction pour obtenir l'indice du fils droit d'un noeud i
int FilsD(int i){
    return 2 * i + 1;
}

void Entasser(int *tas, int n, int i)
{
    int plusGrand = i;
    int fg = FilsG(i); 
    int fd = FilsD(i); 

    // Vérifier si le fils gauche est plus grand que le noeud actuel
    if (fg < n && tas[fg] > tas[plusGrand]) plusGrand = fg; // fils gauche => plus grand

    // Vérifier si le fils droit est plus grand que le plus grand actuel
    if (fd < n && tas[fd] > tas[plusGrand]) plusGrand = fd; // fils droit => le plus grand
    
    // Si le noeud actuel n'est pas le plus grand, on effectue un échange
    if (plusGrand != i)
    {
        int temp = tas[i]; // Échanger l'élément actuel avec le plus grand
        tas[i] = tas[plusGrand];
        tas[plusGrand] = temp;
        Entasser(tas, n, plusGrand);
    }
}

// Fonction pour construire un tas à partir d'un tableau non trié
void ConstruireUnTas(int *tas, int n){
    // Commencer à entasser à partir du dernier noeud parent
    for (int i = n / 2 - 1; i >= 0; i--) Entasser(tas, n, i); // Entasser chaque noeud parent  
}

// Fonction pour trier un tableau en utilisant le tri par tas
void TriParTas(int *tas, int n)
{
    ConstruireUnTas(tas, n);

    for (int i = n - 1; i > 0; i--)
    {
        // Échanger le premier (le plus grand) avec le dernier élément non trié
        int temp = tas[0];
        tas[0] = tas[i];
        tas[i] = temp;

        // Réduire la taille du tas et rétablir la structure de tas
        Entasser(tas, i, 0);
    }
}

// Fonction pour afficher les éléments du tableau
void AfficherTas(int *tas, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tas[i]);
    }
    // printf("\n");
}

// Fonction principale
int main()
{
    int n;

    // Lire le nombre d'éléments à trier
    printf("Entrez le nombre d'éléments à trier : ");
    scanf("%d", &n);

    // Allouer un tableau dynamique pour stocker les éléments, le (int*) sert à caster le pointeur renvoyé par malloc() en un pointeur de type entier.
    int *tas = (int *)malloc(n * sizeof(int));

    printf("Entrez les éléments : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tas[i]); // Stocker chaque élément dans le tableau
    }

    TriParTas(tas, n);

    printf("Tableau trié : ");
    AfficherTas(tas, n);

    free(tas); // Libérer la mémoire allouée

    return 0;
}
