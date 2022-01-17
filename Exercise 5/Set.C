//Universal set is{1,2,3,4,5,6,7,8,9}

#include<stdio.h>
#include<stdlib.h>
void input();
void output(int set[]);
void setunion();
void setintersection();
void setdifference();
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0},c[10];

void input()					//insert into the sets
{
int x,i,n;
printf("\nEnter the size of the set 1:");
scanf("%d",&n);
printf("\nEnter the elements of the set 1:");
for(i=0;i<n;i++)
{
 scanf("%d",&x);
 a[x-1]=1;
}

printf("\nEnter the size of the set 2:");
scanf("%d",&n);
printf("\nEnter the elements of the set 2:");
for(i=0;i<n;i++)
{
 scanf("%d",&x);
 b[x-1]=1;
}

}

void output(int set[])			//display set elements
{
int i;
for(i=0;i<9;i++)
{
 if(set[i]==1)
 {
  printf("%d ",i+1);
 }
}
}

void setunion()					//union of sets
{
int i;
for(i=0;i<9;i++)
{
 if(a[i]!=b[i])
 {
  c[i]=1;
 }
 else
 {
  c[i]=a[i];
 }
}
output(c);
}

void setintersection()		//intersection of sets
{
int i,c[10];
for(i=0;i<9;i++)
{
 if(a[i]==b[i])
 {
  c[i]=a[i];
 }
 else
 {
  c[i]=0;
 }
}
output(c);
}

void setdifference()					//difference of sets
{
int i;
printf("\nSet Difference(A-B):");
for(i=0;i<9;i++)
{
 if(a[i]==1&&b[i]==0)
 {
  c[i]=1;
 }
 else
 {
  c[i]=0;
 }
}
output(c);
printf("\nSet Difference(A-B):");
for(i=0;i<9;i++)
{
 if(a[i]==0&&b[i]==1)
 {
  c[i]=1;
 }
 else
 {
  c[i]=0;
 }
}
output(c);
}

void main()
{
int ch;

input();

printf("\nThe set elements are:");
printf("\nSet 1:");
output(a);

printf("\nSet 2:");
output(b);

while(1)
{
printf("\n\nSET OPERATIONS");
printf("\n1. Set Union");
printf("\n2. Set Intersection");
printf("\n3. Set Difference");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	{
	 printf("\n1. Set Union: ");
	 setunion();
	 break;
	}
case 2:
	{
	 printf("\n2. Set Intersection: ");
	 setintersection();
	 break;
	}
case 3:
	{
	 printf("\n3. Set Difference: ");
	 setdifference();
	 break;
	}
default:
	{
	 exit(0);
	}
}
}
}
