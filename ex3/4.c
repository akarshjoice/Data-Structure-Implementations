#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
long long int size=0;
int parent(int i)
{
        return (i-1)/2;
}
struct PQ
{
    long long int a;
    long long int priority;
}t;
 
void min_Heapify(struct PQ *pq,long long int i)
{    struct PQ temp;
    long long int small=i,l,r;
    l=2*i+1;
    r=2*i+2;
    if ((pq[small].priority>pq[l].priority)&& l<size)
        small=l;
    if ((pq[small].priority>pq[r].priority)&&(r<size))
        small=r;
    if(small!=i)
    {   temp=pq[small];
        pq[small]=pq[i];
        pq[i]=temp;
        min_Heapify(pq,small);
    }
}
struct PQ* insert(struct PQ *pq,long long int elem,long long int pr)
{    struct PQ temp;
     long long int i;
    if(size==0)
       {
         pq=(struct PQ*)malloc(sizeof(t));
         pq[size].a=elem;
         pq[size].priority=pr;
         size=size+1;
         return pq;
       }
  
     else
       {
        pq=(struct PQ*)realloc(pq,(size+1)*sizeof(t));
        pq[size].a=elem;
        pq[size].priority=pr;
        size++;
       }
     i=size-1;
     while((i>0) && ((pq[parent(i)].priority)>(pq[i].priority)))
    {
        
        temp=pq[parent(i)];
        pq[parent(i)]=pq[i];
        pq[i]=temp;
        i=parent(i);
    }
    return pq;
}
struct PQ* extract_min(struct PQ *pq)
{
    if (size==0)
    {
        printf("EMPTY\n");
        return pq;
    }
    printf("%lld (%lld)\n",pq[0].a,pq[0].priority);

    pq[0]=pq[size-1];
    size-=1;
    
    min_Heapify(pq,0);
    pq=(struct PQ*)realloc(pq,(size)*sizeof(struct PQ));
    return pq;
}
void get_min(struct PQ *pq)
{
    if (size==0)
        printf("EMPTY\n");
    else
        printf("%lld (%lld)\n",pq[0].a,pq[0].priority);
}
void decrease_priority(struct PQ *pq,int elem,int newpr)
{   struct PQ tmp;
    long long int i=0;
    while((pq[i].a)!=elem && i<size)
        i++;

        pq[i].priority=newpr;

        while(i>0 && (pq[parent(i)].priority)>pq[i].priority)
        {
           
            tmp=pq[parent(i)];
            pq[parent(i)]=pq[i];
            pq[i]=tmp;
            i=parent(i);
        }
    
}
void main()
{
    char ch;
    long long int elem,pr,newpr;
    struct PQ *pq=NULL;
    do
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case 'a':
               scanf("%lld%lld",&elem,&pr);
                pq=insert(pq,elem,pr);
               break;
            case 'e':
            pq=extract_min(pq);
            break;
            case 'g':
            get_min(pq);
            break;
            case 'd':
                scanf("%lld%lld",&elem,&newpr);
                decrease_priority(pq,elem,newpr);
                break;
        }
   }
   while(ch!='s');
   exit(0);
}
