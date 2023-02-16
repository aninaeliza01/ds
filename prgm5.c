#include<stdio.h>
#include<stdlib.h>
void setunion();
void setintersection();
void setdifference();
void setequality();
int s1[10],s2[10],n1,n2,s[10],i;
int main()
{
printf("Enter the number of elements in first set : ");
    scanf("%d",&n1);
    printf("Enter the elements : ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the number of elements in second set : ");
    scanf("%d",&n2);
    printf("Enter the elements : ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&s2[i]);
    }
    int c;
    do
    {
        printf("\n\n****MENU****\n1.Union\n2.Intersection\n3.Set difference\n4.Equality of set\n5.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                setunion();
                break;
            }
            case 2:
            {
                setintersection();
                break;
            }
            case 3:
            {
                setdifference();
                break;
            }
            case 4:
            {
                setequality();
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid choice ...");
            }
        }
    }while(c!=6);
}
void setunion()
{
    if(n1!=n2)
    {
        printf("Two sets are not compatible to union");
    }
    else
    {
        for(i=0;i<n1;i++)
        {
             s[i]=s1[i] || s2[i];
        }
        printf("first set : ");
        for(i=0;i<n1;i++)
        {
            printf("%d\t",s1[i]);
        }
        printf("\nsecond set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s2[i]);
        }
        printf("\nResultant set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s[i]);
        }
    }

}
void setintersection()
{
    if(n1!=n2)
    {
        printf("Two sets are not compatible to intersection");
    }
    else
    {
        for(i=0;i<n1;i++)
        {
             s[i]=s1[i] && s2[i];
        }
        printf("first set : ");
        for(i=0;i<n1;i++)
        {
            printf("%d\t",s1[i]);
        }
        printf("\nsecond set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s2[i]);
        }
        printf("\nResultant set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s[i]);
        }
    }

}
void setdifference()
{
    int s3[10];
    if(n1!=n2)
    {
        printf("Two sets are not compatible for difference");
    }
    else
    {
        for(i=0;i<n1;i++)
        {
            s3[i]=!s2[i];
        }
        for(i=0;i<n1;i++)
        {
            s[i]=s1[i] && s3[i];
        }
        printf("\n First set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s1[i]);
        }
        printf("\nsecond set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s2[i]);
        }
        printf("\nResultant set : ");
        for(i=0;i<n2;i++)
        {
            printf("%d\t",s[i]);
        }
    }

}
void setequality()
{
    if(n1!=n2)
    {
        printf("\nTwo sets are not equal.");
    }
    else
    {
        for(i=0;i<n1;i++)
        {
            if(s1[i]!=s2[i])
            {
                printf("\nThe sets are not equal");
                return 0;
            }
        }
        printf("\nThe sets are equal.");
    }
}
