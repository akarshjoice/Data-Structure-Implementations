#include<stdio.h>
#include<stdlib.h>
void mergesort(int *a,int p,int q);
int merge(int *a,int p,int q,int r);
void main()
{
int i=0,*a,c;
int n;
FILE *out,*in;
in=fopen("in","rb");
out=fopen("out","wb");
a=(int *)malloc(sizeof(int));
if(in==NULL)
  return;
fread(&c,sizeof(int),1,in);

 while(!feof(in))
{
  a=(int *)realloc(a,sizeof(int)*i);
 a[i]=c;
 i++;
 fread(&c,sizeof(int),1,in);

}
n=i;
mergesort(a,0,n-1);
for(i=0;i<n;i++)
  fwrite(&a[i],sizeof(int),1,out);
for(i=0;i<n;i++)
 printf("%d ",a[i]);
fclose(in);
fclose(out);

}
void mergesort(int a[],int l,int u)
{
int r;
if((l<u))
{
r=(u-l)/3;
mergesort(a,l,l+r);
mergesort(a,l+r+1,l+2*r);
mergesort(a,l+2*r+1,u);
merge(a,l,u,r);
}

}
int merge(int a[],int lo,int u,int ro)
{
int s[10],l[10],r[10],i,j,k,n1,n2,n3,min=0,t;
for(i=0,j=lo;j<=lo+ro;i++,j++)
s[i]=a[j];
for(i=0,j=lo+ro+1;j<=lo+2*ro;j++,i++)
l[i]=a[j];
for(i=0,j=lo+2*ro+1;j<=u;i++,j++)
r[i]=a[j];
n1=ro+1;
n2=ro;
n3=u-lo-2*ro;
i=j=k=0;
t=lo;
while(i<n1&&j<n2&&k<n3)
{
min=s[i];
if(l[j]<min)
min=l[j];
if(r[k]<min)
min=r[k];
if(min==s[i])
a[t++]=s[i++];
if(min==l[j])
a[t++]=l[j++];
if(min==r[k])
a[t++]=r[k++];
}
while(i<n1&&j<n2)
{
if(s[i]<l[j])
a[t++]=s[i++];
else
a[t++]=l[j++];
}
while(i<n1&&k<n3)
{
if(s[i]<r[k])
a[t++]=s[i++];
else
a[t++]=r[k++];
}
while(k<n3&&j<n2)
{
if(r[k]<l[j])
a[t++]=r[k++];
else
a[t++]=l[j++];
}
while(i<n1)
a[t++]=s[i++];
while(j<n2)
a[t++]=l[j++];
while(k<n3)
a[t++]=r[k++];
}