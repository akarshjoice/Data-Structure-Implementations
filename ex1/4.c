#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct ratio
{ int x,y;
}l,m,*c,tmp;
void main()
{
 char ch,s;
 int n;
 //struct ratio l,m,c[50],tmp;
 //printf("\n1.Print a/b form");
 //printf("\n2.Sum of Rational numbers");
 //printf("\n3.Product of Rational numbers");
 //printf("\n4.Sort in ascending order");
 //printf("\n5.Print in Simplest form");
 //printf("\nChoose your option:");
 scanf("%c",&ch);
if(ch=='1')
    ch='5';
 switch(ch)
 {
  case '1':
          //struct ratio l;
           //printf("\nEnter a and b:");
           scanf("%d %d",&l.x,&l.y);
           printf("\n%d/%d",l.x,l.y);
           break;
 case '2':
           //struct ratio l,m;
          // printf("\nEnter a and b:");
           scanf("%d %d",&l.x,&l.y);
           //printf("\nEnter a and b:");
           scanf("%d %d",&m.x,&m.y);
           if(l.x<0 && l.y<0 || l.y<0)
                {  l.x=-1*l.x;
                   l.y=-1*l.y;
                 }
             if(m.x<0 && m.y<0 || m.y<0)
                {  m.x=-1*m.x;
                   m.y=-1*m.y;
                 }
           s=simplify((abs(l.x*m.y+l.y*m.x)),(abs(l.y*m.y)));
           printf("\n%d/%d",((l.x*m.y)+(l.y*m.x))/s,(l.y*m.y)/s);
           break;
  case '3':
           //struct ratio l,m;
           //printf("\nEnter a and b:");
           scanf("%d %d",&l.x,&l.y);
           //printf("\nEnter a and b:");
           scanf("%d %d",&m.x,&m.y);
            if(l.x<0 && l.y<0 || l.y<0)
                {  l.x=-1*l.x;
                   l.y=-1*l.y;
                 }
             if(m.x<0 && m.y<0 || m.y<0)
                {  m.x=-1*m.x;
                   m.y=-1*m.y;
                 }
           s=simplify((abs(l.x*m.x)),abs(l.y*m.y));
           printf("\n%d/%d",(l.x*m.x)/s,(l.y*m.y)/s);
           break;
 case '4':
         // struct ratio c[50],tmp;

         // printf("\nNumber of Rational numbers to be sorted:");
          scanf("%d",&n);
         // printf("\nEnter in the form  a b:");
          c=(struct ratio*)malloc(n*sizeof(m));
             if(c==NULL)
                exit(0);
           scanf("%d %d",&c[0].x,&c[0].y);
                if(c[0].x<0 && c[0].y<0 || c[0].y<0)
                  {      c[0].x=-1*c[0].x;
                         c[0].y=-1*c[0].y;
                  }
          for(int i=1;i<n;i++)
           { //printf("\n Enter in the form a b:");
             scanf("%d %d",&c[i].x,&c[i].y);
                if(c[i].x<0 && c[i].y<0 || c[i].y<0)
                  {      c[i].x=-1*c[i].x;
                         c[i].y=-1*c[i].y;
                  }
                  for(int j=0;j<i;j++)
                     {
                      if((c[j].x*c[i].y)>(c[i].x*c[j].y))
                              {  tmp=c[i];
                                 c[i]=c[j];
                                 c[j]=tmp;
                               }
                      }
          }
          for(int j=0;j<n;j++)
             {
                     printf("%d/%d  ",c[j].x,c[j].y);
             }
         break;
  case '5':
           //struct ratio l;
          // printf("\nEnter a and b:");
           scanf("%d %d",&l.x,&l.y);
            if(l.x<0 && l.y<0 || l.y<0)
                {  l.x=-1*l.x;
                   l.y=-1*l.y;
                 }
           s=simplify(abs(l.x),abs(l.y));

           printf("\n%d/%d",l.x/s,l.y/s);
           break;

   default:
           printf("\nWRONG CHOICE");
 }
}
int simplify(int a,int b)
 {
       int s=1,l;
        l=a<b?a:b;
       for(int i=1;i<=l;i++)
            {
                   if(a%i==0 && b%i==0)
                             s=i;
            }
     return s;
 }
