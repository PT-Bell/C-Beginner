#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[15];
    char number[20];
} PhoneBook;

int main(){
    int N = 2, size = 0;
    PhoneBook *arr = (PhoneBook*)malloc(sizeof(PhoneBook) * N);

    if(arr == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    while(size < N) {
        int duplicate_check = 0; //중복 체크

        printf("이 름 : ");
        scanf("%s", arr[size].name);

        int len = strlen(arr[size].name);
        if(len > 15){
            printf("입력 가능한 글자 수를 초과하였습니다.\n");
            continue;
        }

        printf("전 화 번 호 : ");
        scanf("%s", arr[size].number);

        for (int i = 0; i < size + 1; i++) {
            for (int j = i + 1; j < size + 1; j++) {
                if (strcmp(arr[i].name, arr[j].name) == 0 &&
                        strcmp(arr[i].number, arr[j].number) == 0) {
                    printf("== 비 정 상  입 력 ==\n");
                    printf("데 이 터 가  중 복 되 었 습 니 다 .\n");
                    duplicate_check = 1;
                    break;
                }
            }
        }
        if(duplicate_check){
                continue;
        }

        size++;
        int exit_choice;

        if(size >= 2){
            while(1){
                printf("추가 입력 0, 종료 1: ");
                scanf("%d", &exit_choice);

                if(exit_choice == 0){
                    N++;
                    arr = (PhoneBook*)realloc(arr, sizeof(PhoneBook) * N);
                    if(arr == NULL){
                        printf("Memory allocate failed\n");
                        return 1;
                    }
                    else {
                        break;
                    }
                }
                else if(exit_choice == 1) {
                    size = N;
                    break;
                }
                else
                        printf("다시 입력하세요.\n");
            }
        }
    }

    printf("\n== 전 화 번 호 부 ==\n\n");
    for (int i = 0; i < size; i++) {
        printf("%s      %s\n", arr[i].name, arr[i].number);
    }
    printf("\n===================\n\n");

    free(arr);
    return 0;
}