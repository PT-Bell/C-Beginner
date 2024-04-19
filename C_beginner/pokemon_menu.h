/* pokemon_menu.h */
#ifndef MENU_H
#define MENU_H

typedef struct {
    char name[50];
    char type[20];
    int attack;
    int hp;
} Pokemon;

void readAndSavePokemon(const char* pokemonName);
void start_menu(void);
void newgame_or_loadfile(void);
void start_newgame(void);
void print_spec(void);


#endif
