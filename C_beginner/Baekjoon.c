#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x; //몸무게
    int y; //키
} Person;

int main() {
    int N, rank;
    
    scanf("%d", &N);
    Person *arr = (Person*)malloc(sizeof(Person) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < N; i++) {
        rank = 1;
        for (int j = 0; j < N; j++) {
            if (arr[i].x < arr[j].x && arr[i].y < arr[j].y) {
                rank++;
            }
        }
        printf("%d ", rank);
    }
    
    free(arr);
    return 0;
}
