#include<stdio.h>
#include<conio.h>
#define size 10
int stack[size],top=-1;

void push(int);
int pop();
void status();

void push(int x)
{
 if(top==size-1)
 {
  printf("\nStack overflow!!!");
 }
 else
 {
 top++;
 stack[top]=x;
 }
}

int pop()
{
 int p;
 if(top==-1)
 {
  printf("\nStack underflow!!!");
  return -1;
 }
 else
 {
  p=stack[top];
  top--;
  return p;
 }
}

void status()
{
 int i;
 if(top==-1)
 {
  printf("\nStack Underflow!!!");
 }
 else
 {
  printf("\nThe elements of the stack are: ");
  for(i=top;i>=0;i--)
  {
   printf("%d ",stack[i]);
  }
 }
}

void main()
{
int ch,x;
char choice;
clrscr();

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
	 printf("\nEnter the element to push:");
	 scanf("%d",&x);
	 push(x);
	 printf("\nInserted Successfully!!");
	 break;
	}
case 2:
	{
	 printf("\n2.Pop into the stack");
	 x=pop();
	 if(x!=-1)
	 {
	  printf("\nPopped successfully!!!");
	 }
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
getch();
}