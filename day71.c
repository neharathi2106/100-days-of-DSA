#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    // initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    while (q--) {
        char op[20];
        int key;

        scanf("%s %d", op, &key);

        // convert operation to uppercase
        for (int i = 0; op[i]; i++)
            op[i] = toupper(op[i]);

        int h = key % m;

        // INSERT
        if (strcmp(op, "INSERT") == 0) {
            int i = 0;

            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }

                i++;
            }
        }

        // SEARCH
        else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;

            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY)
                    break;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}