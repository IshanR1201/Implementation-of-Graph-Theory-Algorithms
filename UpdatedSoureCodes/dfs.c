#include<stdio.h>
#include<stdlib.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NIL 100
#define INFINITY 10000

int dfs(int u);

/* 'n' is the number of nodes and 'time' is the discovery time of a node */
int n,time;

/* Adjacency matrix to hold the graph */

int **adj;

/* Matrix to hold the graph's node color */

int *color;

/* Matrix to hold the predecessor node values */

int *pred;

/* Matrix to hold the discovery time of a node */

int *dist;

/* Matrix to hold the finishing time of a node */

int *finish;

int main()
 {
   int i,j;

   printf("\n Enter the number of nodes: ");
   scanf("%d",&n);

   /* Memory allocation for all matrices is done here */

   adj = (int**)malloc(sizeof(int*));

   for(i=0;i<n;i++)
	   adj[i] = (int*)malloc(n*sizeof(int));

   color=(int*)malloc(n*sizeof(int));
   pred=(int*)malloc(n*sizeof(int));
   dist=(int*)malloc(n*sizeof(int));
   finish=(int*)malloc(n*sizeof(int));

   printf("\n Enter the adjacency matrix: ");

   for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
       scanf("%d",&adj[i][j]);
    }
   
	/* Initialization of matrices */

    for(i=0;i<n;i++)
      {
       color[i]=WHITE;
       pred[i]=NIL;
      }

    /* set discovery time of starting node as 0 */

    time=0;

	printf("\n Node\tFinish Time\n");
	printf("----\t-----------\n");
    for(i=0;i<n;i++)
     {
		/* If the color of node is white then call dfs */

      if(color[i] == WHITE)
      dfs(i);
     }
  }

  int dfs(int u)
   {
	int i;
	color[u] = GRAY;
   time = time+1;
   dist[u] = time;
	for(i=0;i<n;i++)
	{
		if(adj[u][i] == 1 && color[i] == WHITE)
		{
			pred[i] = u;
			dfs(i);
		}
   }
      color[u] = BLACK;
      time= time+1;
      dist[u] = time;
      finish[u] = dist[u];
      printf("%d\t%d\n",u,finish[u]);
			
	
    /* 1. Update the color of u as gray 
	   2. update discovery time of node u as (current discvoery time + 1).
	   3. For each node adjacent of u, check if the node is reachable (i.e.,
	      Adjacent node value is not infinity and color of adjacent node is white).If so
		  then:

		  a. set u's adjacent node's predecessor as u in the predecessor matrix.
		  b. call dfs recursively with the each value of u's adjacent node as function argument to dfs(). 
	
	   4. update color of u as black once step#3 is done
	   5. update discovery time of node u as (current discvoery time + 1).
	   6. Update u's finish time as updated discovery time of step 5
	   7. Print the finishing time of u.
	*/
   }