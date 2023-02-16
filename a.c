#include<stdio.h>
#include<stdlib.h>
void insert(int);
void delete();
void display();
struct Node
{
  int data;
 struct Node*next;
}*rear = NULL,*temp;
void main()
{
    int value,choice;
while(1)
{
    printf("***menu***\n");
    printf("\nQUEUE\n1.insert\n 2.delete\n3.display\n");
    printf("enter your choice:");
    scanf("%d",&choice);
switch(choice)
{
    case 1: printf("enter a value you want to insert:");
           scanf("%d",&value);
           insert(value);
           break;
   case 2: delete(value);
           break;
   case 3:display();
          break;
	        default: printf("\nWrong selection!!! Please try again!!!\n");
}
}
}
void insert(int value)
{
    struct Node *newNode=malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if(rear == NULL)
	rear = newNode;
   else
   {
      struct Node *temp = rear;
      while(temp->next != NULL)
      { temp = temp->next; }
    	temp->next = newNode;
}
}
void delete()
{
    struct Node *temp;
    if(rear == NULL)
    {
        printf("QUEUE is already empty");
    }
    else
    {
        temp=rear;
        rear=rear->next;
        free(temp);
    }
}
void display()
{
    if(rear == NULL)
    printf("\nQUEUE is Empty!!!\n");
    else
    {
        temp= rear;
    while(temp->next!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("%d-->NULL\n",temp->data);
    }
}
