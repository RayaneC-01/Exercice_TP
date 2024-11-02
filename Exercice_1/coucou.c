#include <stdio.h>

int main() {
    int n;
    printf("coucou! Test réussi ! \n");

   do{
    // 1. Demander à l'utilisateur un entier compris entre 1 et 6
    printf("Veuillez entrer un entier compris entre 1 et 6 : ");
    // Lecture de l'entier saisi par l'utilisateur
    scanf("%d", &n);  

        // 2. Vérifier que l'entier est valide
        if(n < 1  || n > 6) {
            printf("Valeur invalide ! Veuillez entrer un entier compris entre 1 et 6 : ");
        scanf("%d", &n);  // Redemande à l'utilisateur de saisir un entier valide
        }
      
      printf(" Votre valeur est: %d", n);  
    } while (n < 1  || n > 6);// Utilise une boucle pour redemander une valeur tant que n n'est pas entre 1 et 6


for (int i = 0; i < n; i++){
    printf("i = %d:\n", i);  // Afficher la valeur de i
for(int j = 0; j < n; j++){
    printf("  j = %d\n", j);  // Afficher la valeur de j avec une indentation
        
    }
    
}
    


 return 0;

}
