#include<stdio.h>
#include<conio.h>
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
   size++;
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
 int size=0;
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
clrscr();
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
printf("\n4. Delete at beginning");
printf("\n5. Delete at end");
printf("\n6. Delete any node");
printf("\nEnter your choice:");
scanf("%d",&ch);
 switch(ch)
 {
 case 1:
	{
	 printf("\n1.Insert at beginning");
	 new = (struct node*)malloc(sizeof(struct node));
	 printf("\nEnter the element to be inserted:");
	 scanf("%d",&x);
	 new->data=x;
	 new->next=head;
	 head=new;
	 size++;
	 printf("The new linked list is:");
	 printlist();
	 break;
	}
 case 2:
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
	size++;
	printf("The new linked list is:");
	printlist();
	break;
	}
 case 3:
	{
	printf("\n3.Insertion at any position");
	new = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the new element to be inserted:");
	scanf("%d",&x);
	printf("\nEnter the position to be inserted:");
	scanf("%d",&pos);
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
	size++;
	printf("\nThe new linked list is:");
	printlist();
	break;
	}
 case 4:
	{
	 printf("\n4.Delete at beginning");
	 head=head->next;
	 size--;
	 printf("\nThe new linked list after deletion:");
	 printlist();
	 break;
	}
 case 5:
	{
	 printf("\n5.Delete at end");
	 temp=head;
	 while(temp->next->next!=NULL)
	 {
	  temp=temp->next;
	 }
	 temp->next=NULL;
	 size--;
	 printf("\nThe new linked list after deletion:");
	 printlist();
	 break;
	}
 case 6:
	{
	 printf("\n6.Delete any node");
	 printf("\nEnter the element to be deleted:");
	 scanf("%d",&x);

	 temp=head;
	 while(temp->next->data!=x)
	 {
	  temp=temp->next;
	 }
	 temp->next=temp->next->next;
	 size--;
	 printf("The new linked list is:");
	 printlist();
	 break;
	}
 default:
	{
	 printf("\nInvalid Choice!!!");
	 break;
	}
 }
printf("\nDo you want to continue?(Press y/n):");
scanf(" %c",&choice);
}while(choice=='y'|| choice=='Y');
getch();
 }