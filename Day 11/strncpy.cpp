#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, strncpy!";
    char destination[20];

    // 使用 strncpy 复制字符串
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0'; // 确保目标缓冲区以 '\0' 结尾

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
