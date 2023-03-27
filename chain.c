#include "chain.h"
#include "grid.h"

Chain *create_chain(Grid *grid, int start_row, int start_col) {
    Chain *chain = (Chain *)malloc(sizeof(Chain));
    chain->length = 1;
    chain->rows = (int *)malloc(sizeof(int));
    chain->cols = (int *)malloc(sizeof(int));
    chain->rows[0] = start_row;
    chain->cols[0] = start_col;
    return chain;
}

void extend_chain(Chain *chain, int row, int col) {
    chain->length++;
    chain->rows = (int *)realloc(chain->rows, chain->length * sizeof(int));
    chain->cols = (int *)realloc(chain->cols, chain->length * sizeof(int));
    chain->rows[chain->length - 1] = row;
    chain->cols[chain->length - 1] = col;
}

void remove_last_link(Chain *chain) {
    if (chain->length > 1) {
        chain->length--;
        chain->rows = (int *)realloc(chain->rows, chain->length * sizeof(int));
        chain->cols = (int *)realloc(chain->cols, chain->length * sizeof(int));
    }
}

int is_chain_valid(Chain *chain, Grid *grid) {
    for (int i = 1; i < chain->length; i++) {
        int prev_value = get_cell(grid, chain->rows[i - 1], chain->cols[i - 1]);
        int cur_value = get_cell(grid, chain->rows[i], chain->cols[i]);

                if (cur_value < prev_value) {
            return 0;
        }
    }
    return 1;
}

void free_chain(Chain *chain) {
    free(chain->rows);
    free(chain->cols);
    free(chain);
}

