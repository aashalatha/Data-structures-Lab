#include<stdio.h>
#include<conio.h>
void push(int);
int pop();
void status();

struct node
	{
	int data;
	struct node *next;
	};
struct node *head,*new,*temp,*prev;

void push(int x)
{
 new = (struct node*)malloc(sizeof(struct node));
 if(head==NULL)
 {
  new->data=x;
  new->next=NULL;
  head=new;
 }
 else
 {
  new->data=x;
  new->next=head;
  head=new;
 }
 printf("\nInserted!!!");
}

int pop()
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
  printf("\nItem popped");
  return item;
 }
}

void status()
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
clrscr();
head=(struct node *)malloc(sizeof(struct node));
temp=head;

while(1)
{
printf("\n\nSTACK OPERATIONS");
printf("\n1. Push into the stack");
printf("\n2. Pop from the stack");
printf("\n3. Status of the stack");
printf("\nEnter your choice:");
scanf("%d",&ch);

switch(ch)
{
case 1:
	{
	 printf("\n1.Push into the stack");
	 printf("\nEnter the element to be inserted:");
	 scanf("%d",&x);
	 push(x);
	 break;
	}
case 2:
	{
	 printf("\n2.Pop into the stack");
	 printf("%d",pop());
	 break;
	}
case 3:
	{
	 printf("\n3.Status of the stack");
	 status();
	 break;
	}
default:
	{
	 exit(1);
	}
}
}
}