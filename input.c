#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "grid.h"
#include "chain.h"

Action get_user_input() {
    char input;
    printf("Entrez une action (s: sélectionner, u: annuler, r: redémarrer, q: quitter): ");
    scanf(" %c", &input);

    switch (input) {
        case 's':
            return ACTION_SELECT;
        case 'u':
            return ACTION_UNDO;
        case 'r':
            return ACTION_RESTART;
        case 'q':
            return ACTION_QUIT;
        default:
            return ACTION_NONE;
    }
}

void handle_user_input(Action action, Grid *grid, Chain *chain) {
    // Vous devrez implémenter cette fonction en fonction de la logique de votre jeu
    // Par exemple, vous pouvez vérifier si l'utilisateur a sélectionné une nouvelle cellule et étendre la chaîne en conséquence
}
