#include <stdio.h>

void selection_sort(int arr[], int size);

int main() {
    int arr[10] = {5, 3, 7, 6, 1, 9, 0, 2, 8, 4};

    selection_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selection_sort(int arr[], int size) {
    int min, temp;

    //i번째 값과 뒤의 숫자들 중 최솟값을 비교하며 swap
    //마지막 숫자는 자동으로 정렬됨. (size - 1)
    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            //최솟값 탐색, j로 순회하며 i = 0 부터 비교
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        //j로 최솟값을 찾아 min 값이 변경됐을 때만 swap
        //아니면 swap 안함
        if (i != min) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}