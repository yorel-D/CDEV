#include <stdio.h>
#include <stdlib.h>
#include "level.h"
#include "grid.h"

Level *load_level(char *filename) {
    Level *level = (Level *)malloc(sizeof(Level));
    level->grid = load_grid_from_file(filename);
    sscanf(filename, "level%d.txt", &(level->level_number));
    return level;
}

Level *get_next_level(Level *current_level) {
    char next_level_filename[32];
    sprintf(next_level_filename, "level%d.txt", current_level->level_number + 1);
    Level *next_level = load_level(next_level_filename);
    return next_level;
}

void save_level(Level *level, char *filename) {
    // Cette fonction est optionnelle, car vous n'avez pas besoin de sauvegarder les niveaux dans cette version du jeu
}

void free_level(Level *level) {
    free_grid(level->grid);
    free(level);
}
