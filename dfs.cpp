#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;

// Structure to represent a node in the linked list
struct Node {
    int vertex;
    Node* next;
};

// Function to create a new node in the linked list
Node* newNode(int vertex) {
    Node* temp = new Node;
    temp->vertex = vertex;
    temp->next = NULL;
    return temp;
}

// Function to add an edge to the adjacency list represented by a linked list
void addEdge(Node* adjList[], int head, int pvertex) {
    Node* tnode = newNode(pvertex);
    tnode->next = adjList[head];
    adjList[head] = tnode;
}

// Function to perform DFS traversal of a graph and print each possible path from startVertex to endVertex
void DFS(Node* adjList[], int startVertex, int endVertex, bool visited[], stack<int>& pathStack) {
    visited[startVertex] = true;
    pathStack.push(startVertex);

    if (startVertex == endVertex) {
        stack<int> tempStack = pathStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    } else {
        for (Node* neighbor = adjList[startVertex]; neighbor != NULL; neighbor = neighbor->next) {
            if (!visited[neighbor->vertex]) {
                DFS(adjList, neighbor->vertex, endVertex, visited, pathStack);
            }
        }
    }

    visited[startVertex] = false;
    pathStack.pop();
}

int main() {
	cout<<"Finding Path in Maze using DFS technique of graphs and stack"<<endl;
    //graph's total vertices & edges
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // array of pointers for nodes to represent adjacency list
    Node* adjList[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = NULL;
    }

    // Input edges
    for (int j = 0; j < numEdges; j++) {
        int first, sec;
        cout << "Enter start vertex for edge " << j + 1 << ": ";
        cin >> first;
        cout << "Enter end vertex for edge " << j + 1 << ": ";
        cin >> sec;
        addEdge(adjList, first, sec);
    }

    // Array for visited vertices
    bool visited[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    // Start and end vertices of maze
    int startVertex, endVertex; 
	cout << "Enter the start of maze: ";
	cin >> startVertex;
	cout << "Enter the end of maze: ";
	cin >> endVertex;
	
	//searching the paths
    stack<int> pathStack;
    DFS(adjList, startVertex, endVertex, visited, pathStack);

    return 0;
}

