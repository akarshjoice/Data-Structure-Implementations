#include<stdio.h>
#include<stdlib.h>
int *a,t,R;
char c,ch;
struct node
{
  int data;
  struct node* next;
}*b[100];


void findR()
 {  int flag=0,i;
       for(i=t-1;i>0;i--)
        {
            flag=checkprime(i);
            if(flag==1)
                     break;
         }
   R=i;
 }
    
int checkprime(int k)
    {       int j;
           for(j=2;j<k;j++)
               {
                      if(k%j==0)
                             return 0;
               }
        return 1;
     }





void main()
{  
 
  int p=0,k,m;
  scanf("%c",&c);
  scanf("%d",&m);
  t=m;
  hashtable(m);
  findR();
    do
      {
       scanf("%c",&ch);
       
     switch(ch)
        {
            case 'i':
                   scanf("%d",&k);
             	   insert(k);
                   break;
            case 's':
                   scanf("%d",&k);
                   p=search(k);
                   printf("%d\n",p);
                   break;
            case 'd':
                   scanf("%d",&k);                    
                   delete(k);
                 
                   break;
            case 'p':
                   print_hash();
                  
                   break;
         }
      }
    while(ch!='t');
exit(0);
 
}                       

void hashtable(int m)
{ int i=0;
if(c=='a' || c=='b' || c=='c')
 { a=(int*)malloc(sizeof(int)*m);
 for(i=0;i<m;i++)
        a[i]=-1;
 }
else
 { 
      for(i=0;i<m;i++)
      {
       b[i]=NULL;
      }
 }
}
        
void insert(int k)
{  int i=0,x=k,p,q;

 
if(c=='a' || c=='b' || c=='c')
 {
  k=h(k,0);
  while(a[k]!=-1 && i<t && a[k]!=-2)
   {   
     k=h(x,i);
     i++;
   }
     if(i==t)
                    printf("\nfull");
     else
         { 
                    if(c=='a' || c=='b' || c=='c')
                    a[k]=x;
         }
 }
else
   { x=k;
     k=k%t;
   if(b[k]==NULL)
     {
        b[k]=(struct node*)malloc(sizeof(struct node));
        b[k]->data=x;
        b[k]->next=NULL;
      }
  else
      {
         struct node *pre;
           pre=b[k];    
        b[k]=(struct node*)malloc(sizeof(struct node));
         b[k]->data=x;
         b[k]->next=pre;
      }
    }
}


void delete(int k)
{ 
int i=0,x=k;
if(c=='a' || c=='b' || c=='c')
  {
            k=h(x,i);
            while(i<t && a[k]!=x)
              {
                    i=i+1;
                    k=h(x,i);
              }
           if(i!=t)
                    a[k]=-2;
           else
                    printf("\n ERROR");
  }
else
  {    int flag=0;
    int x;
          x=k;
        k=k%t;
      struct node* ptr,*pre;
     ptr=b[k];
     pre=b[k];
      while(ptr!=NULL)
         {
              if(ptr->data == x && flag==0)
                     {  b[k]=ptr->next;  
                       flag=1; 
                       break;            
                      }
              else if(ptr->data == x && flag==1)
                      {
                         pre->next=ptr->next;
                         break;               
                      }
              else
                      {
                       pre=ptr;
                       ptr=ptr->next;
                       }
           }
   }
}
 
int search(int k)
 {
  if(c=='a' || c=='b' || c=='c')
      {
            int i=1,x=k;
            k=h(x,0);
             while(i<t && a[k]!=x && a[k]!=-1)
               {  
  
                   k=h(x,i);
                   i++;
               }
         if(a[k]==x)
                      return 1;
         else
                      return -1;
      }
  else
      { int x;
        x=k;
        struct node* ptr;
        k=k%t;
        ptr=b[k];
        while(ptr!=NULL)
          {
             if(ptr->data==x)
                        break;
             else
                      ptr=ptr->next;
          }
        if(ptr==NULL)
              return -1 ;
        else
              return 1;
      }
}
void print_hash()
{
    int i=0;
if(c=='a' || c=='b' || c=='c')
       {
         while(i<t)
              {
                if(a[i] ==-1 || a[i] ==-2)
                    printf("%d ()\n",i);
                else
                    printf("%d (%d)\n",i,a[i]);
               i++;
               }
        }
else
       {   
         int *v=(int *)malloc(sizeof(int));
          struct node*ptr;
         int f=0;
           while(i<t)
               {  f=0;
                   ptr=b[i];
                   printf("\n%d (",i);
                   while(ptr!=NULL)
                        {  
                           v[f]= ptr->data;
                           v=(int *)realloc(v,(sizeof(int)*(f+1))); 
          //                 printf("%d ",ptr->data);
                           ptr=ptr->next;
                           f++;

                          }
                  f--;
                  while(f>=0)
                       {
                      if(f!=0)
                        printf("%d ",v[f]);
                      else
                        printf("%d",v[f]);
                        f--;
                       }
                     
                              
                     printf(")");
                 
 
                  i++;
              }
          printf("\n");
        }
}

int h(k,i)
 {   int q,p;
      if(c=='a')
              k=(k+i)%t;
      else if(c=='b')
              k=(k+(i*i))%t;
      else if(c=='c')
              {
               p=k%t;
               q=R-(k%R);
               k=(p+i*q)%t;
              }
      return k;
  }












      















