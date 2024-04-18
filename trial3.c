#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void findAndPrintChildren(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    if (root->data == key)
    {
        printf("Node %d found.\n", key);
        if (root->left != NULL)
            printf("Left Child: %d\n", root->left->data);
        else
            printf("No Left Child\n");

        if (root->right != NULL)
            printf("Right Child: %d\n", root->right->data);
        else
            printf("No Right Child\n");

        return;
    }

    if (key < root->data)
        findAndPrintChildren(root->left, key);
    else
        findAndPrintChildren(root->right, key);
}

int main()
{
    struct node *root = NULL;
    int value;

    do
    {
        printf("Enter data (-1 to stop): ");
        scanf("%d", &value);

        if (value != -1)
        {
            root = insert(root, value);
        }
    } while (value != -1);

    int key;
    printf("Enter the node value to find its children: ");
    scanf("%d", &key);

    findAndPrintChildren(root, key);

    return 0;
}
