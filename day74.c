#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];   // store input names
    char unique[1000][50];  // store unique names
    int count[1000] = {0};  // vote counts

    int uniqueCount = 0;

    // Input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        // Check if name already exists
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output
    printf("%s %d\n", winner, maxVotes);

    return 0;
}