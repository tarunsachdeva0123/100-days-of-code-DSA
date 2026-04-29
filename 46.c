#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* queue[100];
int front = -1, rear = -1;
void enqueue(struct Node* node)
{
    if (rear == 99)
        return;
    
    if (front == -1)
        front = 0;
    
    queue[++rear] = node;
}

struct Node* dequeue()
{
    if (front == -1 || front > rear)
        return NULL;

    return queue[front++];
}

void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main()
{


    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}