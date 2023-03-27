#include <stdio.h>
#include <stdlib.h>
#include "grid.h"


Grid *load_grid_from_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL ) {
        printf("Erreur d'ouverture du fichier\n");
        return NULL;
    }

    Grid *grid = (Grid *)malloc(sizeof(Grid));
    if (grid == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        fclose(file);
        return NULL;
    }
    
    fscanf(file, "%d %d", &(grid->rows), &(grid->cols));

    grid->cells = (int **)malloc(grid->rows * sizeof(int *));
    if (grid->cells == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        fclose(file);
        free(grid);
        return NULL;
    }

    for (int i = 0; i < grid->rows; i++) {
        grid->cells[i] = (int *)malloc(grid->cols * sizeof(int));
        if (grid->cells[i] == NULL) {
            printf("Erreur d'allocation de mémoire\n");
            for (int j = 0; j < i; j++) {
                free(grid->cells[j]);
            }
            free(grid->cells);
            fclose(file);
            free(grid);
            return NULL;
        }
        for (int j = 0; j < grid->cols; j++) {
            fscanf(file, "%d", &(grid->cells[i][j]));
        }
    }

    fclose(file);
    return grid;
}

void display_grid(Grid *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->cells[i][j]);
        }
        printf("\n");
    }
}

int get_cell(Grid *grid, int row, int col) {
    return grid->cells[row][col];
}

void set_cell(Grid *grid, int row, int col, int value) {
    grid->cells[row][col] = value;
}

void free_grid(Grid *grid) {
    for (int i = 0; i < grid->rows; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}
