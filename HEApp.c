#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int heap[100], heapSize=0;
void Insert(int);
int DeleteMin();
void display();
void main()
{
    int choice,number_of_elements,i,element;
    while(1)
    {
        printf("\n MENU \n");
        printf("\n 1.Insert\n 2.DeleteMin\n 3.display\n 4.exit");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
    printf("\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    for (i = 0; i < number_of_elements;i++) {
        printf("Enter the elements: ");
        scanf("%d", &element);
        Insert(element);
    }
    break;
    case 2:
    DeleteMin();
    break;
    case 3:
     display();
     break;
    default:
        printf("\n wrong selection!! try again\n");


}
    }

}
void Insert(int element) {
    heapSize++;
    heap[heapSize] = element;
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now=now/ 2;
    }
    heap[now] = element;
}

int DeleteMin() {
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];

    for (now = 1; now * 2 <= heapSize; now = child) {


        child = now * 2;


        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
        }

        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        }
        heap[now] = lastElement;
}
}
void display()
 {
     int i;
     if(heapSize==NULL)
     {
         printf("Tree is empty");


     }
     for(i=1;i<=heapSize;i++)
     {
         printf("%d",heap[i]);
     }

}














