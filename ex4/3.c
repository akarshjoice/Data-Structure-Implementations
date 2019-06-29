#include<stdio.h>
#include<stdlib.h>
int u,v,w,z;


struct ele
  {
     int value;
     struct ele *next;
   
}*ptr1,*ptr3,*p,*p2;
struct eler
   {
     int value;
     int rank;
     struct eler  *nextr;
   }*ptr2,*ptr4,*p1,*p3;


 struct ele *a1[10000];
 struct eler* a2[10000];
 struct ele* a3[10000];
 struct eler* a4[10000];

  
char ch;
void main()
{ int x,t,y,s,i;
for(i=0;i<10000;i++)
   {
     a1[i]=NULL;
     a2[i]=NULL;
     a3[i]=NULL;
     a4[i]=NULL;
   }  

do
 {
 scanf("%c",&ch);
 switch(ch)
       {
            case 'm':{

                  t=0;
                  scanf("%d",&x);
 		  t=makeset(x);
                  if(t==-1)
                        printf("PRESENT\n");
                  else
                        printf("%d\n",x);
		     }
                  break;
            case 'f':{
                   
                   scanf("%d",&x);
                   find(x);}
                   break;
            case 'u':{
                    t=0,s=0;
                    scanf("%d%d",&x,&y);
                    unio(x,y);}
                    break;
            case 's':{
                    printf("%d ",u);
                    printf("%d ",v);
                    printf("%d ",w);
                    printf("%d ",z);
		     } break;
            }
   }
          while(ch!='s');
  exit(0);
}
int makeset(int x)
  {
       ptr1=(struct ele*)malloc(sizeof(struct ele));
       ptr2=(struct eler*)malloc(sizeof(struct eler));
       ptr3=(struct ele*)malloc(sizeof(struct ele));
       ptr4=(struct eler*)malloc(sizeof(struct eler));
  
   if(a1[x]!=NULL || a2[x]!=NULL || a3[x]!=NULL || a4[x]!=NULL)
                       return -1;
   ptr1->value=x;
   ptr2->value=x;
   ptr3->value=x;
   ptr4->value=x;
 
   ptr1->next=ptr1;
   ptr2->nextr=ptr2;
   ptr3->next=ptr3;
   ptr4->nextr=ptr4;
 
   ptr2->rank=0;
   ptr4->rank=0;

   a1[x]=ptr1;
   a2[x]=ptr2;
   a3[x]=ptr3;
   a4[x]=ptr4;
  }
int find(int x)
 { 
   p=a1[x];
   if(p==NULL)
       {if(ch!='u')
         printf("NOT FOUND ");
       else
          return -1;
        }
   else
      { u++;
   while(p->next!=p)
        { p=p->next;
          u++;
         }
  if(ch!='u')
       printf("%d ",p->value);
       }

   

   p1=a2[x];
     if(p1==NULL)
       { if(ch!='u')
             printf("NOT FOUND ");
         else
             return -1;  
        }
     else
      {  v++;
   while(p1->nextr!=p1)
         {p1=p1->nextr;
          v++;
          }
 if(ch!='u')
     printf("%d ",p1->value);
       }
    struct ele *q2,*q;



       p2=a3[x];
   if(p2==NULL)
      {
        if(ch!='u')
          printf("NOT FOUND ");
        else
          return -1;  
      }
   else
         {  w++;
           while(p2->next!=p2)
             {     p2=p2->next;
                   w++;
             }
           q2=a3[x];
           while(q2->next!=q2)
                { q=q2;
                 q2=q2->next;              
                  q->next=p2;
                  
                }
     if(ch!='u')
           printf("%d ",p2->value);
                          
          }
          

   struct eler *q3,*q1;


       p3=a4[x];
   if(p3==NULL)
        {
         if(ch!='u')
          printf("NOT FOUND\n");
         else
           return -1;  
        }
   else
       {    z++;
          while(p3->nextr!=p3)
               { p3=p3->nextr;
                 z++;
               }
           q3=a4[x];
           while(q3->nextr!=q3)
                {
                    q1=q3;
                    q3=q3->nextr;
                    q1->nextr=p3;
                }
       if(ch!='u')
           printf("%d\n",p3->value);
       }

}

int unio(int x,int y)
  {  int d,u; 
    struct ele *l1,*l3,*t1,*t3;
     struct eler *l2,*l4,*t2,*t4;
         d=find(x);
         l1=p;   
         l2=p1;
         l3=p2;
         l4=p3;

         u=find(y);
         t1=p;
         t2=p1;
         t3=p2;
         t4=p3;
 if(u==-1 || d==-1)
    {   printf("ERROR\n");
       return 0;
     }
        // if(l1==NULL || t1==NULL)
          //    printf("ERROR ");
 
   if(l1!=t1)
    {      t1->next=l1;
           printf("%d ",l1->value);
    }
   else
          printf("%d ",l1->value);
        
     //  if(l2==NULL || t2==NULL)
      //      printf("ERROR ");

if(l2!=t2)
  {
    if(l2->rank>=t2->rank)
       {
         t2->nextr=l2;
         printf("%d ",l2->value);
        } 
    else
       {
        l2->nextr=t2;
        printf("%d ",t2->value);
       }
  if(l2->rank==t2->rank)
           l2->rank=l2->rank+1;
   }
else
     printf("%d ",l2->value);
          

   //  if(l3==NULL || t3==NULL)
            //  printf("ERROR ");
    
   if(l3!=t3)
    {       
           t3->next=l3;
           printf("%d ",l3->value);
    }
   else
           printf("%d ",l3->value);
 
     // if(l4==NULL || t4==NULL)
       //     printf("ERROR ");

if(l4!=t4)
  {   
    if(l4->rank>=t4->rank)
      { t4->nextr=l4;
        printf("%d\n",l4->value);
      }
    else
       { l4->nextr=t4;
         printf("%d\n",t4->value);
        }
  if(l4->rank==t4->rank)
           l4->rank=l4->rank+1;
   
   }
else
      printf("%d\n",l4->value);

}

          
        











   




          























     













 
