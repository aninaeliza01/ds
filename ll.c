#include<stdio.h>
#include<stdlib.h>
void insertatbegin(int);
void insertatend(int);
void insertafterpos(int,int);
void deleteatbegin();
void deleteatend();
void deleteafterpos(int);
void display();
struct node
{
    int data;
    struct node*prev;
    struct node*next;
}*head=NULL,*temp;
void main()
{
    int value,choice,loc;
    while(1)
    {
     printf("\n**DL**\nINSERT\n1.At begin\t2.At end\t3.After a position.\nDELETE\n4.At begin\t5.At end\t6.After a position.\n7.Display\n");
    printf("ENTER THE CHOICE:");
    scanf("%d",&choice);
        switch(choice)
    {
        case 1: printf("enter the value:");
        scanf("%d",&value);
        insertatbegin(value);
        break;
        case 2: printf("\nenter the value:");
        scanf("%d",&value);
        insertatend(value);
        break;
        case 3: printf("\nenter the value:");
        scanf("%d",&value);
        printf("enter the location:");
        scanf("%d",&loc);
        insertafterpos(value,loc);
        break;
        case 4:deleteatbegin();
        break;
        case 5:deleteatend();
        break;
        case 6: printf("\nenter the value:");
        scanf("%d",&loc);
        deleteafterpos(loc);
        break;
        case 7: display();
        break;
        default:printf("\nINAVALID!!\n");
    }
    }
}
void insertatbegin(int value)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->data=value;
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
    temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node*));
     newnode->data=value;
     newnode->next=NULL;
     if(head==NULL)
     {
         head=newnode;
         newnode->next=NULL;
     }
     else
     {
    while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newnode;
     newnode->prev=temp;
     }
}
void insertafterpos(int value,int loc)
{
    temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node*));
     newnode->data=value;
     if(head==NULL)
     {
         printf("\nLIST IS EMPTY!!\n");
         return 0;
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
void deleteatbegin()
{
    temp=head;
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY!!\n");
        return 0;
    }
    else
    {
        head=temp->next;
        free(temp);
    }
}
void deleteatend()
{
    if(head == NULL)
    {
        printf("List is empty");

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

void deleteafterpos(int loc)
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else
        temp=head;
        while(temp->data!=loc)
        {
            if(temp->next==NULL)
            {
                printf("\nValue not found\n");
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

}
void display()
{
    temp=head;
if(head==NULL)
    {
        printf("\nLIST IS EMPTY!!\n");
        return 0;
    }
    else
     printf("\nNULL<--");
    while(temp->next!=NULL)
    {
        printf("%d<==>",temp->data);
        temp=temp->next;
    }
    printf("%d<==>",temp->data);
}

