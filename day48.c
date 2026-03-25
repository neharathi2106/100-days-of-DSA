#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int leafCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            continue;

        int left = 2*i + 1;
        int right = 2*i + 2;

        if((left >= n || arr[left] == -1) &&
           (right >= n || arr[right] == -1)) {
            leafCount++;
        }
    }

    printf("%d\n", leafCount);

    return 0;
}