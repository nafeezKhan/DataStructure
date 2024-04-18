#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int value)
{
    if (root == 0)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = newNode->right = 0; // 0 is used here to represent null
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
    else if (value == root->data)
    {
        printf("\nInsert Operation failed: Duplicate Entry!!\n");
    }

    return root;
}

struct node *findMin(struct node *root)
{
    while (root->left != 0)
    {
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == 0)
    {
        printf("Node not found.\n");
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == 0)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == 0)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != 0) // 0 is used here to represent null
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = 0; // 0 is used here to represent null
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

    printf("Inorder traversal before deletion is:\n");
    inorder(root);

    int key;
    printf("\nEnter the node value to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("\nInorder traversal after deletion is:\n");
    inorder(root);

    return 0;
}
