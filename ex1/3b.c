#include<stdlib.h>
#include<stdio.h>
void main()
{ int n,**b,l;
 //printf("ENTER n*n:");
 scanf("%d",&n);
 //printf("\n Enter the matrix:");
b=malloc(sizeof(int *)*n);
for(int h=0;h<n;h++)
 {   b[h]=malloc(sizeof(int)*n);
 }
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<n;j++)
    {
      scanf("%d",&b[i][j]);
     }
 }
   transpose(b,0,0,n);
 l=(n%2==0)?n/2:((n/2)+1);
 for(int k=0;k<l;k++)
  {
    for(int i=k;i<n-k;i++)
             printf("%d ",b[k][i]);
     for(int j=k+1;j<n-k;j++)
             printf("%d ",b[j][n-k-1]);
      for(int l=n-2-k;l>=k;l--)
             printf("%d ",b[n-1-k][l]);
      for(int r=n-k-2;r>k;r--)
             printf("%d ",b[r][k]);
  }



 }
int transpose(int **a,int i,int j,int p)
{  int tmp;
       if(i< p)
           {
               if(j< p)
                       {

                               tmp=a[i][j];
                                a[i][j]=a[j][i];
                               a[j][i]=tmp;
                               transpose(a,i,j+1,p);
                       }
               else

                               transpose(a,i+1,i+1,p);
            }
        else
                 return 0;
}
