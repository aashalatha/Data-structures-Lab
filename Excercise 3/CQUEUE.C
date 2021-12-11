#include<stdio.h>
#include<stdlib.h>
void enqueue(int);					//function declaration
int dequeue();
void display();

struct node
	{
	int data;
	struct node *next;
	};
struct node *front=NULL,*rear=NULL,*temp;

void enqueue(int x)					//function to insert the element to the circular queue
{
 struct node *new=(struct node *)malloc(sizeof(struct node));
 new->data=x;
 new->next=NULL;
 if((front==NULL)&&(rear==NULL))
 {
  front=rear=new;
  rear->next=front;
 }
 else
 {
  rear->next=new;
  rear=new;
  new->next=front;
 }
}

int dequeue()						//function to delete the element to the circular queue
{
 int item;
 temp=front;
 if(front==NULL && rear==NULL)
 {
  printf("\nUnderflow!!!");
  return 0;
 }
 else if(front==rear)
 {
  item=front->data;
  front=rear=NULL;
  return item;
 }
 else
 {
  front=front->next;
  rear->next=temp;
  item=temp->data;
  free(temp);
  return item;
 }
}

void display()						//function to print the elements of the circular queue			
{
 temp=front;
 if(front==NULL && rear==NULL)
 {
  printf("\nUnderflow!!!");
 }
 else
 {
  printf("\nThe queue elements are:");
  do
  {
   printf("%d ",temp->data);
   temp=temp->next;
  }while(temp!=front);
 }
}


void main()
{
int i,x,pos,ch;

while(1)
{
printf("\n\nCIRCULAR QUEUE OPERATIONS");
printf("\n1. Insert into the circular queue");
printf("\n2. Delete from the circular queue");
printf("\n3. Display the circular queue");
printf("\nEnter your choice:");
scanf("%d",&ch);

switch(ch)
{
case 1:
	{
	 printf("\n1. Insert into the circular queue");
	 printf("\nEnter the element to be inserted:");
	 scanf("%d",&x);
	 enqueue(x);
	 break;
	}
case 2:
	{
	 printf("\n2. Delete from the circular queue");
	 x=dequeue();
	 if(x!=0)
	  printf("Deleted element:%d",x);
	 break;
	}
case 3:
	{
	 printf("\n3. Display the circular queue");
	 display();
	 break;
	}
default:
	{
	 exit(1);
	}
}
}
}
