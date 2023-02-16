#include<stdio.h>
int a[20][20],v,f,i,j,q[20],front=0,rear=0,visited[20],m=0,s,k;
int main()
{
    printf("Graph creation\n");
    printf("Enter the number of vertices : ");
    scanf("%d",&v);
    printf("Enter the graph in adjacency matrix form :\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex :");
    scanf("%d",&s);
    i=s;
    q[front]=i;
    printf("\n\n\nBreadth first traversal for the graph : %d\t",q[front]);
    visited[m]=i;
    m=m+1;
    j=0;
    while(front<=rear)
    {
        if(a[i][j]==1)
        {
            f=0;
            for(k=0;k<m;k++)
            {
                if(visited[k]==j)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                q[rear]=j;
                printf("%d\t",q[rear]);
                rear=rear+1;
                visited[m]=j;
                m=m+1;
            }
        }
        j=j+1;
        if(j==v)
        {
            i=q[front];
            front=front+1;
            j=0;
        }
    }
}
