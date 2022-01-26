#include<stdio.h>

int i, j, k,n,dist[10][10];

void floydWarshell ()
{
//Use the Floyd Warshall algorithm to solve all shortest path problems.
	
// Hint:

//step 1:    do For  k=0 to k<n:
//step 2:              do For i=0 to i<n:
//step 3:                       do For j=0 to j<n:
//step 4:                               if    D[i][k]+D[k][j] < D[i][j]:
//step 5:                                      set   D[i][j] = D[i][k]+D[k][j]
//step 6:    Exit.

//1. Add all vertices one by one to the set of intermediate vertices.
//  Before the iteration stars, we have shortest distances between all
//   vertex pairs so that the shortest distances consider only the
//   vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
//   After the iteration is over, the vertex number adds k to the intermediate vertex of the 
//   group, and the set becomes {0,1,2,...,k}

//2. Select all vertices as sources.
//3.  Select all vertices as the destination of the source selected above.
//4. When vertex k is on the shortest path
//5.  i to j, then update the value of dist[i][j].

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