#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义图的最大顶点数
#define MAX_VERTICES 11

// 邻接矩阵表示图
typedef struct 
{
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;//顶点的数量
    bool visited[MAX_VERTICES]; // 用于标记顶点是否已经被访问
} GraphMatrix;

// 邻接表节点
typedef struct Node 
{
    int vertex;
    int weight;//后续邻接表转邻接矩阵的时候会用到
    struct Node* next;
} Node;

// 邻接表表示图，每个点对应一个链表，链表存储了与该点直接相连的其他顶点
typedef struct 
{
    Node* adjLists[MAX_VERTICES];//用来存储每个顶点对应链表的头指针，adjLists[i]存储了顶点i对应的链表的头指针
    int numVertices;
    bool visited[MAX_VERTICES];//用来标记顶点是否被访问过
} GraphList;

// 栈的定义和操作，邻接表非递归深度优先搜索中用栈来模拟递归
typedef struct Stack 
{
    int items[MAX_VERTICES];//栈仅存放顶点的标号
    int top;
} Stack;

void initStack(Stack* stack) 
{
    stack->top = -1;
}

bool isEmpty(Stack* stack) 
{
    return stack->top == -1;
}

void push(Stack* stack, int value) 
{
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) 
{
    if (!isEmpty(stack)) 
    {
        return stack->items[stack->top--];
    }
    return -1;
}

// 队列的定义和操作，用于广度优先搜索
typedef struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(Queue* queue)
{
    return queue->rear == -1;
}

void enqueue(Queue* queue, int value)
{
    if (queue->rear == MAX_VERTICES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue* queue)
{
    int item;
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty\n");
        item = -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// 初始化邻接矩阵图
void initGraphMatrix(GraphMatrix* graph) 
{
    graph->numVertices = MAX_VERTICES;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            graph->matrix[i][j] = 0; // 初始化所有边的权重为 0
        }
    }
}

// 添加边到邻接矩阵图
void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight) 
{
    graph->matrix[src][dest] = weight;
    graph->matrix[dest][src] = weight; // 无向图，所以边是双向的
}

// 初始化邻接表图
void initGraphList(GraphList* graph) 
{
    graph->numVertices = MAX_VERTICES;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph->adjLists[i] = NULL;
    }
}

// 添加边到邻接表图
void addEdgeList(GraphList* graph, int src, int dest,int weight) 
{
    // 添加边到 src 的邻接表
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight; // 设置权重
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // 添加边到 dest 的邻接表
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->weight = weight; // 设置权重
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 打印邻接矩阵表示的图
void printGraphMatrix(GraphMatrix* graph) 
{
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < graph->numVertices; i++) 
    {
        for (int j = 0; j < graph->numVertices; j++) 
        {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// 打印邻接表表示的图
void printGraphList(GraphList* graph) 
{
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < graph->numVertices; i++) 
    {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) 
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 将邻接矩阵转换为邻接表（有权图）
void matrixToList(GraphMatrix* graphMatrix, GraphList* graphList)
{
    for (int i = 0; i < graphMatrix->numVertices; i++)
    {
        for (int j = i+1; j < graphMatrix->numVertices; j++)
        {
            int weight = graphMatrix->matrix[i][j];
            if (weight != 0)
            {
                addEdgeList(graphList, i, j, weight);
            }
        }
    }
}

// 将邻接表转换为邻接矩阵（有权图）
void listToMatrix(GraphList* graphList, GraphMatrix* graphMatrix)
{
    for (int i = 0; i < graphList->numVertices; i++)
    {
        Node* temp = graphList->adjLists[i];
        while (temp)
        {
            addEdgeMatrix(graphMatrix, i, temp->vertex, temp->weight);
            temp = temp->next;
        }
    }
}

void DFSRec1(GraphMatrix* graph, int vertex)
{
    printf("%d ", vertex);
    graph->visited[vertex] = true;

    // 遍历与当前顶点相邻的顶点
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->matrix[vertex][i] != 0 && !graph->visited[i])
        {
            DFSRec1(graph, i);
        }
    }
}

// 邻接矩阵递归深度优先搜索
void DFS_recursive(GraphMatrix* graph, int startVertex) 
{
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问
    {
        graph->visited[i] = false;
    }

    DFSRec1(graph, startVertex);
}

// 邻接矩阵非递归深度优先搜索
void DFS_non_recursive(GraphMatrix* graph, int startVertex) 
{
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问,如果少了这一步，顶点的状态全是被访问过的，判断语句会出错
    {
        graph->visited[i] = false;
    }

    push(&stack, startVertex);
    graph->visited[startVertex] = true;//只要被要入栈就说明被访问过了

    while (!isEmpty(&stack))
    {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        // 遍历与当前顶点相邻的顶点
        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->matrix[currentVertex][i] != 0 && !graph->visited[i])
            {
                push(&stack, i);
                graph->visited[i] = true;
            }
        }
    }
}

// 邻接矩阵广度优先搜索
void BFS1(GraphMatrix* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问
    {
        graph->visited[i] = false;
    }

    Queue queue;
    initQueue(&queue);

    graph->visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isQueueEmpty(&queue))
    {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->matrix[currentVertex][i] != 0 && !graph->visited[i])
            {
                graph->visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
}


//邻接表递归深度优先搜索
void DFSRec2(GraphList* graph, int vertex) 
{
    printf("%d ", vertex);
    graph->visited[vertex] = true;//从vertex这一点开始搜索，说明vertex这一点已经被访问过

    Node* adjList = graph->adjLists[vertex];//adjList表示顶点vertex对应链表的头结点
    while (adjList != NULL)
    {
        if (!graph->visited[adjList->vertex])//如果adjList->vertex这一点没有被访问过，那就从这一点开始搜索
        {
            DFSRec2(graph, adjList->vertex);
        }
        adjList = adjList->next;//后移
    }
}

