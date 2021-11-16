     #include<stdio.h>
#include<stdlib.h>
void main()
{
struct node
{
 int data;
 struct node *next;
};
struct node *head,*temp,*prev;
int x;
head = (struct node*)malloc(sizeof(struct node));
temp = head;
printf("Enter the elements(enter -999 to stop):");

while(temp!=NULL)
{
 scanf("%d",&x);
 if(x!=-999)
 {
  temp->data = x;
  temp->next = (struct node*)malloc(sizeof(struct node));
  prev=temp;
  temp=temp->next;
 }
 else
 {
  prev->next= NULL;
  temp=NULL;
 }
}
printf("The linked list is:");
temp=head;
while(temp!=NULL)
{
 printf("%d ", temp->data);
 temp= temp->next;
}
}
