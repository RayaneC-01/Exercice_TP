/******************************************************************************
EXERCICE 3A NOMBRE PREMIER SANS PROTOTYPE
*******************************************************************************/

#include <stdio.h>
int main() {
  // Déclaration des variables
  int N, i;
  int diviseur, est_premier;
  
  while (1){
    printf("Entrez un nombre positif : ");

    if (scanf("%d", &N) != 1 || N < 1){

      printf("Erreur : Veuillez entrer un entier strictement positif.\n");
      while (getchar() != '\n');
    } else {
      break;
    }
  }

  printf("Les nombres entre 1 et %d sont : 1 ", N);
    for (i = 2; i <= N; i++) {
      est_premier = 1;
      diviseur = 2;

      // Tester si `i` est divisible par un nombre autre que lui-même et 1
      while ((diviseur * diviseur <= i) && est_premier) {
        if (i % diviseur == 0) est_premier = 0;
        diviseur++;
      }
      // Afficher le nombre i s'il est premier
      if (est_premier) printf("%d", i);
      
    }
  printf("\n");
  return 0;
}
