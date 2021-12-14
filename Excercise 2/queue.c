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

void enqueue(int x)					//function to insert the element to the queue
{
 struct node *new=(struct node *)malloc(sizeof(struct node));
 new->data=x;
 new->next=NULL;
 if((front==NULL)&&(rear==NULL))
 {
  front=rear=new;
 }
 else
 {
  rear->next=new;
  rear=new;
 }
 printf("\nInserted!!!");
}

int dequeue()						//function to delete the element to the queue
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
  item=temp->data;
  free(temp);
  return item;
 }
}

void display()						//function to print the elements of the queue
{
 temp=front;
 if(front==NULL && rear==NULL)
 {
  printf("\nUnderflow!!!");
 }
 else
 {
  printf("\nThe queue elements are:");
  while(temp!=NULL)
  {
   printf("%d ",temp->data);
   temp=temp->next;
  }
 }
}


void main()
{
int i,x,pos,ch;

while(1)
{
printf("\n\nQUEUE OPERATIONS");
printf("\n1. Insert into the queue");
printf("\n2. Delete from the queue");
printf("\n3. Display the queue");
printf("\nEnter your choice:");
scanf("%d",&ch);

switch(ch)
{
case 1:
	{
	 printf("\n1. Insert into the queue");
	 printf("\nEnter the element to be inserted:");
	 scanf("%d",&x);
	 enqueue(x);
	 break;
	}
case 2:
	{
	 printf("\n2. Delete from the queue");
	 x=dequeue();
	 if(x!=0)
	  printf("\nDeleted element:%d",x);
	 break;
	}
case 3:
	{
	 printf("\n3. Display the queue");
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
