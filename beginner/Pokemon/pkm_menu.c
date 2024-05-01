#include "pkm_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void start_menu(void){
    printf("===============================\n");
    printf("     K.Knock Pokemon Game\n\n");
    printf("     press enter to start\n");
    printf("===============================\n\n");

    while (getchar() != '\n');
}

void newgame_or_loadfile(void){
    int choice;
    printf("===============================\n");
    printf("     1. 새로하기  2. 이어하기\n");
    do {
        printf(">> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            start_newgame();
            return;

            case 2:
            printf("2번\n");
            return;

            default:
            printf("잘못된 선택\n");
            break;
        }
    }while(choice != 1 || choice != 2);
}

void start_newgame(void){
    int choice;
    printf("===============================\n");
    printf("어느 포켓몬을 선택하시겠습니까?\n");
    printf("    1.파이리 2.이상해씨 3.꼬부기\n");
    do {
        printf(">> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            readAndSavePokemon("파이리");
            return;

            case 2:
            readAndSavePokemon("이상해씨");
            return;

            case 3:
            readAndSavePokemon("꼬부기");
            return;

            default:
            printf("잘못된 선택\n");
            break;
        }
    }while(choice != 1 || choice != 2 || choice != 3);
}

void readAndSavePokemon(const char* pokemonName) {
    FILE *allPokemonFile = fopen("all_pokemon.txt", "r");
    FILE *userPokemonFile = fopen("user_pokemon.txt", "w");

    if (allPokemonFile == NULL) {
        printf("all_pokemon.txt 을 열지 못함\n");
        return;
    }
    if (userPokemonFile == NULL) {
        printf("user_pokemon.txt 을 열지 못함\n");
        return;
    }

    char line[500];
    int found = 0, n = 1, num = 1;

    while (fgets(line, sizeof(line), allPokemonFile)) {
        Pokemon pokemon;

        //개행 문자 제거
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        // 문자열에서 데이터 추출
        sscanf(line, "%d %s %s %d %d", &pokemon.number, pokemon.name, pokemon.type, &pokemon.attack, &pokemon.hp);

        if (strcmp(pokemon.name, pokemonName) == 0) {
            sscanf(line, "%d %s %s %d %d", pokemon.number, pokemon.name, pokemon.type, pokemon.attack, pokemon.hp);

            fprintf(userPokemonFile, "%d %s %s %d %d\n", pokemon.number, pokemon.name, pokemon.type, pokemon.attack, pokemon.hp);
            found = 1;
            num++;
            break;
        }
    }

    if (!found) {
        printf("%s 를 찾지 못했습니다..\n", pokemonName);
    }

    fclose(allPokemonFile);
    fclose(userPokemonFile);
    printf("파일 종료\n");
}

void print_spec(void){
    FILE *userPokemonList = fopen("user_pokemon.txt", "r");
    
    if (userPokemonList == NULL) {
        printf("파일을 열지 못함");
        return;
    }

    Pokemon myPokemon;

    printf("\n===== 보유한 포케몬 목록 =====\n");

    while (fscanf(userPokemonList, "%d %s %s %d %d", &myPokemon.number, myPokemon.name, myPokemon.type, &myPokemon.attack, &myPokemon.hp) != EOF) {
        printf("Number: %d\n", myPokemon.number);
        printf("Name: %s\n", myPokemon.name);
        printf("Type: %s\n", myPokemon.type);
        printf("ATK: %d\n", myPokemon.attack);
        printf("HP: %d\n", myPokemon.hp);
        printf("------------------------\n");
    }

    printf("종료");
    fclose(userPokemonList);
}