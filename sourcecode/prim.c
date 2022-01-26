#include<stdio.h>
#define INFINITY 10000

/* Function declaration for initialize */

int initialize();

/* matrices for covered nodes, predecessor and spanning tree distances respectively */

int covered[10];
int pred[10];
int dist[10];

int main(int argc,char *argv[])
{
  int i,j,n,src,n1,count,small,k;
  int adj[10][10],index,coveredVar; 
  initialize();

  printf("\n Enter the number of nodes: ");
  scanf("%d",&n);
 
  printf("Enter the starting node between 0 to %d: ",n-1);
  scanf("%d",&src);

  printf("\n Enter the adjacency matrix:\n");

  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    scanf("%d",&adj[i][j]);
  }

  n1=n; 
  covered[0] = src;
  pred[src]=INFINITY;
  count=1;
  dist[0]=0;

  while(n1 != 0) 
   {
    small=INFINITY;
    for(j=0;j<count;j++)
     {
      for(k=0;k<n;k++)
       {
           small = INFINITY;
           
		  /* 1. small is initially INFINITY. 

		     2. Initially source is the only node that is covered. All other nodes are NIL.
			    But covered matrix gets updated as the above loops run. So see the code very carefully !!

		     3. In the adjacency matrix use only the rows that are covered by covered[] matrix to
			    find the smallest distance in the adjacency matrix and use this condition to fill the 
				first part of the if condition below. You should also use part of step 1 here to satisfy the if
				condition.

			 4. If the first part of the if condition is satisfied to be the smallest distance then the rest of the 
			    program is taken care.
		 */
			 

       if( /* Condition to be filled */  && completed(k,n) == 1)
         {

           
          small=adj[covered[j]][k];
          index=k;
          coveredVar=covered[j];
          pred[k]=coveredVar;
		  dist[k]=small;
	     }      
       } 
     }
    n1--;
    

    adj[coveredVar][index]=INFINITY;
    adj[index][coveredVar]=INFINITY;

    covered[count]=index;
    count++; 
  }

    printf("NODE\tPREDECESSOR\tDISTANCE FROM PREDECESSOR\n");
	printf("----\t-----------\t-------------------------\n");
    for(i=0;i<n;i++)
     printf("%d\t%d\t\t%d\n",i,pred[i],dist[i]);
}

int initialize()
 {
  int i;
 
   for(i=0;i<10;i++){
    covered[i]=100;
    pred[i]=INFINITY;
   }
 }

int completed(int k,int n)
 {
  int i;

  for(i=0;i<n;i++)
   if(covered[i] == k)
    return 0;

   return 1;
 } 
 
