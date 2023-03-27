#include <stdio.h>
#include "grid.h"

int main() {
    char *filename = "level1.txt"; // Remplacez par le nom du fichier contenant votre niveau

    Grid *grid = load_grid_from_file(filename);

    if (grid == NULL) {
        printf("Erreur lors du chargement du niveau depuis le fichier %s\n", filename);
        return 1;
    }

    printf("Niveau chargé avec succès depuis le fichier %s\n\n", filename);
    display_grid(grid);

    // Ajoutez ici la logique pour résoudre les niveaux et interagir avec l'utilisateur

    printf("\nAppuyez sur Entrée pour quitter...");
    getchar();

    free_grid(grid);
    return 0;
}
