#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Pair {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    int offset = 1000;
    int minHD = 0, maxHD = 0;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct TreeNode* node = p.node;
        int hd = p.hd;

        int idx = hd + offset;
        map[idx][count[idx]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}