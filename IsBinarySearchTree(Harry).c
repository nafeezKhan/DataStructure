#include <stdio.h>
#include <stdlib.h>
// #include <limits.h> //s included to use the constants defined in it,-1specifically INT_MIN and INT_MAX

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

int isBST(struct node *root)
{
    static struct node *prev = 0;
    if (root != 0 )
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != 0 && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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
