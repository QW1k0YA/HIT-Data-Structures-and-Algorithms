#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX 11


// ���еĶ���Ͳ��������ڹ����������
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
    int weight;//�����ڽӱ�ת�ڽӾ����ʱ����õ�
    struct Node* next;
} Node;

// �ڽӱ�
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

// �ڽӾ���ǵݹ������������
void DFS_non_recursive(GraphMatrix* graph, int startVertex);

// �ڽӾ�������������
void BFS1(GraphMatrix* graph, int startVertex);

// �ڽӱ�ݹ������������
void DFS1(GraphList* graph, int startVertex);

// �ڽӱ�ǵݹ������������
void DFS2(GraphList* graph, int startVertex);

// �ڽӾ�����������������ݹ�ʵ�֣�
void DFS_recursive(GraphMatrix* graph, int startVertex);

// �ڽӱ���������������ݹ�ʵ�֣�
void DFSRec1(GraphMatrix* graph, int startVertex);

// �ڽӱ���������������ݹ�ʵ�֣�
void DFSRec2(GraphList* graph, int vertex);

// �ڽӱ�ǵݹ������������
void DFS2(GraphList* graph, int startVertex);

// �ڽӱ�����������
void BFS2(GraphList* graph, int startVertex);

// ���ڽӱ����ÿ������Ķ���
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

// ��ʼ���ڽӾ���ͼ
void initGraphMatrix(GraphMatrix* graph)
{
    graph->numVertices = MAX;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph->matrix[i][j] = 0; // ��ʼ�����бߵ�Ȩ��Ϊ 0
        }
    }
}

// ��ӱߵ��ڽӾ���ͼ
void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight)
{
    graph->matrix[src][dest] = weight;
    graph->matrix[dest][src] = weight; // ����ͼ�����Ա���˫���
}

// ��ʼ���ڽӱ�ͼ
void initGraphList(GraphList* graph)
{
    graph->numVertices = MAX;
    for (int i = 0; i < MAX; i++)
    {
        graph->adjLists[i] = NULL;
    }
}

// ��ӱߵ��ڽӱ�ͼ
void addEdgeList(GraphList* graph, int src, int dest, int weight)
{
    // ��ӱߵ� src ���ڽӱ�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight; // ����Ȩ��
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // ��ӱߵ� dest ���ڽӱ�
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->weight = weight; // ����Ȩ��
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// ��ӡ�ڽӾ����ʾ��ͼ
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

// ��ӡ�ڽӱ��ʾ��ͼ
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

// ���ڽӾ���ת��Ϊ�ڽӱ���Ȩͼ��
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

// ���ڽӱ�ת��Ϊ�ڽӾ�����Ȩͼ��
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

    // �����뵱ǰ�������ڵĶ���
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->matrix[vertex][i] != 0 && !graph->visited[i])
        {
            DFSRec1(graph, i);
        }
    }
}

// �ڽӾ���ݹ������������
void DFS_recursive(GraphMatrix* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����
    {
        graph->visited[i] = false;
    }

    DFSRec1(graph, startVertex);
}

// �ڽӾ���ǵݹ������������
void DFS_non_recursive(GraphMatrix* graph, int startVertex)
{
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����,���������һ���������״̬ȫ�Ǳ����ʹ��ģ��ж��������
    {
        graph->visited[i] = false;
    }

    push(&stack, startVertex);
    graph->visited[startVertex] = true;//ֻҪ��Ҫ��ջ��˵�������ʹ���

    while (!isEmpty(&stack))
    {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        // �����뵱ǰ�������ڵĶ���
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

// �ڽӾ�������������
void BFS1(GraphMatrix* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����
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


//�ڽӱ�ݹ������������
void DFSRec2(GraphList* graph, int vertex)
{
    printf("%d ", vertex);
    graph->visited[vertex] = true;//��vertex��һ�㿪ʼ������˵��vertex��һ���Ѿ������ʹ�

    Node* adjList = graph->adjLists[vertex];//adjList��ʾ����vertex��Ӧ�����ͷ���
    while (adjList != NULL)
    {
        if (!graph->visited[adjList->vertex])//���adjList->vertex��һ��û�б����ʹ����Ǿʹ���һ�㿪ʼ����
        {
            DFSRec2(graph, adjList->vertex);
        }
        adjList = adjList->next;//����
    }
}

//�ڽӱ�ݹ������������
void DFS1(GraphList* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����
    {
        graph->visited[i] = false;
    }

    DFSRec2(graph, startVertex);
}

// �ڽӱ�ǵݹ������������
void DFS2(GraphList* graph, int startVertex)
{
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����,���������һ���������״̬ȫ�Ǳ����ʹ��ģ��ж��������
    {
        graph->visited[i] = false;
    }

    push(&stack, startVertex);//�Ȱѿ�ʼ�Ķ���ѹ��ջ��

    while (!isEmpty(&stack))
    {
        int currentVertex = pop(&stack);//currentVertexÿ�ζ���ջ��Ԫ��

        if (!(graph->visited[currentVertex])) //���û�б����ʣ����޸�Ϊ�����ʹ�
        {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = true;
        }

        Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) //���ǵ��������ͷ��㣬��Ȼ�ͻᰴ˳��û�б����ʹ��Ľڵ�ѹ��ջ��
        {
            if (!(graph->visited[adjList->vertex]))
            {
                push(&stack, adjList->vertex);
            }
            adjList = adjList->next;
        }
    }
}

//�ڽӱ�����������
void BFS2(GraphList* graph, int startVertex)
{
    for (int i = 0; i < graph->numVertices; i++)//�ȳ�ʼ��Ϊδ����
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

// ���ڽӱ����ÿ������Ķ���
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

