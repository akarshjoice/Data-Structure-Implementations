#include<stdio.h>
#include<stdlib.h>
long int print_final(long int c[],long int n,long int i)
  {   
         
           if(c[i]==0)
                {
                     printf("() ");                  
                }    
        


            else
                {  printf("( %d ",c[i]);
                         print_final(c,n,((2*i)+1));
                  	 print_final(c,n,((2*i)+2));
                    
                   printf(") ");
                }
            
   }




long int pow(long int a,long int b)
  { long int i,p=1;
         
      for(i=0;i<b;i++)
            p=p*a;
   return p;
  }
void main()
{ long int n,i,t,p,s;
  
  scanf("%ld",&n);
  long int b[n],c[pow(2,n+1)-1];
  struct inorder
   {
       long int data;
        long int status;
   }*a[n];

for(i=0;i<(pow(2,n+1));i++)
         c[i]=0;
 
 for(i=0;i<n;i++)
        scanf("%ld",&b[i]);
 
 for(i=0;i<n;i++)
    {   a[i]=(struct node*)malloc(sizeof(struct inorder));
        scanf("%ld",&(a[i]->data));
        a[i]->status=0;
     }
  long int j,flag,l=-1,r,lleft,lright;
 for(i=0;i<n;i++)
      {   
         t=b[i];
        r=0;
        lleft=-1;
        lright=-1;
        flag=0;
        for(j=0;j<n;j++)
             { 
               if(t != a[j]->data && flag==0)
                     {
                       if(a[j]->status != 0)
                           {           
                                    lleft=j;
                            }
                     }
              else if(a[j]->data == t || flag==1 )
                     {
                      if(flag==0)  
                           {       flag=1;    
                                   a[j]->status=1;
                                   if(lright==-1)
                                         continue;
                                   else
                                        { 
                                         break;
                                         }
                           }
                     else
                            {      flag=1;
                                   if(a[j]->status != 0)
                                                lright=j;
                                    if(lright==-1)
                                         continue;
                                    else
                                         break;                   
                             }
                  
  
                   }
              }
            
     if(i==0)
         {
           c[0]=t;
         }  
     else
         {
       if(lleft!=-1 && lright!=-1)
          {   for(p=0;p<(pow(2,n)-1);p++)
                  {
                      if(a[lleft]->data ==c[p])
                               break;
                  }
                  if(c[2*p+2]==0)
                        c[2*p+2]=t;
                  else
                 {
                           for(p=0;p<(pow(2,n)-1);p++)
                                  {
                      			if(a[lright]->data ==c[p])
                               		break;
                  		  }
             		c[2*p+1]=t;            
            	}
           }
      else if(lleft!=-1)
            {
                        for(p=0;p<(pow(2,n)-1);p++)
                          {
                            if(a[lleft]->data ==c[p])
                                 break;
                           }
               c[2*p+2]=t;
            }
      else
              {
                       for(p=0;p<(pow(2,n)-1);p++)
	                  {
	                      if(a[lright]->data ==c[p])
	                               break;
	                  }
               c[2*p+1]=t;
              }
          }
}   
    


//for(i=0;i<pow(2,n)-1;i++)
  //     printf("%d ",c[i]);
 print_final(c,n,0);

}


  

                    
   

































     
