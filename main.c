#include<stdio.h>
#include<conio.h>

#define INFINITY 9999 // adjust infinity accordingly
#define MAX 20 // max number of vertices

/* Dijkstra's Algorithm
 *
 * G[MAX][MAX] - graph of dists between vertices
 *               G[i][MAX] where i is the node number (0 for self, 0 for no path)
 * n           - number of vertices, since n doesn't always populate G
 * startnode   - the initial node to run dijkstra's algorithm
 *
 */
void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()
{
    int G[MAX][MAX];
    int n,s;

    printf("Enter # of vertices (1-20): ");
    scanf("%d",&n);

    while(n > 20 || n < 0){
        printf("Reenter # of vertices (1-20): ");
        scanf("%d", &n);
    }

    printf("\nEnter the dists matrix (Note: assign 0 for self, assign 0 for no path):\n");
    for(int i=0;i<n;i++){
        printf("dists from node %d: ", i);
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }

    printf("\nEnter the starting node: ");
    scanf("%d",&s);
    dijkstra(G,n,s); // begin dijkstra's algorithm

    return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX],dist[MAX],prev[MAX];
    // cost[][]   - stores cost matrix of all vertices
    // dist[]     - stores dists to every other node
    // prev[]     - stores the previous nodes to create shortest paths

    int visited[MAX],visitcount,mindist,nextnode;
    // visited[]  - markes visited nodes (prevent backtracking)
    // visitcount - stores the number of nodes "seen"

    // create the cost matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    // initialize dist[], prev[], and visited[]
    // for starting node
    for(int i=0;i<n;i++){
        dist[i]=cost[startnode][i];
        prev[i]=startnode;
        visited[i]=0;
    }

    dist[startnode]=0;
    visited[startnode]=1;
    visitcount=1;

    while(visitcount<n-1){

        mindist=INFINITY; // make minimum something extremely large

        // find next node of minimum distance
        for(int i=0;i<n;i++)
            if(dist[i]<mindist&&!visited[i]){
                // if distance to node is less than current mindist
                // and has not been visited yet through algorithm
                mindist=dist[i];
                nextnode=i;
            }

        // check if better path exists
        // update previous node path accordingly
        visited[nextnode]=1;
        for(int i=0;i<n;i++)
            if(!visited[i])
                if(mindist+cost[nextnode][i]<dist[i]){
                    dist[i]=mindist+cost[nextnode][i];
                    prev[i]=nextnode;
                }

        visitcount++;
    }

    // print
    int i=0;
    while(i!=-1){
        printf("\nEnter node to travel to (-1 to exit): ");
        scanf("%d",&i);

        if(i >= n || i < 0) continue;

        printf("Shortest distance to node %d = %d",i,dist[i]);

        printf("\nPath=%d",i);
        int j=i;
        while(j!=startnode){
            j=prev[j];
            printf("<-%d",j);
        }
    }
}
