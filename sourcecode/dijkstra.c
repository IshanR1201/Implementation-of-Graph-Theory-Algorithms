#include<stdio.h>

#define INFINITY 10000
#define NIL 20000
#define TRUE 1
#define FALSE 0

/* These global variable are used to hold the number of nodes and adjacency matrix
   of the graph respectively */
int n,**adj;

int i1,j2;

/* These variable are used to hold the predecessors, shortest distances and completed nodes
   of the graph */

int *pred,*dist,*completed;

int main(int argc,char **argv[])
 {
   int i=0,j,min,index;
    
   printf("\n Enter the number of nodes: ");
   scanf("%d",&n);

   printf("\n Enter the adjacency matrix: ");
   
   /* Memory allocation for the adjacency matrix and other matrices takes place here */

   adj = (int **) malloc( n * sizeof(int *) );

   for(i=0;i<n;i++)
    adj[i]=(int*)malloc(n*sizeof(int));

    
    pred=(int*)malloc(n * sizeof(int));
    dist=(int*)malloc(n * sizeof(int));
    completed=(int*)malloc(n * sizeof(int));
    
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",&adj[i][j]);
    }
   
	/* Initialization takes place here */

    for(i=0;i<n;i++)
     {
      pred[i]=NIL;
      dist[i]=INFINITY;
      completed[i]=FALSE;
     }
     
	 dist[0]=0;
     index=0;

     /* This part of the program checks if all the nodes' final distances has already been
	    computed or not. If they are not computed yet then this code relaxes all those edges
		whose final distances are not yet computed */

 	 while(checkCompleted())
	 {
		   for(j=0;j<n;j++)
			 {
			    if(adj[index][j] != INFINITY)
				 {
					relax(index,j);
				 }
			 }

		index=findSmallestDistance();
	 }

  printf("\nNode\tDistance from source \n");
  printf("\n----\t--------------------\n");
  for(i=0;i<n;i++)
   printf("%d\t%d\n",i,dist[i]);
}
 
 int relax(int u,int v)
  {
    if (dist[v] > dist[u] + adj[u][v])
     {
       dist[v] = dist[u] + adj[u][v];
       pred[v] = u;
     }
  }
  
  int findSmallestDistance()
   {
	
	   /* Check for the smallest distance in the 'dist' matrix
	      and simultaneously check the status of the 'completed' matrix.
		  
		  Hint: A value of 1 means the node is already covered and a 0 means
		  that the node is yet to be discovered.

		  1. If the distance of a given node is smallest in the dist matrix and at the same time
		     the node is not yet covered in the completed matrix then record that index(NOT THE VALUE)

			 For example :

			 if dist matrix's indices are :  0 1 2 3     4
			 If dist matrix's value is:      0 4 1 10000 10000
			 if completed matrix's value is: 1 0 1 0 0
              
			 then index = 1

			 because 4 is the smallest value in the dist matrix that is not yet discovered. 

		  2. Update the value of 'completed' matrix at this index as 1

		  3. return the value of this index to the calling function.*/
  }  
   
 int checkCompleted()
 {
	 int i;

	for(i=0;i<n;i++)
		if(completed[i] == FALSE)
		 return 1;

	return 0;
 }