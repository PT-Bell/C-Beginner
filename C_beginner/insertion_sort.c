#include <stdio.h>

void insertion_sort(int arr[], int length);

int main(){
    int length = 0;
    int arr[5] = {9, 4, 3, 5, 1};

    length = sizeof(arr) / sizeof(int);

    insertion_sort(arr, length);

    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void insertion_sort(int arr[], int length){
    int key, j;

    for(int i = 1; i < length; i++){
        key = arr[i];   //key를 2번째 index부터 설정
        j = i - 1;      //직전 index와 비교

        //직전 값이 key보다 클 때만 위치 바꾸기
        while(j >= 0 && arr[j] >= key) {
            arr[j+1] = arr[j];
            j--;
        }

        //key에 저장했던 값으로 정렬
        arr[j + 1] = key;
    }
}
