#include <stdio.h>
#include <stdlib.h>

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

void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root;
    //root=0;
    root = create();

    printf("Preorder is:\n");
    preorder(root);

    return 0;
}
