#ifndef GRID_H
#define GRID_H

typedef struct {
    int rows;
    int cols;
    int **cells;
} Grid;

Grid *load_grid_from_file(char *filename);
void display_grid(Grid *grid);
int get_cell(Grid *grid, int row, int col);
void set_cell(Grid *grid, int row, int col, int value);
void free_grid(Grid *grid);

#endif // GRID_H
