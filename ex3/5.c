#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node
{
 long int a; 
 struct node* next;
}*top,r,*ptr;
long int pow1(long int a,long int b)
{ long int i,p=1;

  for(i=0;i<b;i++)
    { p=p*a;
     
    }
 return p;
}

/*void push(struct node* top,int s)
{
 if(top==NULL)
     { top=(struct node*)(malloc(sizeof(r)));
       top->a=s;
       top->next=NULL;
       printf("%d",s);
     }
 else
     {
       ptr=top;
       top=(struct node*)(malloc(sizeof(r)));
       top->a=s;
       top->next=ptr;
    printf("%d",top->a);
     }
}
*/
/*int pop(struct node* top)
{ int l;
 if(top==NULL)
   {
      return 0;
   }
 else
   {
     l=top->a;
     top=top->next;
   }
  return l;
}*/
void main()
{
long int q=0,t,l,j=0,y=0,p,i,n1,n2,num=0;
char word[10000],*s,chl;
top=NULL;
s=malloc(sizeof(char));
chl=getchar();
while(chl!='\n')
{
  s[q]=chl;
  q++;
  s=realloc(s,sizeof(char)*(q+1));
  chl=getchar();
}
s[q]='\0';
 
for(i=0;s[i]!='\0';i++)
{
             if(s[i]>='0' && s[i]<='9')
                          {  y=1;
                             word[j]=s[i];
                             j++;
                           }  
             else if(s[i]==' ')
                          {
                            num=0;
                            if(y==1)
                                     { 
                                        y=0;
                                        for( p=0;p<j;p++)
                                                {
                                                       switch(word[p])
                                                           { 
                                                            case '0':
                                                                   num=0+num*(pow1(10,p));
                                                                   break;
                                                            case '1':
                                                                   num=1+num*(pow1(10,p));
                                                                   break;
                                                            case '2':
                                                                   num=2+num*(pow1(10,p));
                                                                   break;
                                                            case '3':
                                                                   num=3+num*(pow1(10,p));
                                                                   break;
                                                            case '4':
                                                                   num=4+num*(pow1(10,p));
                                                                   break;
                                                            case '5':
                                                                   num=5+num*(pow1(10,p));
                                                                   break;
                                                            case '6':
                                                                   num=6+num*(pow1(10,p));
                                                                   break;
                                                            case '7':
                                                                   num=7+num*(pow1(10,p));
                                                                   break;
                                                            case '8':
                                                                   num=8+num*(pow1(10,p));
                                                                   break;

                                                            case '9':
                                                                   num=9+num*(pow1(10,p));
                                                                   break;
                                                            }
          
                                               }
                                    j=0;
       
                                   if(top==NULL)
                                          { top=(struct node*)(malloc(sizeof(r)));
                                            top->a=num;
                                            top->next=NULL;
      
                                          }
                                  else
                                          {
                                           ptr=top;
                                           top=(struct node*)(malloc(sizeof(r)));
                                           top->a=num;
                                           top->next=ptr;

                                            }
                                    num=0;

                                    }
 
         }
  else
    {
   n2=top->a;
     top=top->next;
    n1=top->a;
     top=top->next;

        switch(s[i])
           {
                 case '+':
                       n1=n1+n2;


                       break;
                 case '-':
                       n1=n1-n2;

                       break;

                 case '*':
                       n1=n1*n2;

                       break;
                 case '/':
                       n1=n1/n2;

                       break;
                 case '^':
                      n1=pow1(n1,n2);

                      break;
           }

   if(top==NULL)
     { top=(struct node*)(malloc(sizeof(r)));
       top->a=n1;
       top->next=NULL;

     }
   else
     {
       ptr=top;
       top=(struct node*)(malloc(sizeof(r)));
       top->a=n1;
       top->next=ptr;

      }
   }
}

n1=top->a;
top=top->next;
//printf("%d",n1);
int f=0;
char ch;
for(i=0;s[i]!='\0';)
   {
      if(s[i]>='0' &&s[i]<='9'|| s[i]==' ')
          {i++;
           continue;
          }
     else 
           {
               ch=s[i];
                      for(j=i-1;j>=0;j--)
                          {
                            if(s[j]>='0' && s[j]<='9')
                                 f=1;
                            else if (s[j]==' '&&f==1)
                               {  s[j]=ch;
                                 break;
                               }
                         }
                      for(j=i;s[j]!='\0';j++)
                        {
                             s[j]=s[j+1];
                        }
                     for(j=i;s[j]!='\0';j++)
                        {
                             s[j]=s[j+1];
                        }




          f=0;
          }
       
   }
printf("%s",s);
printf("\n%ld",n1);
}
