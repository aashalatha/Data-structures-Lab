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
struct node *head,*new,*temp,*prev;

void enqueue(int x)					//function to insert the element to the queue
{
 new = (struct node*)malloc(sizeof(struct node));
 new->data=x;
 if(head==NULL)
 {
  new->next=NULL;
  head=new;
 }
 else
 {
  temp=head;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  new->data=x;
  new->next=NULL;
  temp->next=new;
 }
 printf("\nInserted!!!");
}

int dequeue()						//function to delete the element to the queue
{	
 int item;
 if(head==NULL)
 {
  printf("\nUnderflow!!!");
  return 0;
 }
 else
 {
  item=head->data;
  prev=head;
  head=head->next;
  free(prev);
  printf("\nItem deleted");
  return item;
 }
}

void display()						//function to print the elements of the queue			
{
 temp=head;
 if(temp==NULL)
 {
  printf("\nUnderflow!!!");
 }
 else
 {
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
	 printf("%d",dequeue());
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
