#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}


int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isComplete(struct Node* root, int index, int total) {
    if (!root) return 1;
    if (index >= total) return 0;

    return isComplete(root->left, 2*index + 1, total) &&
           isComplete(root->right, 2*index + 2, total);
}


int isMinHeap(struct Node* root) {
    if (!root) return 1;

    
    if (!root->left && !root->right)
        return 1;

    
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    
    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}