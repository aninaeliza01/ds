#include<stdio.h>
#include<stdlib.h>
void insertAtBeg(int);
void insertAtEnd(int);
int insertAtLocation(int,int);
void deleteFromBeg();
void deleteFromEnd();
void deleteFromLocation(int);
void display();
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}*head=NULL,*prev=NULL,*next=NULL,*temp;
void main()
{
    int a,c,l;
    while(1)
    {
        printf("\n**DOUBLY LINKED LIST*\n");
        printf(" Insert \n 1.at beginning\t 2.at end\t 3. at specific location\n Delete \n 4.from beginning\t 5.delete from end\t 6.delete from specific location\n 7.display\n 8.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the value:");
            scanf("%d",&a);
            insertAtBeg(a);
            break;
            case 2:printf("Enter the value: ");
           scanf("%d",&a);
           insertAtEnd(a);
           break;
           case 3:
           printf("Enter the location: ");
           scanf("%d",&l);
           printf("Enter the value:");
           scanf("%d",&a);
           insertAtLocation(a,l);
           break;
           case 4:
            deleteFromBeg();
            break;
           case 5:
           deleteFromEnd();
           break;
           case 6:printf("Enter the value: ");
           scanf("%d",&a);
           deleteFromLocation(a);
           break;
           case 7:display();
           break;
           case 8:exit(0);
           break;
           default:printf("Wrong selection!!!\n");
       }

   }
}
void insertAtBeg(int a)
{
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->prev = NULL;
    if(head==NULL)
    {
         newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }


}
void insertAtEnd(int a)
{
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->next = NULL;
    if(head==NULL)
    {
        newNode->prev=NULL;
        head=newNode;
    }

    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
int insertAtLocation(int a,int l)
{

   struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
  //newnode->next=NULL;
 // newNode->prev=NULL;
  if(head==NULL)
  {
      printf("The list is empty");
      //exit(0);
  }

  else
  {
      int f=0;
      temp=head;
      while(temp!=NULL)
      {
          if(temp->data==l)
          {
              f=1;
              break;
          }
          temp=temp->next;
          //printf("\n\n\n%d",temp->data);

      }
        if(f==0)
        {
            printf("Location not found\n");
            return 0;
        }
        else
        {


             if(temp->next==NULL)
            {
                temp->next=newNode;
                newNode->next=NULL;
                newNode->prev=temp;
            }
            else
            {

                newNode->next=temp->next;
                newNode->next->prev=newNode;
                newNode->prev=temp;
                temp->next=newNode;

            }

        }

      }

}

void deleteFromBeg()
{

    if(head == NULL)
    {
        printf("List is empty");
        return 0;
    }
    if(head->next==NULL)
    {

        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {

        temp=head;
        head=head->next;
        head->prev=NULL;


        free(temp);

    }
}
void deleteFromEnd()
{

    if(head == NULL)
    {
        printf("List is empty");
        return 0;
    }
    if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
void deleteFromLocation(int a)
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    {
        struct Node *temp=head;
        while(temp->data!=a)
        {
            if(temp->next==NULL)
            {
                printf("Value not found");
                return 0;

            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp==head)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            temp->prev->next=temp->next;
            free(temp);
        }
        printf("Node deleted");
    }
}


void display()
    {
        if(head==NULL)
            printf("List is empty");
        else
        {
        temp=head;
        printf("\n list elements are-\n");
          while(temp->next!=NULL)
            {
                printf("%d<===>",temp->data);
                temp=temp->next;
            }

      printf("%d<===>NULL",temp->data);
        }
   }
