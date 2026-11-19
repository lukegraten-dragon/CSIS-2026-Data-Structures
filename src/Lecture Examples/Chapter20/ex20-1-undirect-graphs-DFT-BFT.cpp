#include <iostream>
#include <fstream>

using namespace std ;

// Queue class for BFS operations
class queue {
private:
    int* arr;  // Array to store queue elements
    int front; // Front index
    int rear;  // Rear index
    int capacity; // Maximum size of the queue

public:
    queue(int size) ; // Constructor to initialize the queue
    ~queue() ;        // Destructor to clean up memory
    void enqueue(int value) ; // Add an element to the queue
    int dequeue() ; // Remove an element from the queue
    bool isEmpty() const ; // Check if the queue is empty
    bool isFull() const ; // Check if the queue is full
} ;

queue::queue(int size) {
    capacity = size ; // Initialize the capacity
    arr = new int[capacity] ; // Create array to hold elements
    front = 0 ; // Initialize front pointer
    rear = -1 ; // Initialize rear pointer
}

queue::~queue() {
    delete[] arr ; // Free memory allocated for the queue
}

void queue::enqueue(int value) {
    if (isFull()) { // Check if the queue is full
        cout << "Queue is full." << endl ;
        return ;
    }
    rear = (rear + 1) % capacity ; // Circular increment of rear pointer
    arr[rear] = value ; // Add the element to the rear
}

int queue::dequeue() {
    if (isEmpty()) { // Check if the queue is empty
        cout << "Queue is empty." << endl ;
        return -1 ;
    }
    int value = arr[front] ; // Get the front element
    front = (front + 1) % capacity ; // Circular increment of front pointer
    return value ; // Return the dequeued element
}

bool queue::isEmpty() const {
    return (rear + 1) % capacity == front ; // Check if queue is empty
}

bool queue::isFull() const {
    return (rear + 2) % capacity == front ; // Check if queue is full
}

// Graph class
class graph {
private:
    int maxSize;    // Maximum number of vertices
    int gSize;      // Current number of vertices in the graph
    int** adjMatrix; // Adjacency matrix to represent the graph

    void dft(int v, bool visited[]); // Helper function for Depth First Traversal (DFS)

public:
    graph(int size) ; // Constructor
    ~graph() ; // Destructor

    void createGraph() ; // Read graph from a file ("input.txt")
    void addEdge(int u, int v) ; // Add edge between vertices u and v
    void printGraph() const ; // Print the adjacency matrix

    void depthFirstTraversal() ; // Perform Depth First Traversal (DFS)
    void breadthFirstTraversal() ; // Perform Breadth First Traversal (BFS)

    bool isEmpty() const ; // Check if the graph is empty
    void clearGraph() ;    // Clear the graph and reset adjacency matrix
} ;

graph::graph(int size) {
    maxSize = size ; // Set the maximum number of vertices
    gSize = 0 ; // Initialize current size to 0

    // Allocate memory for adjacency matrix
    adjMatrix = new int*[maxSize] ;
    for (int i = 0; i < maxSize; i++) {
        adjMatrix[i] = new int[maxSize] ;
        for (int j = 0; j < maxSize; j++) {
            adjMatrix[i][j] = 0 ; // Initialize all edges to 0
        }
    }
}

graph::~graph() {
    for (int i = 0; i < maxSize; i++) {
        delete[] adjMatrix[i] ; // Free rows of adjacency matrix
    }
    delete[] adjMatrix ; // Free the entire adjacency matrix
}

bool graph::isEmpty() const {
    return (gSize == 0) ; // Return true if the graph has no vertices
}

void graph::clearGraph() {
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            adjMatrix[i][j] = 0 ; // Reset all edges to 0
        }
    }
    gSize = 0 ; // Reset the current size of the graph to 0
    cout << "Graph has been cleared." << endl ;
}

