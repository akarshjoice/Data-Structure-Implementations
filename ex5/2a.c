#include<stdio.h>
#include<stdlib.h>

struct node
{
 long int key;
 long int parent;
 int colour;
 struct adj* next;
}a[1000];

struct adj
 {
  long int value;
  long int weight;
  struct adj* nextnode;
  }*p,*t,*h;


long int n;


void main()
 { 
   long int i,j,top=0,stack[10000],pl=0;
   char s[10000];
   scanf("%ld",&n);
   for(i=0;i<1000;i++)
     {
        a[i].next=NULL;
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
                    stack[top]=pl;
                    top++;
                    pl=0;
                    j++;
                  }
            }
          stack[top++]=pl;
          pl=0;
      while(top!=0)
          {  top--;
         //   printf("%ld",stack[top]);
            p=(struct adj*)malloc(sizeof(struct adj));
            p->value=stack[top];
            p->nextnode=a[i].next;
            a[i].next=p;
        //  printf("%d",a[i]->data);
            
          }
               
               
         }
      }

//  while(getchar()!='\n');

  for(i=0;i<n;i++)
    {
      gets(s);
     // printf("%s",s);
      
      if(s[0]=='\0')
         {
           continue;
         }
      else
         {
          t=a[i].next;  
          j=0;
          while(s[j]!='\0')
              {
                if(s[j]!=' ')
                 {
                   pl=pl*10+(int)(s[j]-48);
                   j++;
                 }
                else
                  {  
                   t->weight=pl;
                   t=t->nextnode;
                   pl=0;
                   j++;
                  }
              }
  
                   t->weight=pl;
                   pl=0;
                   
           
         //printf("123");
            
           } 
               
               
        }


prims(0);
}

struct PQ
 {
   int no;
   int priority;
   struct PQ* down;
  }*head,*tail,*l,*m,*pre;

void insert(long int i)
{
        if(head==NULL)
           {
            l=(struct PQ*)malloc(sizeof(struct PQ));
            l->no=i;
            l->priority=a[i].key;
            l->down=NULL;
            head=l;
            tail=l;
           
           }
         else
           {  pre=head;
              m=head;
          	while(m!=NULL)
              	{
                	if(a[i].key>m->priority)
                	     {   pre=m;
                	         m=m->down;
                	      }
 
                	else
                	        break;
               }
               if(m==head)
          	{
           	 l=(struct PQ*)malloc(sizeof(struct PQ));
           	 l->no=i;
            	l->priority=a[i].key;
            	l->down=m;
           	}
   		else 
          	{
           	 l=(struct PQ*)malloc(sizeof(struct PQ));
            	l->no=i;
            	l->priority=a[i].key;
                pre->down=l;
            	l->down=m;
           	}
      		if(m==head)
       		 {
        	   head=l;
         	}
     	 }
  
}

int extractmin()
    {
       long int y;
       y=head->no;
       head=head->down;
        return y;
     }
void decreasekey(long int num,long int replace)
     {

struct PQ *rl,*po;
rl=head;
po=head;
while(rl!=NULL)
   {
        if(rl->no==num)
                break;
        po=rl;
        rl=rl->down;
    }
if(head==rl)
       head=head->down;
else
  { // printf("%d",po->no);  
     po->down=rl->down;
  } 
a[num].key=replace;
insert(num);        

}

void prims(long int s)
   { long int i,sum=0;
    for(i=0;i<1000;i++)
      {
         a[i].key=10000;
         a[i].parent=-1;
         a[i].colour=0;
       }
    
    long int u,v;
    struct adj* h;
    head=NULL;
    tail=NULL;
    a[s].key=0;
for( i=0;i<n;i++)
   {
      insert(i);
    }
    
    while(isempty())
        {  
            u=extractmin();
            h=a[u].next;
   	 while(h!=NULL)
        	{
        	   v=h->value;
        	   if(a[v].colour==0)
        	      {
        	        if(h->weight<a[v].key)
        	            {
        	               a[v].parent=u;
                            
			       decreasekey(v,h->weight);
        	             }
        	       }
                   h=h->nextnode;
        	  }
        
        a[u].colour=1;
         }
  struct adj *c;
   i=0;
    while(i<n)
      {
        c=a[i].next;
        while(c!=NULL)
           {
              if(a[c->value].parent==i)
               {         sum+=c->weight;
                         c=c->nextnode;
                                             
                }
              else
                {
                      c=c->nextnode;
                }
            }
         i++;
       }
 printf("%ld",sum);
}
int isempty()
 {
   if(head==NULL)
         return 0;
   else
         return 1;          
  }





















  








        
   







