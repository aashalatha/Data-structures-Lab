#include<stdio.h>
#include<stdlib.h>
void getlist(int);              //function declaration
void printlist();

struct node                     //global declaration
	{
	int data;
	struct node *next;
	};
struct node *head,*new,*temp,*prev;
int size=0;

void getlist(int m)             //function to get linked list
{
 while(temp!=NULL)
 {
  scanf("%d",&m);
  if(m!=-999)
  {
   temp->data=m;
   temp->next=(struct node *)malloc(sizeof(struct node));
   prev=temp;
   temp=temp->next;
  }
  else
  {
   prev->next=NULL;
   temp=NULL;
  }
 }
}

void printlist()           	//function to print linked list
{
 temp=head;
 while(temp!=NULL)
 {
  printf("%d ",temp->data);
  temp=temp->next;
 }
}

void main()
{
int i,pos,x,ch;
char choice;

head=(struct node *)malloc(sizeof(struct node));
temp=head;
printf("Enter the elements(enter -999 to stop):");
getlist(x);
printf("The elements are=");
printlist();

do
{
printf("\nLINKED LIST OPERATIONS");
printf("\n1. Insert at beginning");
printf("\n2. Insert at end");
printf("\n3. Insert at any position");
printf("\n4. Delete a node");
printf("\nEnter your choice:");
scanf("%d",&ch);
 switch(ch)
 {
 case 1:							#insertion at beginning
	{
	 printf("\n1.Insert at beginning");
	 new = (struct node*)malloc(sizeof(struct node));
	 printf("\nEnter the element to be inserted:");
	 scanf("%d",&x);
	 new->data=x;
	 new->next=head;
	 head=new;
	 printf("The new linked list is:");
	 printlist();
	 break;
	}
 case 2:							#insertion at end
	{
	printf("\n2.Insertion at end");
	new = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted:");
	scanf("%d",&x);

	temp=head;
	while(temp->next!=NULL)
	{
	 temp=temp->next;
	}

	new->data=x;
	new->next=NULL;
	temp->next=new;
	printf("The new linked list is:");
	printlist();
	break;
	}
 case 3:							#insertion at any position
	{
	printf("\n3.Insertion at any position");
	new = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the new element to be inserted:");
	scanf("%d",&x);
	printf("\nEnter the position to be inserted:");
	scanf("%d",&pos);
	size++;
	temp=head;
	if(pos<1||pos>size+1)
	{
	 printf("Invalid Positiion!");
	}
	else
	{
	 for(i=2;i<pos;i++)
	 {
	  if(temp->next!=NULL)
	  {
	   temp=temp->next;
	  }
	 }
	 new->data=x;
	 new->next=temp->next;
	 temp->next=new;
	}
	printf("The new linked list is:");
	printlist();
	break;
	}
 case 4:							#deletion of any node
	{
	 printf("\n4.Delete a node");
	 new = (struct node*)malloc(sizeof(struct node));
	 printf("\nEnter the element to be deleted:");
	 scanf("%d",&x);

	 temp=head;
	 while(temp->next->data!=x)
	 {
	  temp=temp->next;
	 }
	 temp->next=temp->next->next;
	 printf("The new linked list is:");
	 printlist();
	 break;
	}
 case 5:							#exits the program
	{
	 exit(0);
	}
 default:
	{
	 printf("\nInvalid Choice!!!");
	 break;
	}
 }
printf("\nDo you want to continue?(Press y/n):");
scanf(" %c",&choice);
}while(choice=='y');
}
