#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,i,t,k,w=-1,*a;
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
     scanf("%d",&a[i]);
scanf("%d",&k);
int l=0;
t=change(a,n);
  w=binary(a,l,t,k);
   if(w != -1)
         printf("%d",w-1);
   else
        {  w=-1;
           w=binary(a,t+1,n-1,k);
        if(w != -1)
               printf("%d",w-1);
        else
              printf("-1");
        }
}
int binary(int a[],int l,int u,int k)
{ int m=0,flag=0,p;
while(l<=u)
{
     m=(l+u)/2;
     if(k>a[m])
              l=m+1;
     else if(k<a[m])
              u=m-1;
     else
          {   flag=1;
              break;
           }
}
if(flag==1)
{
  return (m+1);

}
return -1;
}
int change(int a[],int n)
{
 int l=0;
 int u=n-1,mid;
 while(l<=u)
  {
   mid=(l+u)/2;
 if(a[mid]>a[mid+1])
           return mid;
 else if(a[mid]<a[mid-1])
           return (mid-1);
 else if(a[l]>=a[mid])
           u=mid-1;
 else
           l=mid+1;
   }
  if(l>u)
      return 0;
 }