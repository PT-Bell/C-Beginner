#include <stdio.h>

void SelectionSort(int arr[], int size)
{
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[10] = {5, 3, 7, 6, 1, 9, 0, 2, 8, 4};

    SelectionSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}