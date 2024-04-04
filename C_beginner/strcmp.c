#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello";
    char str2[] = "hello";
    
    int result = strcmp(str1, str2);
    
    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("String 1 is less than String 2\n");
    else
        printf("String 1 is greater than String 2\n");

    return 0;
}
