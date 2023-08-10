#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V])
{
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight of Minimum Spanning Tree: %d\n", totalWeight);
}

// Function to construct and find the minimum spanning tree using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize all keys as infinity and mstSet as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first 0th vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // Construct MST with V-1 vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver program to test above function
int main()
{
    int graph[V][V];

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the minimum spanning tree using Prim's algorithm
    primMST(graph);

    return 0;
}
