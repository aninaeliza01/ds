#include<stdio.h>
#include<stdlib.h>
void insertAtBeg(int);
void insertAtEnd(int);
int insertAtLocation(int,int);
void deleteFromBeg();
void deleteFromEnd();
void deleteFromLocation(int);
void display();
struct node
{
  int data;
  struct node *next;
  struct node *prev;
}*head=NULL,*prev=NULL,*next=NULL,*temp;
void main()
{
    int a,c,l;
    while(1)
    {
        printf("\n*MENU*\n");
        printf(" 1.insert at beginning\n 2.insert at end\n 3.insert at specific location\n 4.delete from beginning\n 5.delete from end\n 6.delete from specific location\n 7.display\n 8.Exit\n");
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
            case 4:deleteFromBeg();
            break;

        case 5:deleteFromEnd();



            break;


        case 6:

            deleteSpecificLocation();
            break;
        case 7:
            display();
            break;
            case 8:exit(0);
            break;
            default: printf("\nCHOOSE ANOTHER OPTION!!!!!\n");
       }
   }
}
void insertatbeg(int a)
{
    struct node *newnode=malloc(sizeof(struct node*));
    newnode->data=a;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertatend(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
        newnode->next=NULL;
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
    }
    else
        while(temp->next!=NULL)
    {
           temp->next=newnode;
           newnode->prev=temp;
    }
}
void insertafteravalue(int value,int loc)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    temp=head;
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    while(temp->data!=loc&&temp!=NULL)
    {
        temp=temp->next;
    }
        if(temp==NULL)
        {
            printf("\nLOCATION NOT FOUND!!!\n");
        }
        else
            if(temp->next==NULL)
        {
            temp->next=newnode;
             newnode->next=NULL;
             newnode->prev=temp;
        }
        else
        {
        newnode->next=temp->next;
        newnode->next->prev=temp;
        newnode->prev=temp;
        temp->next=newnode;
        }
}

int deleteFromBeg ()
{
    if(head == NULL)
    {
        printf("List is already empty");
    }
    else
    {
        temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
    }
}

int deleteFromEnd()
{
    if (head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp==head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->prev->next=NULL;
    }
}
int deleteSpecificLocation()
{
    int value;
    printf("\nenter the value to be the value deleted : ");
    scanf("%d",&value);
    if (head==NULL)
    {
        printf("the list is empty");
    }
    else
    {
       temp=head;
        while(temp->data!=value)
        {
            temp=temp->next;
            if (temp==NULL)
            {
                printf("ELEMENT NOT FOUND!!!");
                return 0;
            }

    }
    if(temp->prev==NULL && temp->next==NULL)
            {

                head=NULL;
                free(temp);
                printf("NULL");

            }
            else if(temp->next==NULL)
            {
                temp->prev->next=NULL;
                free(temp);
            }
            else if(temp->prev==NULL)
            {
                temp->next->prev=NULL;
                head=temp->next;
                free(temp);
            }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);

        }

    }
}



int display()
{
    if(head==NULL)
    {
        printf("\n list is empty\n");
        return 0;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {

            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->NULL",temp->data);

    }
}

