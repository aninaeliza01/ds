#include<stdio.h>
#include<stdlib.h>
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAfter(int,int);
void deleteFromBeg(int);
void deleteFromend(int);
void deleteSpecificLocation(int);
void display();
struct node
{
    int data;
    struct node*next;
}*head=NULL,*temp;
void main()
{
   int value,choice,location;
   while(1)
   {
       printf("\n***MENU*\n");
       printf("1.At beginning\n 2.At end\n 3.After\n  4.From beginning\n 5.From end\n 6.Specific location\n 7.Display\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:printf("Enter the value: ");
           scanf("%d",&value);
           insertAtBeginning(value);
           break;
           case 2:printf("Enter the value: ");
           scanf("%d",&value);
           insertAtEnd(value);
           break;
           case 3:
           printf("Enter the location: ");
           scanf("%d",&location);
           printf("Enter the value: ");
           scanf("%d",&value);
           insertAfter(value,location);
           break;
           case 4:printf("Enter the value: ");
           scanf("%d",&value);
           deleteFromBeg(value);
           break;
           case 5:printf("Enter the value: ");
           scanf("%d",&value);
           deleteFromEnd(value);
           break;
           case 6:
           printf("Enter the value: ");
           scanf("%d",&value);
           deleteSpecificLocation(value);
           break;
           case 7:display();
           break;
           default:printf("Wrong selection!!!try again!!\n");

       }

   }
}
void insertAtBeginning(int value)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertAtEnd(int value)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        struct node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertAfter(int value,int location)
{
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=value;
  if(head==NULL)
  {
      printf("The list is empty");
      exit(0);
  }

  else
  {
      temp=head;
      while(temp->data!=location)
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
void deleteFromBeg(int value)
{
    struct node *temp;
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
void deleteFromEnd(int value)
{
    struct node*prev;
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
    struct node*prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
 if(head==NULL)
    {
        printf("There is no element to delete");
        return 0;
    }
    temp=head;
    if((temp->next!=NULL)&&(temp->data==value))
    {
        printf("The node %d deleted %d and now list is empty",temp->data);
        temp=temp->next;
        free(temp);
        return 0;
    }
    while((temp!=NULL)&&(temp->data!=value))
    {
         prev=temp;
         temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not Found");
        return 0;
    }
    else
    {
    prev->next=temp->next;
    free(temp);
    }
}
    void display()
    {
        printf("one node inserted\n");
        struct node*temp=head;
        printf("\n list elements are-\n");
          while(temp->next!=NULL)
     {
       printf("%d-->",temp->data);
       temp=temp->next;
     }
      printf("%d-->NULL",temp->data);
   }
