#include<stdio.h>
#include<stdlib.h>
void main()
{//mainvoid
int frag[10],b[10],f[10],bf[10],ff[10],i,j,nb,nf,temp,c,x,lowest=10000,highest=0;
printf("\nEnter the number of blocks:\n");
scanf("%d",&nb);
printf("\nEnter the number of files:\n");
scanf("%d",&nf);
printf("\nEnter the size of blocks:\n");
for(i=1;i<=nb;i++)
  {
  printf("Block %d:",i);
  scanf("%d",&b[i]);
  }
printf("\nEnter the size of files:\n");
for(i=1;i<=nf;i++)
  {
  printf("File %d:",i);
  scanf("%d",&f[i]);
  }
do
{
printf("\nENTER THE CHOICE\n1.FIRSTFIT\n2.BESTFIT\n3.WORSTFIT\nCHOICE:");
scanf("%d",&c);
switch(c)
  {
  case 1:
    {
    printf("\nFIRST FIT\n");
  for(i=1;i<=nf;i++)
  {//for1
  for(j=i;j<=nb;j++)
    {//for2
    if(bf[j]!=1)
      {//if1
      temp=b[j]-f[i];
      if(temp>=0)
        {//if2
        ff[i]=j;
        break;
        }//if1end
      }//if2end
    }//for2end  
frag[i]=temp;
if(temp<0)  
  printf("\nFile %d can't be allocated\n",i);
  bf[ff[i]]=1;
}//for1end
printf("\nFile_no:\tFile_block:\tBlock_no:\tBlock_size:\tFragments");
for(i=1;i<nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",i,f[i],ff[i],b[ff[i]],frag[i]);
    break;
    }
  case 2:
    {
    printf("\nBEST FIT\n");
  for(i=1;i<=nf;i++)
  {//for1
  for(j=i;j<=nb;j++)
    {//for2
    if(bf[j]!=1)
      {//if1
      temp=b[j]-f[i];
      if(temp>=0)
        {//if2
        if(lowest>temp)
          {
          ff[i]=j;
          lowest=temp;
          }//if3end
        }//if2end
      }//if1end
    }//for2ends
    frag[i]=lowest;
    if(lowest<0)
       printf("\nFile %d can't be allocated\n",i);
       bf[ff[i]]=1;
       lowest=10000;
  }//for1ends       
printf("\nFile_no:\tFile_block:\tBlock_no:\tBlock_size:\tFragments");
for(i=1;i<=nf&&ff[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",i,f[i],ff[i],b[ff[i]],frag[i]);
    break;
    }
  case 3:
    {
    printf("\nWORST FIT\n");
    for(i=1;i<=nf;i++)
  {//for1
  for(j=i;j<=nb;j++)
    {//for2
    if(bf[j]!=1)
      {//if1
      temp=b[j]-f[i];
      if(temp>=0)
        {//if2
        if(lowest>temp)
          {
          ff[i]=j;
          highest=temp;
          }//if3end
        }//if2end
      }//if1end
    }//for2ends
 frag[i]=highest;
    if(highest==0)     
       printf("\nFile %d can't be allocated\n",i);
       bf[ff[i]]=1;
       highest=0;      
  }//for1ends       
printf("\nFile_no:\tFile_block:\tBlock_no:\tBlock_size:\tFragments");
for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",i,f[i],ff[i],b[ff[i]],frag[i]);
    break;
    }
  }
printf("\n\nWould you like to continue? (1/0) : ");
scanf("%d", &x);
} while (x == 1);
}//mainvoidend
    
