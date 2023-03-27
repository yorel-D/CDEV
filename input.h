#ifndef INPUT_H
#define INPUT_H

typedef enum {
    ACTION_NONE,
    ACTION_SELECT,
    ACTION_UNDO,
    ACTION_RESTART,
    ACTION_QUIT
} Action;

Action get_user_input();
void handle_user_input(Action action, Grid *grid, Chain *chain);

#endif // INPUT_H
