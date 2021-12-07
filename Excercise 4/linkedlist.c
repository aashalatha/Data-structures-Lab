#include<stdio.h>
#include<stdlib.h>
void getlist(int);            					  //function declaration
void printlist();
void insbegin();
void insend();
void inspos();
void delbegin();
void delend();
void delany();

struct node                  				          //global declaration
	{
	int data;
	struct node *next;
	};
struct node *head,*new,*temp,*prev;
int size=0,x;

void getlist(int m)            					 //function to get linked list
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

void printlist()           					//function to print linked list
{
 int size=0;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d ",temp->data);
  temp=temp->next;
 }
}

void insbegin()							//function to insert to the beginning of a linked list
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
}

void insend()							//function to insert to the end of a linked list
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
}

void inspos()							//function to insert at any position in a linked list
{
int pos,i;
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
}

void delbegin()							//function to delete from the beginning of a linked list
{
printf("\n4.Delete at beginning");
prev=head;
head=head->next;
free(prev);
size--;
printf("\nThe new linked list after deletion:");
printlist();
}

void delend()							//function to delete from the end of a linked list
{
printf("\n5.Delete at end");
temp=head;
while(temp->next->next!=NULL)
{
 temp=temp->next;
}
prev=temp->next;
temp->next=NULL;
free(prev);
size--;
printf("\nThe new linked list after deletion:");
printlist();
}

void delany()							//function to delete any node in a linked list
{
printf("\n6.Delete any node");
printf("\nEnter the element to be deleted:");
scanf("%d",&x);
temp=head;
while(temp->next->data!=x)
{
 temp=temp->next;
}
prev=temp->next;
temp->next=temp->next->next;
free(prev);
size--;
printf("The new linked list is:");
printlist();
}

void main()
{
int ch;
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
printf("\n4. Delete at beginning");
printf("\n5. Delete at end");
printf("\n6. Delete any node");
printf("\nEnter your choice:");
scanf("%d",&ch);
 switch(ch)
 {
 case 1:
	{
	 insbegin();
	 break;
	}
 case 2:
	{
	insend();
	break;
	}
 case 3:
	{
	inspos();
	break;
	}
 case 4:
	{
	 delbegin();
	 break;
	}
 case 5:
	{
	 delend();
	 break;
	}
 case 6:
	{
	 delany();
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
}
