
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct que
{

   long int value;
   struct que* nextnode;
}*head,*tail,*t;


struct node
{
  long int data;
  struct node* next;
}*a[10000],*b[10000],q,*p;

long int color[10000],n,flag=0;

  
void bfs(long int start,long int key)
    {  
      long int v,u;
       color[start]=1;
       
    
       struct node* pt;
       enqueue(start);
      printf("%d ",start);
       while(isempty())
         {
            u=dequeue();
            pt=a[u];
        
              while(pt!=NULL)
                {  v=pt->data;
                    
                 
                  if(color[v]==0)
                       {  
                          printf("%d ",v);                   
                          if(v==key)
                             {
                              head=NULL;
                              tail=NULL;
                             
                                return;
                             }
                          color[v]=1;
                          enqueue(v);
                       }
                  pt=pt->next;
                }
            color[u]=2;
         }
    }
     
  void enqueue(long int start)
    { 
      
      if(tail==NULL)
       {
          t=(struct que*)malloc(sizeof(struct que));
          t->value=start;
          t->nextnode=NULL;
          head=t;
          tail=t;
       }
      else
       {
         tail->nextnode=(struct que*)malloc(sizeof(struct que));
         tail=tail->nextnode;
         tail->value=start;
         tail->nextnode=NULL;
       }
       
    }
       
 int isempty()
   {
     if(tail==NULL)
        return 0;
      else 
        return 1;
   }
       
   int dequeue()
     {
       long int l;
       l=head->value;
       if(head==tail)
          {
            head=NULL;
            tail=NULL;
          }
       else
        head=head->nextnode;
       return l;
     }

    
  void main()
{ head=NULL;
  tail=NULL;
  long int i,j,pl=0,top=0,stack[10000],start,key;
 char s[10000],choice[100],ch;
  scanf("%ld",&n);
  
   for(i=0;i<10000;i++)
    {
      b[i]=NULL;      
      a[i]=NULL;
      color[i]=0;
    }
     while(getchar()!='\n');
  for(i=0;i<n;i++)
    {
      gets(s);
     // printf("%s",s);
      
      if(s[0]=='\0')
         {
           continue;
         }
      else
         {  j=0;
            top=0;
          while(s[j]!='\0')
            {
                if(s[j]!=' ')
                 {
                   pl=pl*10+(int)(s[j]-48);
                   j++;
                 }
                else
                  {  
                  p=(struct node*)malloc(sizeof(struct node));
                  p->data=pl;
                  p->next=b[i];
                  b[i]=p;      

                    stack[top]=pl;
                    top++;
                    pl=0;
                    j++;
                  }
            }
          p=(struct node*)malloc(sizeof(struct node));
          p->data=pl;
          p->next=b[i];
          b[i]=p;      

          stack[top++]=pl;
          pl=0;
      while(top!=0)
          {  top--;
         //   printf("%ld",stack[top]);
            p=(struct node*)malloc(sizeof(struct node));
            p->data=stack[top];
            p->next=a[i];
            a[i]=p;
        //  printf("%d",a[i]->data);
            
          }
               
               
         }
      }

    
 do
  {
  
  scanf("%s",choice);
  
  if(!(strcmp(choice,"bfs")))
    {
     
      scanf("%ld%ld",&start,&key);
      bfs(start,key);
      printf("\n");
       for(i=0;i<10000;i++)
        {
          color[i]=0;
        }
      
      
    }
  else if(!(strcmp(choice,"dfs")))
    { flag=0; 
      scanf("%ld%ld",&start,&key);
      dfs(start,key);
       printf("\n");
       for(i=0;i<10000;i++)
        {
          color[i]=0;
        }
    }
  }
 while((strcmp(choice,"stp")));
   
  exit(0);
}    
      
      
void dfs(long int start,long int key)
   {
    long int v;
    struct node* pt;

     color[start]=1;
     pt=b[start];
     printf("%d ",start);
    

     while(pt!=NULL)
         { v=pt->data;
           if(start==key)
             { flag=1;
               return;
              }
               
           if(color[v]==0)
             {
                dfs(v,key);
               }  
           if(flag==1)
                  return;
            pt=pt->next;     
           
         } 
           
    color[start]=2; 
  }
     
     
     
   
