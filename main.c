#include <stdio.h>
#include "grid.h"

void process_user_input(Grid *grid, char command) {
    int new_x = grid->current_x;
    int new_y = grid->current_y;

    switch (command) {
        case 'w': // Haut
            new_y--;
            break;
        case 's': // Bas
            new_y++;
            break;
        case 'a': // Gauche
            new_x--;
            break;
        case 'd': // Droite
            new_x++;
            break;
        case 'u': // Annuler
            // À implémenter: Annuler le dernier mouvement
            return;
        default:
            return;
    }

    if (new_x >= 0 && new_x < grid->cols && new_y >= 0 && new_y < grid->rows) {
        int current_value = get_cell(grid, grid->current_y, grid->current_x);
        int new_value = get_cell(grid, new_y, new_x);

        if (new_value == current_value || new_value == current_value + 1) {
            set_cell(grid, new_y, new_x, current_value + 1);
            grid->current_x = new_x;
            grid->current_y = new_y;
        }
    }
}


int main() {
    int current_level = 1;

    while (1) {
        char filename[64];
        snprintf(filename, sizeof(filename), "level%d.txt", current_level);

        Grid *grid = load_grid_from_file(filename);

        if (grid == NULL) {
            printf("Erreur lors du chargement du niveau depuis le fichier %s\n", filename);
            break;
        }

        printf("Niveau %d chargé avec succès depuis le fichier %s\n\n", current_level, filename);

        char command;

        while (1) {
            system("clear"); // Pour Windows, utilisez system("cls");
            display_grid(grid);

            printf("\nEntrez votre commande (n pour niveau suivant, q pour quitter) : ");
            scanf(" %c", &command);

            if (command == 'q') {
                free_grid(grid);
                return 0;
            } else if (command == 'n') {
                break;
            } else {
                process_user_input(grid, command);
            }
        }

        free_grid(grid);
        current_level++;
    }

    return 0;
}
