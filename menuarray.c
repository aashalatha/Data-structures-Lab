#include<stdio.h>
#include<stdlib.h>
int arr[10],n;
void printarray(int arr[]);

void printarray(int arr[])
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%d ",*arr+i);
 }
}

void main()
{

int i,ch,item,pos,flag=0;
char y;

printf("Enter the array limit:");
scanf("%d",&n);
printf("Enter the array elements:");
for(i=0;i<n;i++)
{
scanf("%d",arr+i);
}

while(1)
{
printf("\n\nARRAY OPERATIONS\n");
printf("1. Insert into an array\n");
printf("2. Delete from an array\n");
printf("3. Search an element from an array\n");
printf("4. Exit\n");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
 case 1:
	{
	 printf("\n1. Insert into an array\n");
	 printf("\nEnter the new array element and the position to be inserted:");
	 scanf("%d%d",&item,&pos);

	 for(i=n;i>=pos;i--)
	 {
	 arr[i]=arr[i-1];
	 }
	 arr[pos]=item;
	 printf("\nThe new array is:");
	 printarray(arr);
	 break;
	}

 case 2:
	{
	 printf("\n2. Delete from an array\n");
	 printf("Enter the postion to be deleted:");
	 scanf("%d",&pos);
	 for(i=0;i<n;i++)
	 {
 	  if(i>=pos)
	  {
	   arr[i]=arr[i+1];
	  }
	 }
	 n--;
	 printf("\nThe new array is:");
	 printarray(arr);
	 break;
	}
	
case 3:
	{
	 printf("\n3. Search an element from an array\n");
	 printf("Enter the element to be searched:");
	 scanf("%d",&item);
	 for(i=0;i<n;i++)
	 {
 	  if(arr[i]==item)
	  {
	   flag=1;
	   break;
	  }
	 }
	if(flag==1)
	{
	 printf("\n%d is present",item);
	}
	else
	{
	 printf("\n%d is not present",item);
	}
	break;
	}
case 4:
	{
	 exit(0);
	}
default:
	{
	 printf("Invalid Choice!!!");
	 break;
	}

}
}

return 0;
}
