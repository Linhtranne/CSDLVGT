#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float score;
} Student;

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) {
        return 1;
    }

    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Ten: ");
        scanf(" %s", students[i].name);
        printf("Điem: ");
        scanf("%f", &students[i].score);
    }
    char searchName[50];
    printf("\nNhap ten sinh vien can tim: ");
    scanf(" %s", searchName);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\nDiem cua: %s la: %.2f\n", students[i].name, students[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien.\n");
    }

    return 0;
}
