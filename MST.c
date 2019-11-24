#include <stdio.h>
#include <stdlib.h>

int isFull(int * vertices_taken, int vertices){
    for(int i=0;i<vertices;i++){
        if(vertices_taken[i] == 0){
            return 0;
        }
    }
    return 1;
}

void printMST(int** graph, int vertices){
    for(int i =0;i<vertices;i++){
        for(int j =0; j<vertices;j++){
            if(graph[i][j] == 0) graph[i][j] = INT_MAX;
        }
    }

    int min;
    int *vertice_taken = (int *) calloc(vertices, sizeof(int));

    while(!isFull(vertice_taken, vertices)){
        min = graph[0][0];
        int src,des;

        for(int i = 0;i<vertices;i++){
            for(int j=i;j<vertices;j++){
                if(min > graph[i][j]){
                    min = graph[i][j];
                    src = i;
                    des = j;
                }
            }
        }

        if(vertice_taken[src] !=0 && vertice_taken[des] !=0){
            graph[src][des] = INT_MAX;
            continue;
        }
        

        printf("\nEdge Taken: %d to %d with weight %d\n",src,des, graph[src][des]);

        graph[src][des] = INT_MAX;
        graph[des][src] = INT_MAX;

        vertice_taken[src] ++;
        vertice_taken[des] ++;
    }
}



void main(){

    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("\nEnter the adjacency matrix of the connected graph");

    int ** graph;

    graph = (int ** ) calloc(vertices, sizeof(int *));

    for(int i =0;i<vertices;i++){
        graph[i] = (int *) calloc(vertices, sizeof(int));
        for(int j =0; j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printMST(graph,vertices);
}