void graph::createGraph() {
    // Open the input file "input.txt"
    ifstream infile("input-fig20-6.txt") ;
    // The first line of input specifies the number of vertices in the graph. 
    // The first entry in the remaining lines specifies the vertex, and all of 
    // the remaining entries in the line (except the last) specify the vertices 
    // that are adjacent to the vertex. Each line ends with the number −999.

    if (!infile) {
        // Error handling if the file cannot be opened
        cout << "Cannot open input file: input.txt" << endl ;
        return ;
    }

    // Read the number of vertices (gSize) from the file
    infile >> gSize ;

    if (gSize > maxSize) {
        // Error handling if the input graph size exceeds maxSize
        cout << "Graph size exceeds maximum allowed size." << endl ;
        infile.close() ;
        return ;
    }

    int vertex, adjacentVertex ;

    // Read each line of the file to construct the graph
    while (infile >> vertex) {
        if (vertex < 0 || vertex >= gSize) {
            // Error handling for invalid vertices
            cout << "Invalid vertex: " << vertex << endl ;
            continue ;
        }

        // Read adjacent vertices for the current vertex
        while (infile >> adjacentVertex && adjacentVertex != -999) {
            if (adjacentVertex < 0 || adjacentVertex >= gSize) {
                // Error handling for invalid adjacent vertices
                cout << "Invalid adjacent vertex: " << adjacentVertex << endl ;
                continue ;
            }

            // Add an edge between the current vertex and the adjacent vertex
            addEdge(vertex, adjacentVertex) ;
        }
    }

    infile.close() ; // Close the input file
}

void graph::addEdge(int u, int v) {
    if (u >= 0 && u < gSize && v >= 0 && v < gSize) {
        adjMatrix[u][v] = 1 ; // Set adjacency matrix entry to 1
        adjMatrix[v][u] = 1 ; // Since the graph is undirected, set both [u][v] and [v][u]
    }
}

void graph::printGraph() const {
    cout << "Adjacency Matrix:" << endl ;
    for (int i = 0; i < gSize; i++) { // Only print up to gSize
        for (int j = 0; j < gSize; j++) { // Only print up to gSize
            cout << adjMatrix[i][j] << " " ;
        }
        cout << endl ;
    }
}

void graph::dft(int v, bool visited[]) {
    visited[v] = true ; // Mark the vertex as visited
    cout << v << " " ; // Print the visited vertex

    for (int i = 0; i < gSize; i++) { // Check all vertices up to gSize
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            dft(i, visited) ; // Recursively visit connected vertices
        }
    }
}

void graph::depthFirstTraversal() {
    bool* visited = new bool[gSize] ; // Array to track visited vertices
    for (int i = 0; i < gSize; i++) {
        visited[i] = false ; // Initialize all vertices as unvisited
    }

    cout << "Depth First Traversal: " ;
    for (int i = 0; i < gSize; i++) {
        if (!visited[i]) {
            dft(i, visited) ; // Start DFS at each unvisited vertex
        }
    }
    cout << endl ;

    delete[] visited ; // Free the visited array
}

void graph::breadthFirstTraversal() {
    bool* visited = new bool[gSize] ; // Array to track visited vertices
    for (int i = 0; i < gSize; i++) {
        visited[i] = false ; // Initialize all vertices as unvisited
    }

    cout << "Breadth First Traversal: " ;
    queue q(gSize) ; // Queue for BFS

    for (int i = 0; i < gSize; i++) {
        if (!visited[i]) {
            q.enqueue(i) ; // Start BFS at each unvisited vertex
            visited[i] = true ;

            while (!q.isEmpty()) {
                int v = q.dequeue() ; // Dequeue a vertex
                cout << v << " " ; // Visit the vertex

                for (int j = 0; j < gSize; j++) {
                    if (adjMatrix[v][j] == 1 && !visited[j]) {
                        q.enqueue(j) ; // Enqueue adjacent vertices
                        visited[j] = true ; // Mark them as visited
                    }
                }
            }
        }
    }
    cout << endl ;

    delete[] visited ; // Free the visited array
}

int main() {
    int size = 10 ; // Define maximum graph size
    graph g(size) ; // Create graph

    g.createGraph() ; // Read graph from "input.txt"

    if (g.isEmpty()) {
        cout << "The graph is empty." << endl ;
    } else {
        cout << "The graph is not empty." << endl ;
    }

    g.printGraph() ; // Print the adjacency matrix

    g.depthFirstTraversal() ; // Perform Depth First Traversal
    g.breadthFirstTraversal() ; // Perform Breadth First Traversal

    g.clearGraph() ; // Clear the graph

    if (g.isEmpty()) {
        cout << "The graph is now empty after clearing." << endl ;
    }

    return 0 ;
}
