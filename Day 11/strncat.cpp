#include <stdio.h>
#include <string.h>

int main() {
    char destination[20] = "Hello, ";
    char source[] = "World!";

    // 追加最多 5 个字符
    strncat(destination, source, 5);

    printf("Concatenated String: %s\n", destination);

    return 0;
}