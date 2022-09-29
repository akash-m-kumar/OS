#include<stdio.h>
int main()
{
int n,m,max[10][10],alloc[10][10],avail[10],i,j,k;
printf("\nEnter the number of rows : ");
scanf("%d", &n);
printf("\nEnter the number of columns: ");
scanf("%d", &m);

printf("\nEnter elements of allocation matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++) 
  {
   printf("Enter element of alloc %d,%d: ", i + 1, j + 1);
   scanf("%d", &alloc[i][j]);
  }

printf("\nEnter elements of max matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++) 
  {
   printf("Enter element of max %d,%d: ", i + 1, j + 1);
   scanf("%d", &max[i][j]);
  }
printf("\nEnter the avail resource:\n");
for(i=0;i<m;i++)
{
scanf("%d",&avail[i]);
}
int f[n],ans[n],ind=0;
for(k=0;k<n;k++)
  {
  f[k]=0;
  }
int need[n][m];
for(i=0;i<n;i++)
  for(j=0;j<m;j++)
    {
    need[i][j]=max[i][j]-alloc[i][j];
    }
int y=0;
for(k=0;k<m;k++)
  {  
     {
      int flag=0;
      for(j=0;j<n;j++)
        {
        if(need[i][j]>avail[j])
          {
          flag = 1;
          break;
          }
        }
      if(flag==0)
        {
        for(y=0;y<m;y++)
          {
          avail[y]+=alloc[i][y];
          }
        f[i]=1;
        }
      }
    }
    int flag=1;
for(int i=0;i<n;i++)
    {
    if(f[i]==0)
      {
      flag=0;
      printf("\nThe following system is not safe\n");
      break;
     }
    }
if(flag==1)
{
printf("\nFollowing is in the safe SAFE sequence\n");
for(i=0;i<n-1;i++)
printf("P%d->",ans[i]);
printf("P%d",ans[n-1]);
 }
 return 0;
}

