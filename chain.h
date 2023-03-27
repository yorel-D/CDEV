#ifndef CHAIN_H
#define CHAIN_H

typedef struct {
    int length;
    int *rows;
    int *cols;
} Chain;

Chain *create_chain(Grid *grid, int start_row, int start_col);
void extend_chain(Chain *chain, int row, int col);
void remove_last_link(Chain *chain);
int is_chain_valid(Chain *chain, Grid *grid);
void free_chain(Chain *chain);

#endif // CHAIN_H
