#include<stdio.h>
#include<stdlib.h>
void main()
{ int i,n,*a,k;

 scanf("%d",&n);
 a=(int *)malloc(sizeof(int)*n);
 for(i=0;i<n;i++)
             scanf("%d",&a[i]);
 scanf("%d",&k);
 heap(a,n,k);
}
void heap(int a[],int n,int k)
{ int i,tmp,h=0;
  for(i=(n/2)-1;i>=0;i--)
         maxheap(a,n,i);
  for(i=n-1;i>=0;i--)
    { h++;
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
 if(h==k)
     {  printf("%d",a[i]);
         break;
      }
 else
   maxheap(a,i,0);
 }
}
int maxheap(int a[],int n,int i)
{ int large,l,r,tmp;
  large=i;
  l=2*i+1;
  r=2*i+2;
if(l<n && a[l]>a[large])
       large=l;
if(r<n && a[r]>a[large])
       large=r;
if(large != i)
   {
       tmp=a[i];
       a[i]=a[large];
       a[large]=tmp;
    maxheap(a,n,large);
   }
}