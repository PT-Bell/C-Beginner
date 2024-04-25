#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon_menu.h"

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
    printf("     1.새로하기  2.이어하기\n");
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
            printf("잘못된 입력\n");
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
            printf("파이리\n");
            return;

            case 2:
            readAndSavePokemon("이상해씨");
            printf("이상해씨\n");
            return;

            case 3:
            readAndSavePokemon("꼬부기");
            printf("꼬부기\n");
            return;

            default:
            break;
        }
    }while(choice != 1 || choice != 2 || choice != 3);
}

void readAndSavePokemon(const char* pokemonName) {
    FILE *allPokemonFile = fopen("all_pokemon.txt", "r");
    FILE *userPokemonFile = fopen("user_pokemon.txt", "w");

    if (allPokemonFile == NULL) {
        printf("all_pokemon.txt 파일 열기 오류\n");
        return;
    }
    if (userPokemonFile == NULL) {
        printf("user_pokemon.txt 파일 열기 오류\n");
        return;
    }

    char line[500];
    int found = 0; 

    while (fgets(line, sizeof(line), allPokemonFile)) {
        char name[50], type[20];
        int attack, hp;
        printf("저장 함수\n");
        // 개행 문자 제거
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        

        sscanf(line, "%*d\t%49s\t%19s\t%d\t%d", name, type, &attack, &hp);

        if (strcmp(name, pokemonName) == 0) {
            printf("저장\n");
            fprintf(userPokemonFile, "%s %s %d %d\n", name, type, attack, hp);
            found = 1; 
            break;
        }
    }
    if (!found) {
        printf("%s 포켓몬을 찾을 수 없습니다.\n", pokemonName);
    }

    fclose(allPokemonFile);
    fclose(userPokemonFile);
}

void print_spec(void){
    FILE *userPokemonList = fopen("user_pokemon.txt", "r");
    
    if (userPokemonList == NULL) {
        printf("파일 열기 오류");
        return;
    }

    Pokemon pokemon;

    printf("===== 유저 포켓몬 스펙 =====\n");

    while (fscanf(userPokemonList, "%49s %19s %d %d", pokemon.name, pokemon.type, &pokemon.attack, &pokemon.hp) != EOF) {
        printf("이름: %s\n", pokemon.name);
        printf("속성: %s\n", pokemon.type);
        printf("공격력: %d\n", pokemon.attack);
        printf("HP: %d\n", pokemon.hp);
        printf("------------------------\n");
    }

    printf("통과");
    fclose(userPokemonList);
}