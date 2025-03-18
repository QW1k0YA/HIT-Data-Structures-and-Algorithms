#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX 11


// 队列的定义和操作，用于广度优先搜索
typedef struct
{
    int items[MAX];
    int front;
    int rear;
}Queue;


typedef struct Stack
{
    int items[MAX];
    int top;
} Stack;

typedef struct Node
{
    int vertex;
    int weight;//后续邻接表转邻接矩阵的时候会用到
    struct Node* next;
} Node;

// 邻接表
typedef struct
{
    Node* adjLists[MAX];
    int numVertices;
    bool visited[MAX];
} GraphList;

typedef struct
{
    int matrix[MAX][MAX];
    int numVertices;
    bool visited[MAX];
} GraphMatrix;


void initStack(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);


void initQueue(Queue* queue);
bool isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);


void initGraphMatrix(GraphMatrix* graph);
void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight);
void printGraphMatrix(GraphMatrix* graph);
void DFSRec1(GraphMatrix* graph, int vertex);


void initGraphList(GraphList* graph);
void addEdgeList(GraphList* graph, int src, int dest, int weight);
void printGraphList(GraphList* graph);


void matrixToList(GraphMatrix* graphMatrix, GraphList* graphList);
void listToMatrix(GraphList* graphList, GraphMatrix* graphMatrix);

// 邻接矩阵非递归深度优先搜索
void DFS_non_recursive(GraphMatrix* graph, int startVertex);

// 邻接矩阵广度优先搜索
void BFS1(GraphMatrix* graph, int startVertex);

// 邻接表递归深度优先搜索
void DFS1(GraphList* graph, int startVertex);

// 邻接表非递归深度优先搜索
void DFS2(GraphList* graph, int startVertex);

// 邻接矩阵深度优先搜索（递归实现）
void DFS_recursive(GraphMatrix* graph, int startVertex);

// 邻接表深度优先搜索（递归实现）
void DFSRec1(GraphMatrix* graph, int startVertex);

// 邻接表深度优先搜索（递归实现）
void DFSRec2(GraphList* graph, int vertex);

// 邻接表非递归深度优先搜索
void DFS2(GraphList* graph, int startVertex);

// 邻接表广度优先搜索
void BFS2(GraphList* graph, int startVertex);

// 用邻接表计算每个顶点的度数
void calculateDegrees(GraphList* graph);


int main()
{
    GraphMatrix graphMatrix;
    GraphList graphList;

    initGraphMatrix(&graphMatrix);
    initGraphList(&graphList);

    addEdgeMatrix(&graphMatrix, 0, 1, 2);
    addEdgeMatrix(&graphMatrix, 0, 2, 3);
    addEdgeMatrix(&graphMatrix, 0, 3, 4);
    addEdgeMatrix(&graphMatrix, 1, 4, 5);
    addEdgeMatrix(&graphMatrix, 1, 3, 3);
    addEdgeMatrix(&graphMatrix, 5, 6, 7);
    addEdgeMatrix(&graphMatrix, 4, 6, 4);
    addEdgeMatrix(&graphMatrix, 2, 3, 5);
    addEdgeMatrix(&graphMatrix, 3, 9, 6);
    addEdgeMatrix(&graphMatrix, 8, 1, 7);
    addEdgeMatrix(&graphMatrix, 5, 7, 4);
    addEdgeMatrix(&graphMatrix, 10, 1, 2);
    addEdgeMatrix(&graphMatrix, 10, 8, 3);


    printf("Matrix:\n");
    printGraphMatrix(&graphMatrix);

    matrixToList(&graphMatrix, &graphList);

    printf("\nconvert to List:\n");
    printGraphList(&graphList);

    GraphMatrix newGraphMatrix;
    initGraphMatrix(&newGraphMatrix);
    listToMatrix(&graphList, &newGraphMatrix);

    printf("\nConverted to a Matrix:\n");
    printGraphMatrix(&newGraphMatrix);

    printf("Graph Matrix:\n");

    printf("DFS Recursive Traversal ");
    DFS_recursive(&graphMatrix, 0);
    printf("\n");

    printf("DFS Iterative Traversal");
    DFS_non_recursive(&graphMatrix, 0);
    printf("\n");

    printf("BFS Traversal");
    BFS1(&graphMatrix, 0);
    printf("\n");

    printf("Graph List:\n");

    printf("DFS Recursive Traversal ");
    DFS1(&graphList, 0);
    printf("\n");

    printf("DFS Iterative Traversal");
    DFS2(&graphList, 0);
    printf("\n");

    printf("BFS Traversal starting  ");
    BFS2(&graphList, 0);
    printf("\n");

    calculateDegrees(&graphList);

    return 0;
}



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
    if (queue->rear == MAX - 1)
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
    graph->numVertices = MAX;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
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
    graph->numVertices = MAX;
    for (int i = 0; i < MAX; i++)
    {
        graph->adjLists[i] = NULL;
    }
}

// 添加边到邻接表图
void addEdgeList(GraphList* graph, int src, int dest, int weight)
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
        printf("V %d: ", i);
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
        for (int j = i + 1; j < graphMatrix->numVertices; j++)
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

