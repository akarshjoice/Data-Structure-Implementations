#include<stdio.h>
#include<stdlib.h>
void main()
{   int K,l,i;

    char g,ch,temp;
    char *a;
    
    //printf("\n1.Encryption");
    //printf("\n2.Decryption");
    //printf("\nEnter your choice:");
    scanf("%c",&ch);
   if (!(ch=='1' || ch=='2'))
        {
           printf("\nWrong Choice");
           exit(0);
        }


   //  printf("\nEnter String length:");
    scanf("%d",&l);
    // printf("\nEnter String :");
    a=malloc((l+1)*sizeof(char));
    if(a==NULL)
       exit(0);
     scanf("%c",&temp); //temp variable to clear buffer
     gets(a);
    //scanf("%s",&a);

   //printf("\nEnter K:");
   scanf("%d",&K);
   K=K%26;
    switch(ch)
  {
    case '1':
          for( i=0;i<l;i++)
            {
               if(a[i]>=65 && a[i]<=90)
                       {
                        if(a[i]+K>90)
                              a[i]=64+((a[i]+K)-90);
                        else
                              a[i]=a[i]+K;
                       }

               else if(a[i]>=97 && a[i]<=122)
                       {
                        if(a[i]+K>122)
                         a[i]=96+((a[i]+K)-122);

                         else
                               a[i]=a[i]+K;
                       }

            }
               printf("%s",a);
              break;
   case '2':

            for(i=0;i<l;i++)
            {
               if(a[i]>=65 && a[i]<=90)
                       {
                        if(a[i]-K<65)
                              a[i]=91-(65-(a[i]-K));
                        else
                              a[i]=a[i]-K;
                       }

               else if(a[i]>=97 && a[i]<=122)
                       {
                        if(a[i]-K<97)
                               a[i]=123-(97-(a[i]-K));

                         else
                               a[i]=a[i]-K;
                       }
           }

               printf("%s",a);
              break;
  }
}