//邻接表递归深度优先搜索
void DFS1(GraphList* graph, int startVertex) 
{
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问
    {
        graph->visited[i] = false;
    }

    DFSRec2(graph, startVertex);
}

// 邻接表非递归深度优先搜索
void DFS2(GraphList* graph, int startVertex) 
{
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问,如果少了这一步，顶点的状态全是被访问过的，判断语句会出错
    {
        graph->visited[i] = false;
    }

    push(&stack, startVertex);//先把开始的顶点压入栈中

    while (!isEmpty(&stack)) 
    {
        int currentVertex = pop(&stack);//currentVertex每次都是栈顶元素

        if (!(graph->visited[currentVertex])) //如果没有被访问，就修改为被访问过
        {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = true;
        }

        Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) //除非到达链表的头结点，不然就会按顺序将没有被访问过的节点压入栈中
        {
            if (!(graph->visited[adjList->vertex])) 
            {
                push(&stack, adjList->vertex);
            }
            adjList = adjList->next;
        }
    }
}

//邻接表广度优先搜索
void BFS2(GraphList* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//先初始化为未访问
    {
        graph->visited[i] = false;
    }

    Queue queue;
    initQueue(&queue);

    graph->visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isQueueEmpty(&queue))
    {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = true;
                enqueue(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// 用邻接表计算每个顶点的度数
void calculateDegrees(GraphList* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        int degree = 0;
        Node* temp = graph->adjLists[i];
        while (temp)
        {
            degree++;
            temp = temp->next;
        }
        printf("vertex %d ,degree: %d\n", i, degree);
    }
}


int main() 
{
    GraphMatrix graphMatrix;
    GraphList graphList;

    // 初始化邻接矩阵和邻接表
    initGraphMatrix(&graphMatrix);
    initGraphList(&graphList);

    // 添加边到矩阵中
    addEdgeMatrix(&graphMatrix, 0, 1, 3);
    addEdgeMatrix(&graphMatrix, 0, 2, 4);
    addEdgeMatrix(&graphMatrix, 0, 3, 5);
    addEdgeMatrix(&graphMatrix, 1, 4, 5);
    addEdgeMatrix(&graphMatrix, 1, 3, 3);
    addEdgeMatrix(&graphMatrix, 5, 6, 8);
    addEdgeMatrix(&graphMatrix, 4, 6, 4);
    addEdgeMatrix(&graphMatrix, 2, 3, 5);
    addEdgeMatrix(&graphMatrix, 3, 9, 7);
    addEdgeMatrix(&graphMatrix, 8, 1, 6);
    addEdgeMatrix(&graphMatrix, 5, 7, 4);
    addEdgeMatrix(&graphMatrix, 10, 1, 2);
    addEdgeMatrix(&graphMatrix, 10, 8, 3);

    // 添加边到链表
    /*addEdgeList(&graphList, 0, 1, 3);
    addEdgeList(&graphList, 0, 2,4);
    addEdgeList(&graphList, 0, 3,5);
    addEdgeList(&graphList, 1, 4,5);
    addEdgeList(&graphList, 1, 3,3);
    addEdgeList(&graphList, 5, 6,8);
    addEdgeList(&graphList, 4, 6,4);
    addEdgeList(&graphList, 2, 3,5);
    addEdgeList(&graphList, 3, 9,7);
    addEdgeList(&graphList, 8, 1,6);
    addEdgeList(&graphList, 5, 7,4);
    addEdgeList(&graphList, 10, 1,2);
    addEdgeList(&graphList, 10, 8,3);*/

    // 打印图的表示
    printf("Original Adjacency Matrix:\n");
    printGraphMatrix(&graphMatrix);

    // 将邻接矩阵转换为邻接表
    matrixToList(&graphMatrix, &graphList);

    // 打印转换后的邻接表
    printf("\nConverted Adjacency List:\n");
    printGraphList(&graphList);

    // 将邻接表转换回邻接矩阵
    GraphMatrix newGraphMatrix;
    initGraphMatrix(&newGraphMatrix);
    listToMatrix(&graphList, &newGraphMatrix);

    // 打印转换回的邻接矩阵
    printf("\nConverted Back to Adjacency Matrix:\n");
    printGraphMatrix(&newGraphMatrix);

    printf("Graph Matrix:\n");

    //邻接矩阵深度优先搜索递归算法
    printf("DFS Recursive Traversal starting from vertex 0: ");
    DFS_recursive(&graphMatrix, 0);
    printf("\n");

    //邻接矩阵深度优先搜索非递归算法
    printf("DFS Iterative Traversal starting from vertex 0: ");
    DFS_non_recursive(&graphMatrix, 0);
    printf("\n");

    //邻接矩阵广度优先搜索算法
    printf("BFS Traversal starting from vertex 0: ");
    BFS1(&graphMatrix, 0);
    printf("\n");

    printf("Graph List:\n");

    //邻接表深度优先搜索递归算法
    printf("DFS Recursive Traversal starting from vertex 0: ");
    DFS1(&graphList, 0);
    printf("\n");

    //邻接表深度优先搜索非递归算法
    printf("DFS Iterative Traversal starting from vertex 0: ");
    DFS2(&graphList, 0);
    printf("\n");

    //邻接表广度优先搜索算法
    printf("BFS Traversal starting from vertex 0: ");
    BFS2(&graphList, 0);
    printf("\n");

    //用邻接表计算每个顶点的度
    calculateDegrees(&graphList);

    return 0;
}
