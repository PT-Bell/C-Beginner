#include "pokemon_menu.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    start_menu();
    newgame_or_loadfile();
    print_spec();
    return 0;
}
