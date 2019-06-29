#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void main()
 { int i=0;
   char *a,tmp,ch;
  // printf("\nEnter Input:");
   a=(char*) malloc(sizeof(char));
  if(a==NULL)
     exit(0);
   scanf("%c",&ch);

   while(ch != '\n')
     {   a[i]=ch;
         i=i+1;
        scanf("%c",&ch);
         a=(char*) realloc(a,(i+1)*sizeof(char));
        if(a==NULL)
            exit(0); 
        a[i]='\0';

    }

   reverse(a,0);
  // printf("Output:");
   printf("%s",a);

 }
 void reverse(char ch[],int i)
 {
  if(i!=(strlen(ch)/2))
   {
      ch[i]=ch[i]+ch[strlen(ch)-i-1];
      ch[strlen(ch)-i-1]=ch[i]-ch[strlen(ch)-i-1];
      ch[i]=ch[i]-ch[strlen(ch)-i-1];
      i=i+1;
      reverse(ch,i);
   }
  }
