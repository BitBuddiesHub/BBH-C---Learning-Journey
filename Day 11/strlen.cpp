#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    size_t length = strlen(str);

    printf("The length of the string \"%s\" is %zu.\n", str, length);

    return 0;
}