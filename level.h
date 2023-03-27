#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int level_number;
    Grid *grid;
} Level;

Level *load_level(char *filename);
Level *get_next_level(Level *current_level);
void save_level(Level *level, char *filename);
void free_level(Level *level);

#endif // LEVEL_H
