#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4,*f5;
int lc,sa,l,op1,o,len,errorflag=0;
char m1[20],la[20],op[20],otp[20],sym[20];
f1=fopen("input.txt","r");
f3=fopen("symtab.txt","w");
f5=fopen("inter.txt","w");
fscanf(f1,"%s %s %d",la,m1,&op1);
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 fprintf(f5,"-\t%s\t%s\t%d\n",la,m1,op1);
 printf("-\t%s\t%s\t%d\n",la,m1,op1);
 }
 else
 lc=0;
fscanf(f1,"%s %s",la,m1);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 fprintf(f5,"\n%d\t%s\t%s\t%s\n",lc,la,m1,op);
 printf("\n%d\t%s\t%s\t%s\n",lc,la,m1,op);
 if(strcmp(la,"-")!=0)
 {/*f3=fopen("symtab.txt","w");
   fscanf(f3,"%s",sym);
  while(!feof(f3))
  {
   if(strcmp(sym,la)==0)
   {errorflag=1;break;}
   }
  if(errorflag=0)*/
 fprintf(f3,"\n%d\t%s\n",lc,la);
    // fclose(f3);
 }
  f2=fopen("optab.txt","r");
 fscanf(f2,"%s %d",otp,&o);
 while(!feof(f2))
 {
  if(strcmp(m1,otp)==0)
  {
    lc=lc+3;
    break;
  }
  fscanf(f2,"%s %d",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
 
    {
   lc=lc+3;
   }
   else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
    else if(strcmp(m1,"BYTE")==0)
    {
    if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;}
    }
