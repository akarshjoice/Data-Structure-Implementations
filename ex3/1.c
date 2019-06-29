#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 long long int a;

  struct node* next;
}*head,ptr,*p,*tmp,*as,*b;

 void main()
{ long long int ch;
 char chch='0';
  head=(struct node*)malloc(sizeof(ptr));
  p=head;
  p->next=head;
 //printf("\n ENTER THE VALUE");


do
  { scanf("%lld",&ch);
   p=p->next;
   p->a=ch;
   p->next=(struct node*)malloc(sizeof(ptr));
   chch=getchar();

  }
while(chch!='\n');
p->next=NULL;
//reverse
tmp=head;
as=head;
 p=as;
 as=as->next;
 p->next=NULL;
while(as!=NULL)
{ tmp=as;
  as=as->next;
  tmp->next=p;
  p=tmp;
}
head=tmp;
b=head;
b=head;
 while(b!=NULL)
  {
     printf("%lld ",b->a);
     b=b->next;
  }

}