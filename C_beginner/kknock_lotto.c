#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;

    srand(time(NULL));

    printf("��÷ ����� :\n");

    for (int i = 0; i < 6; i++) {
        num = rand() % 46 + 1;
        printf("%d ", num);
    }

    printf("�Դϴ�!\n");

    return 0;
}
