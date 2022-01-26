#include<stdio.h>

int i, j, k,n,dist[10][10];

void floydWarshell()
{
   
  int D[n][n];
   for(i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           D[i][j]=dist[i][j];
       }  
   }
  
   for(k=0;k<n;k++)
    {
       for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
           {
                if(D[i][k]+D[k][j]<D[i][j])
                {
                   D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
  
   for(i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           dist[i][j]=D[i][j];
       }  
   }
}


int main()
{
  int i,j;
  printf("Enter the number of nodes:");
  scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   {
    printf("distance between[%d]and[%d]:",i,j);
    scanf("%d",&dist[i][j]);
   }

 floydWarshell();
 printf (" \n\n The final distance");
 printf (" \n\n ------------------------------\n");
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
   printf ("%d\t", dist[i][j]);
  printf("\n");
 }
 return 0;
}