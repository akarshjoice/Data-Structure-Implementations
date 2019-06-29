#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 int a;

  struct node* next;
}*head1,*head2,ptr,*p,*tmp,*as,*b,*h1,*h2;
int bo;

 void main()
{
 char chch;
  head1=(struct node*)malloc(sizeof(ptr));
  p=head1;
  p->next=head1;
// printf("\n ENTER THE VALUE");
do
  { scanf("%c",&chch);
  switch(chch)
  {
   case '0':
         p=p->next;
         p->a=0;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '1':
         p=p->next;
         p->a=1;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '2':
         p=p->next;
         p->a=2;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '3':
         p=p->next;
         p->a=3;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '4':
         p=p->next;
         p->a=4;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
 case '5':
         p=p->next;
         p->a=5;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
 case '6':
         p=p->next;
         p->a=6;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '7':
         p=p->next;
         p->a=7;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '8':
         p=p->next;
         p->a=8;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '9':
         p=p->next;
         p->a=9;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  }
}
while(chch!='\n');
p->next=NULL;
chch='0';
head2=(struct node*)malloc(sizeof(ptr));
  p=head2;
  p->next=head2;
// printf("\n ENTER THE VALUE");


do
  { scanf("%c",&chch);
    switch(chch)
  {
   case '0':
         p=p->next;
         p->a=0;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '1':
         p=p->next;
         p->a=1;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '2':
         p=p->next;
         p->a=2;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '3':
         p=p->next;
         p->a=3;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '4':
         p=p->next;
         p->a=4;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
 case '5':
         p=p->next;
         p->a=5;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
 case '6':
         p=p->next;
         p->a=6;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '7':
         p=p->next;
         p->a=7;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '8':
         p=p->next;
p->a=8;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  case '9':
         p=p->next;
         p->a=9;
         p->next=(struct node*)malloc(sizeof(ptr));
         break;
  }



}
while(chch!='\n');
p->next=NULL;
h1=head1;
h2=head2;
while(h1!=NULL)
{
if(h1->a>h2->a)
  { subtract(head1,head2);
    print_ans(head1);
   break;
  }
else if(h1->a<h2->a)
  { subtract(head2,head1);
    print_ans(head2);
    break;
  }
else
  { h1=h1->next;
    h2=h2->next;
  }
}
if(h1==NULL)
printf("0");
}

void print_ans(struct node* b)
{
int flag=0;
 while(b!=NULL)
  {
        if(b->a!=0)
        flag=1;
        else
        flag=0;
        if(flag==1)
        {
        while(b!=NULL)
        {
        printf("%d",b->a);
        b=b->next;
        }
        break;
        }
     b=b->next;
  }
}
int subtract(struct node* head1,struct node* head2)
{
  if(head1==NULL)

       return 0;
  else
    bo=subtract(head1->next,head2->next);
    if(bo==1)
           head1->a=head1->a-1;
    if(head2->a>head1->a)
         {
           bo=1;
           head1->a=head1->a+10;
         }
    else
            bo=0;
     head1->a=head1->a-head2->a;
     return bo;
}