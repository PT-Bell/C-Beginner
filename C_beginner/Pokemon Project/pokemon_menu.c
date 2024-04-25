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
    printf("     1.�����ϱ�  2.�̾��ϱ�\n");
    do {
        printf(">> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            start_newgame();
            return;

            case 2:
            printf("2��\n");
            return;

            default:
            printf("�߸��� �Է�\n");
            break;
        }
    }while(choice != 1 || choice != 2);
}

void start_newgame(void){
    int choice;
    printf("===============================\n");
    printf("��� ���ϸ��� �����Ͻðڽ��ϱ�?\n");
    printf("    1.���̸� 2.�̻��ؾ� 3.���α�\n");
    do {
        printf(">> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            readAndSavePokemon("���̸�");
            printf("���̸�\n");
            return;

            case 2:
            readAndSavePokemon("�̻��ؾ�");
            printf("�̻��ؾ�\n");
            return;

            case 3:
            readAndSavePokemon("���α�");
            printf("���α�\n");
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
        printf("all_pokemon.txt ���� ���� ����\n");
        return;
    }
    if (userPokemonFile == NULL) {
        printf("user_pokemon.txt ���� ���� ����\n");
        return;
    }

    char line[500];
    int found = 0; 

    while (fgets(line, sizeof(line), allPokemonFile)) {
        char name[50], type[20];
        int attack, hp;
        printf("���� �Լ�\n");
        // ���� ���� ����
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        

        sscanf(line, "%*d\t%49s\t%19s\t%d\t%d", name, type, &attack, &hp);

        if (strcmp(name, pokemonName) == 0) {
            printf("����\n");
            fprintf(userPokemonFile, "%s %s %d %d\n", name, type, attack, hp);
            found = 1; 
            break;
        }
    }
    if (!found) {
        printf("%s ���ϸ��� ã�� �� �����ϴ�.\n", pokemonName);
    }

    fclose(allPokemonFile);
    fclose(userPokemonFile);
}

void print_spec(void){
    FILE *userPokemonList = fopen("user_pokemon.txt", "r");
    
    if (userPokemonList == NULL) {
        printf("���� ���� ����");
        return;
    }

    Pokemon pokemon;

    printf("===== ���� ���ϸ� ���� =====\n");

    while (fscanf(userPokemonList, "%49s %19s %d %d", pokemon.name, pokemon.type, &pokemon.attack, &pokemon.hp) != EOF) {
        printf("�̸�: %s\n", pokemon.name);
        printf("�Ӽ�: %s\n", pokemon.type);
        printf("���ݷ�: %d\n", pokemon.attack);
        printf("HP: %d\n", pokemon.hp);
        printf("------------------------\n");
    }

    printf("���");
    fclose(userPokemonList);
}