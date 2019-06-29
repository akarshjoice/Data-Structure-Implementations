#include<stdio.h>
#include<stdlib.h>
void main()
{ char ch;
  int  l=0;
 FILE *fptr,*fptr1;
 fptr=fopen("in.txt","r");
 fptr1=fopen("out.txt","w");
 if(fptr == NULL || fptr1 == NULL)
     {  printf("error");
       exit(0);
     }
 ch=fgetc(fptr);
 while(ch !=EOF)
 {
  if(l!=1)
    {
        if(ch ==' ')
           {   l=l+1;

              fprintf(fptr1,"%c",ch);
           }
        else if(ch == '\t')
          {    fprintf(fptr1," ");
              l=l+1;
          }
        else
 {
              fprintf(fptr1,"%c",ch);
              if(l==1)
                      l--;
             }
    }
  else
    {
        if(ch ==' ' || ch=='\t')
               l=1;
        else
              { fprintf(fptr1,"%c",ch);
               l--;

              }
    }
   ch=fgetc(fptr);
 }

fclose(fptr);
fclose(fptr1);
}
