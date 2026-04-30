#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays
typedef struct {
    int sum;
    int index;
} Hash;

int main() {
    int arr[MAX], n;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Hash hash[MAX];  // store prefix sum and first index
    int hashSize = 0;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum becomes 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if prefixSum already exists
        int found = -1;
        for (int j = 0; j < hashSize; j++) {
            if (hash[j].sum == prefixSum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int len = i - hash[found].index;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // Store first occurrence of prefixSum
            hash[hashSize].sum = prefixSum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}