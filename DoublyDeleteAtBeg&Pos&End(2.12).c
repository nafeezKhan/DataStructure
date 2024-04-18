#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;//purpose of tail is to traverse the list for displaying its contents.
int count = 0; // declare count globally;for counting the nodes

void create()
{
    head = 0;
    int choice = 1;

    while (choice)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
        count++;
    }
}

void display()
{
    struct node *tail;
    tail = head;
    while (tail != 0)
    {
        printf("%d ", tail->data); // Add a space after %d; making the output more readable
        tail = tail->next;
    }
}
void DeleteFromBegining()
{
    struct node *temp;
    if (head == 0)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        free(temp);
    }
}

void DeleteFromPosition()
{
    int pos;
    int i = 1;
    struct node*temp;//purpose of temp is to locate the node at the specified position for deletion.
    temp = head;
    printf("\nEnter position:\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)//for position 1, we can write else if{DeleteFromBeg}
    {                          //for position last, we can write else if{DeleteFromEnd}
        printf("Invalid position\n");
        return;
    }
    else if (pos==1)
    {
        DeleteFromBegining();
    }
    else if (pos==count)
    {
       DeleteFromEnd();
    }
    
    
    else
    {
    
    while (i < pos)//***
    {
        temp = temp->next;
        i++;
    }
     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
     free(temp);
     
    }
    
   
}
void DeleteFromEnd()
{
    struct node*temp;
    if (head==0)//or tail==0;
    {
        printf("list is empty\n");

    }
    else
    {
        temp=tail;
        tail->prev->next=0;//we also can write like, tail=tail->prev; tail->next=0;
        tail=tail->prev;//we also can write like, tail=temp->prev;
        free(temp);
    }
    
}

int main()
{
    create();
    display();
    DeleteFromPosition();
    printf("\nAfter Delete From Position:\n");
    display();
    return 0;
}
