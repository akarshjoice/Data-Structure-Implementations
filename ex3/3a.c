#include<stdio.h>
#include<stdlib.h>
long long int a[1000];
long long int head,tail,c,size=0;
long long int enqueue(long long int element)
{
          if(size!=c)
            {        tail=(tail+1)%c;
                    a[tail]=element;
                     size=size+1;
                     return 0;
            }
         else
            {
                    return (-2);
            }
}
long long int dequeue()
{  long long int value;
        if(size==0)
           {
                return -1;
           }
        else
           {
                value=a[head];
                head=(head+1)%c;
                size=size-1;
                return value;
           }
}
long long int print_queue()
{  long long int i,j;
  if(size!=0)
   {
    if(head<=tail)
    {   for(i=head;i<=tail;i++)
               printf("%lld ",a[i]);

     }
   else
       { for(i=head;i<c;i++)
              printf("%lld ",a[i]);
         for(j=0;j<=tail;j++)
                 printf("%lld ",a[j]);
       }
        return 0;
   }
  else
        return -1;

}

void main()
{ char ch;
  long long int t,h;
  head=0;
  scanf("%lld",&c);
  tail=c-1;
do
 {
  scanf("%c",&ch);
   switch(ch)
       {
      case 'e':
         scanf("%lld",&t);
         h=enqueue(t);
         if(h==-2)
               printf("%lld\n",h);
          break;
      case 'd':
         h=dequeue();
         printf("%lld\n",h);
          break;
      case 'p':
//          printf("\n");
          h=print_queue();
           if(h==-1)
               printf("%lld\n",h);
           else
               printf("\n");
          break;
        }
  }
while(ch!='s');
exit(0);
}
