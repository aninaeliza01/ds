#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void insertAtBeginning(int);
void insertAtEnd(int);
void between(int,int);
void deleteFromBeg();
void deleteFromEnd();
void deleteSpecificLocation(int);
void display();
struct Node
{
  int data;
 struct Node*next;
}*head = NULL,*temp;
void main()
{
    int value,choice,loc1;
while(1)
{
    printf("***menu***\n");
    printf("Insert\n1.At beginning\n 2.At end\n 3.Between node\nDELETE \n4.At beginning\n 5.At end\n6.Between node\n 7.display\n");
    printf("enter your choice:");
    scanf("%d",&choice);
switch(choice)
{
    case 1: printf("Enter the value to be insert: ");
		    scanf("%d",&value);
	    	insertAtBeginning(value);
        break;
    case 2:printf("enter a value you want to insert:");
           scanf("%d",&value);
           insertAtEnd(value);
           break;
   case 3:
           printf("Enter the location: ");
           scanf("%d",&loc1);
           printf("Enter the value: ");
           scanf("%d",&value);
           between(value,loc1);
           break;
    case 4:
           deleteFromBeg(value);
           break;
    case 5:
           deleteFromEnd(value);
           break;
    case 6:
           printf("Enter the value: ");
           scanf("%d",&value);
           deleteSpecificLocation(value);
           break;
    case 7:display();
          break;
	        default: printf("\nWrong selection!!! Please try again!!!\n");
}
}
}
void insertAtBeginning(int value)
{
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}
void insertAtEnd(int value)
{
    struct Node *newNode=malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if(head == NULL)
	head = newNode;
   else
   {
      struct Node *temp = head;
      while(temp->next != NULL)
      { temp = temp->next; }
    	temp->next = newNode;
}
}
void between(int value,int loc1)
{
  struct Node*newnode;
  newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=value;
  if(head==NULL)
  {
      printf("The list is empty");
      exit(0);
  }

  else
  {
      temp=head;
      while(temp->data!=loc1)
      {
        if(temp->next==NULL)
        {
            printf("Location not found\n");
            exit(0);
        }
        else
        temp=temp->next;
      }
      newnode->next=temp->next;
      temp->next=newnode;

  }

}
void deleteFromBeg()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("List is already empty");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteFromEnd()
{
    struct Node*prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        prev->next= NULL;
    }
    free(temp);
}
void deleteSpecificLocation(int value)
{
    struct Node*prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
 if(head==NULL)
    {
        printf("There is no element to delete");
    }
    temp=head;
    if((temp->next!=NULL)&&(temp->data==value))
    {
        printf("The node %d deleted %d and now list is empty",temp->data);
        temp=temp->next;
        free(temp);
    }
    while((temp!=NULL)&&(temp->data!=value))
    {
         prev=temp;
         temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not Found");
    }
    else
    {
    prev->next=temp->next;
    free(temp);
    }
}
void display()
{
    if(head == NULL)
    printf("\nList is Empty!!!\n");
    else
    {
        temp= head;
    while(temp->next!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("%d-->NULL\n",temp->data);
    }
}
