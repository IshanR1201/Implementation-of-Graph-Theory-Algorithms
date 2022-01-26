//Bellman-Ford algorithm for find shortest path

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

#define N 8					        //size of matrix
#define INF 9999			      //weight of disconnected nodes

int head[N][N]={			
 {0,1,INF,INF,7,INF,INF,INF},       // matrix representing the weights of edges
 {1,0,3,INF,INF,3,5,INF},
 {INF,3,0,4,INF,INF,1,INF},
 {INF,INF,4,0,INF,INF,2,3},
 {7,INF,INF,INF,0,2,INF,INF},
 {INF,3,INF,INF,2,0,INF,INF},
 {INF,5,1,2,INF,INF,0,6},
 {INF,INF,INF,3,INF,INF,6,0}};


void bellman_ford();
void print();


int prev[N][N];                     //minimum cost os D1 ~ D6
int current[N][N]; 

int main()
{
	bellman_ford();
	print();
	return 0;
}
void bellman_ford()
{
	int w,v;
	for (int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			prev[i][j] = INF;
			current[i][j] = INF;
		}
	}
	//prev[0][0]=0;
	current[0][N-2]=0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = i+1; j < N+1; j++)
		{
			if (head[i][j] + current[i][N-2] < current[j][N-2])
			{
				//prev[j][N-2] = current[i][i];
				current[j][N-2] = current[i][N-2] + head[i][j];
				prev[i][N-2] = current[j][N-2];
			}
		}
	}


		//Hint
		// 1. define local variables as needed
	// 2. initialize previous values
	// 3. initialize the current values 
	// in nested for loops
	// 4. check if the distance to the node w is greater than (distance to v + distance b/w v and w)
	// 5. if the condition above is true, update the current distance of w to the new value
	// 6. set previous value to the current value for the next node
}
void print()
{
	int i=0;
	printf("Bellman Ford Argorithm!!(start = node1)\n");
	printf("========================================\n");
	printf("     destination             cost \n");
	for(i = 1; i < N; i++)                                          //print the distance to the destination
	{
        	printf("%11d%21d\n",i+1, current[i][N-2]);
	}
}