#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int height = 0;
    int i = 0;

    while (i < n) {
        int nodes = 1 << height; // nodes at current level
        int valid = 0;

        for (int j = 0; j < nodes && i < n; j++, i++) {
            if (arr[i] != -1) {
                valid = 1;
            }
        }

        if (!valid) break;
        height++;
    }

    printf("%d\n", height);

    return 0;
}