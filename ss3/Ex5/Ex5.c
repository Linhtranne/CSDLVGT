#include <stdio.h>
#include <string.h>

int isPalind(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalind(str, start + 1, end - 1);
}
}
int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    int length = strlen(str);
    if (isPalind(str, 0, length - 1)) {
        printf("Palind valid\n");
    } else {
        printf("Palind invalid\n");
    }

    return 0;
}