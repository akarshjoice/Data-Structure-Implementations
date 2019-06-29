#include<stdio.h>
#include<stdlib.h>
void search(int **b,int r,int c,int k)
{
int i=0,j=c-1,flag=0;
while (((i<r)&&(j>=0)))
{
if(b[i][j]>k)
j--;
else if(b[i][j]<k)
i++;
else
{
flag=1;
break;
}}
if(flag==1)
printf("1");
else
printf("-1");
}
int main()
{
int **a,i,j,k,m,n;
scanf("%d%d",&m,&n);
a=malloc(m*sizeof(int*));
for(i=0;i<n;i++)
      a[i]=malloc(n*sizeof(int));

for(i=0;i<m;i++)
 { for(j=0;j<n;j++)
         scanf("%d",&a[i][j]);
 }
scanf("%d",&k);
search(a,m,n,k);
}