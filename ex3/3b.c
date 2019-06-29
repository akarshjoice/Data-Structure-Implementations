#include<stdio.h>
#include<stdlib.h>
struct node
{
 long long int a;
 struct node* next;
}*head,*tail,*ptr,p;

long long int enqueue(long long int element)
{

 if(tail==NULL)
        {
           tail=(struct node*)(malloc(sizeof(p)));

           head=tail;
           tail->a=element;
           tail->next=NULL;
        }
 else
        {
          ptr=tail;
          tail=(struct node*)(malloc(sizeof(p)));
          tail->a=element;
          tail->next=NULL;
          ptr->next=tail;

       }
                     return 0;

}
long long int dequeue()
{ long long int value;
 if(head==NULL)
        return -1;
 else
      {
      if(head==tail)
              {
                    value=head->a;
                    head=tail=NULL;
                     return value;
              }
 else
              {
                    value=head->a;
                    head=head->next;
                    return value;
              }
      }
}
long long int print_queue()
{
 if(head==NULL)
       return -1;
 else
     {
        ptr=head;
    while(ptr!=NULL)
        {
          printf("%lld ",ptr->a);
          ptr=ptr->next;
        }
     }
}

void main()
{ char ch;
  long long int ele,p;


do
  {
  scanf("%c",&ch);
    switch(ch)
          {
                 case 'e':
                         scanf("%lld",&ele);
                         p=enqueue(ele);
                         if(p==-2)
                               printf("%lld\n",p);
                         break;
                 case 'd':
                        p=dequeue();
                        printf("%lld\n",p);
                       break;
                 case 'p':
                        p=print_queue();
                        if(p==-1)
                              printf("%lld\n",p);
                         else
                              printf("\n");
                        break;
           }
   }
while(ch!='s');
exit(0);
}