#include<stdio.h>
void main()
{
    int arr1[100],arr2[100],arr3[100];
    int n1,n2,n3;
    int i,j,a;
    printf("enter the size of 1st array:");
    scanf("%d",&n1);
    printf("enter the elements:");
    for(i=0;i<n1;i++)
    {
            scanf("%d",&arr1[i]);
    }
     printf("enter the size of 2nd array:");
    scanf("%d",&n2);
    printf("enter the elements:");
    for(i=0;i<n2;i++)
    {
            scanf("%d",&arr2[i]);
    }
 printf("merged array:");
 n3=n1+n2;
 for(i=0;i<n1;i++)
 {
     arr3[i]=arr1[i];
 }
  for(i=0;i<n2;i++)
  {
      arr3[i+n1]=arr2[i];
  }
  for(i=0;i<n3;i++)
  {
      printf("%d\t",arr3[i]);
  }
  printf("\n sorted array:");
    for(i=0;i<n3;i++)
    {
        for(j=i;j<n3;j++)
        {
            if(arr3[i]>arr3[j])
            {
                a=arr3[i];
                arr3[i]=arr3[j];
                arr3[j]=a;
            }
        }
        printf("%d \t",arr3[i]);
    }
}

