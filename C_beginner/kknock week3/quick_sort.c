#include <stdio.h>
#define MAX_SIZE 9 
#define SWAP(x, y, tmp) ((tmp)=(x), (x)=(y), (y)=(tmp))

int partition (int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);

int main(){
    int arr[MAX_SIZE] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

    quick_sort(arr, 0, MAX_SIZE - 1);

    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

int partition (int arr[], int left, int right){
    int pivot = arr[left], tmp;
    int low, high;

    low = left + 1;
    high = right;
    
    //low와 high가 교차하면 종료
    while(low < high) {
        //pivot과 비교, low가 작으면 오른쪽(다음) 검사
        //low가 크면 스톱
        while(low <= right && pivot > arr[low]){
            low++;
        }

        //pivot과 비교, high가 크면 왼쪽(다음) 검사
        //high가 작으면 스톱
        while(high >= left && arr[high] > pivot){
            high--;
        }
        
        //low가 pivot보다 크고, high가 pivot보다 작음
        //low가 high를 넘지 않으면 교환
        if(low < high) {
            SWAP(arr[low], arr[high], tmp);
        }
    }
    //low와 high가 교차됨
    //high
    SWAP(arr[left], arr[high], tmp);
    
    return high;    //pivot 반환
}

void quick_sort(int arr[], int left, int right){
    if(left < right){
        //pivot 위치 정렬
        int p = partition(arr, left, right);

        //pivot보다 작은 값들 정렬
        quick_sort(arr, left, p - 1);

        //pivot보다 큰 값들 정렬
        quick_sort(arr, p + 1, right);
    }
}