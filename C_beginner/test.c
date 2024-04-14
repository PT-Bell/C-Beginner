#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

int main() {
    int n = 3;  // 배열 크기
    Person *people = (Person *) malloc(n * sizeof(Person));

    if (people == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 배열 구조체 초기화
    strcpy(people[0].name, "John");
    people[0].age = 30;
    people[0].height = 175.5;

    strcpy(people[1].name, "Alice");
    people[1].age = 25;
    people[1].height = 160.7;

    strcpy(people[2].name, "Bob");
    people[2].age = 35;
    people[2].height = 180.2;

    // 배열 구조체 출력
    for (int i = 0; i < n; i++) {
        printf("Person %d: Name = %s, Age = %d, Height = %.2f\n",
               i + 1, people[i].name, people[i].age, people[i].height);
    }

    // 동적으로 할당된 메모리 해제
    free(people);

    return 0;
}
