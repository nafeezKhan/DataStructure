#include <stdio.h>
#include <stdlib.h>
#include <limits.h>//s included to use the constants defined in it,-1specifically INT_MIN and INT_MAX

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:(-1 for no node)\n");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    newnode->left = create();
    printf("Enter right of %d\n", x);
    newnode->right = create();
    return newnode;
}

/*void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}*/

int isBSTUtil(struct node *root, int min, int max)
{
    if (root == 0)
    {
        return 1; // Empty tree is a BST
    }

    if (root->data < min || root->data > max)
    {
        return 0; // Node's data violates the BST property
    }

    // Check the subtrees recursively
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

int isBST(struct node *root)
{
    // INT_MIN and INT_MAX are used as initial min and max values for root
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    struct node *root;
    root = create();

    // printf("inorder is:\n");
    // inorder(root);

    if (isBST(root))
    {
        printf("\nThe tree is a Binary Search Tree (BST).\n");
    }
    else
    {
        printf("\nThe tree is not a Binary Search Tree (BST).\n");
    }

    return 0;
}
