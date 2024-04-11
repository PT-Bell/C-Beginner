#include <stdio.h>
#define MAX_SIZE 8

void bubble_sort(int arr[], int size);

int main() {
    int arr[MAX_SIZE] = {7, 5, 1, 3, 2, 6, 8, 4};
    
    bubble_sort(arr, MAX_SIZE);

    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubble_sort(int arr[], int size) {
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            //현재 검사중인 자료
            int tmp = arr[j];

            //tmp가 뒷 수보다 더 크면 교환
            if(tmp > arr[j+1]) {
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
