#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;//'tail' (to traverse the list)      

void create()
{
    head = 0;
    int choice = 1;
     while (choice)
     {
        struct node*newnode;  //'new_node' (to create new nodes)
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if (head==0)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        
        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
     }
      
}     
  void display()
     {
        struct node*tail;
        tail=head;
        while (tail!=0)
        {
            printf("%d ", tail->data);// Add a space after %d; making the output more readable
            tail=tail->next;
        }
        
     }
void InsertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end :\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
int main()
{
    create();
    display();
    InsertAtEnd();
    printf("After Insert At End:\n");
    display();
    return 0;
}