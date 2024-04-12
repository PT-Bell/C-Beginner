#include <stdio.h>


int main(){
    int N = 0;
    int* weight;
    int* height;

    scanf("%d", &N);

    int* weight = (int*)malloc(sizeof(int) * N);
    int* height = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", weight[i], height[i]);
    }

    for(int i = 0; i < N; i++){
        printf("%d %d", weight[i], height[i]);
    }
    return 0;
}