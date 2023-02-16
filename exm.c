#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left,*right;
}*root=NULL;
struct tree * newNode(int item)
{
    struct tree*temp=(struct tree*) malloc(sizeof(struct tree*));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(struct tree* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct tree* insert(struct tree* node,int data)
{
 if(node==NULL)
    return newNode(data);
 if(data<node->data)
    node->left=insert(node->left,data);
 else
    node->right=insert(node->right,data);
 return node;
}
struct tree* minValueNode(struct tree* node)
{
 struct tree*current= node;
 while(current&&current !=NULL)
    current=current->left;
 return current;
}
struct tree* deleteNode(struct tree*root,int data)
{
    struct tree*temp=(struct tree*) malloc(sizeof(struct tree*));
    if(root==NULL)
    {
        printf("item not found");
        return root;
    }

    else if(data <root->data)
    {
        root->left=deleteNode(root->left,data);
    }
    else if(data> root->data)
        root->right=deleteNode(root->right,data);
    else
    {
        if(root->left==NULL)
        {
            struct tree*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
           struct tree*temp=root->left;
            free(root);
            return temp;
        }
        struct tree* temp = minValueNode(root->right);
        root->data= temp->data;
        root->right=deleteNode(root->right,data);
    }
    return root;
}
int search(struct tree*node,int data)
{
    while(node!=NULL)
    {
        if(data==node->data)
        return 1;
        else if(data>node->data)
    {
        node = node->right;
    }
    else
        node = node->left;
    }
return 0;
}
int main(){
int ch,res,elt,item;
printf( "* MENU *");
printf("\n 1.Insertion ");
printf("\n 2.Search ");
printf("\n 3.Deletion ");
printf("\n 4.Inorder Traversal ");
printf("\n 0.Exit");
while(1)
{
    printf("\nEnter the choice : \n");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d",&elt);
            root = insert(root,elt);
            printf("%d , inserted! ",elt);
            break;
        case 2:
            printf("Enter the data to be searched:\t");
            scanf("%d",&item);
            res = search(root,item);
            if(res==1){
                printf("\nkey found!\n");
            }
            else{
                printf("\nkey not found!\n");
            }
            break;
        case 3:
             if(root == NULL)
                printf("empty binary search tree! \n");
             else{
               printf("Enter the data to delete:\t");
               scanf("%d",&item);
               root = deleteNode(root, item);
             }
            break;
        case 4:
               if(root == NULL)
                printf("empty binary search tree! \n");
               else{
               printf("Inorder traversal of the given tree \n");
               inorder(root);
               }
              break;
        case 0:
            printf("\nExited!\n");
            exit(0);
            }
        }
}
