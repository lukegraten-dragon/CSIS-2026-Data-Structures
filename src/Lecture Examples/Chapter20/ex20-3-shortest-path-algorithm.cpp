#include <iostream>
#include <fstream>
#include <cfloat> // For DBL_MAX
#include <iomanip> // For output formatting

using namespace std ;

class weightedGraph {
public:
    weightedGraph(int size = 0) ; // Constructor
    ~weightedGraph() ;           // Destructor

    void createWeightedGraph() ; // Create the graph with weights
    void shortestPath(int vertex) ; // Find shortest path from vertex
    void printShortestDistance(int vertex) ; // Print shortest distances
    void printGraph() const ; // Print the adjacency matrix and weights

protected:
    int maxSize ;           // Maximum number of vertices
    int gSize ;             // Current number of vertices
    double** weights ;      // Weight matrix
    double* smallestWeight ; // Smallest weight from source vertex
} ;

// Constructor
weightedGraph::weightedGraph(int size) {
    maxSize = size ;
    gSize = 0 ;

    // Allocate memory for weight matrix
    weights = new double*[maxSize] ;
    for (int i = 0; i < maxSize; i++) {
        weights[i] = new double[maxSize] ;
        for (int j = 0; j < maxSize; j++) {
            weights[i][j] = (i == j) ? 0 : DBL_MAX ; // Use DBL_MAX for infinity
        }
    }

    smallestWeight = new double[maxSize] ;
}

// Destructor
weightedGraph::~weightedGraph() {
    for (int i = 0; i < maxSize; i++) {
        delete[] weights[i] ;
    }
    delete[] weights ;
    delete[] smallestWeight ;
}

// Create weighted graph
void weightedGraph::createWeightedGraph() {
    ifstream infile("input-fig20-7-2.txt") ;

    int vertex ;
    int adjacentVertex ;

    if (!infile) {
        cout << "Cannot open the input file" << endl ;
        return ;
    }

    infile >> gSize ;

    // Initialize weights matrix to DBL_MAX (infinity)
    for (int i = 0; i < gSize; i++) {
        for (int j = 0; j < gSize; j++) {
            weights[i][j] = DBL_MAX ;
        }
    }

    // Skip the fisrt part of the input file (graph) until meeting '@'
    char ch ;
    while (infile >> ch) {
        if (ch == '@') {
            break ; // Stop reading into arr1 when '@' is encountered
        }

        infile.unget() ; // Put back the character for integer parsing
        infile >> ch ;
    }

    double weight ;

    // Read adjacency and weight data
    infile >> vertex ;
    while (infile) {
        infile >> adjacentVertex ;
        while (adjacentVertex != -999) {
            infile >> weight ;
            weights[vertex][adjacentVertex] = weight ;
            //cout << "weights[" << vertex << "][" << adjacentVertex << "] = " << weight << endl ;
            infile >> adjacentVertex ;
        }
        infile >> vertex ;
    }

    infile.close() ;
}

// Shortest path using Dijkstra's algorithm
void weightedGraph::shortestPath(int vertex) {
    // Initialize smallestWeight with direct weights from the source vertex
    for (int j = 0; j < gSize; j++) {
        smallestWeight[j] = weights[vertex][j] ;
    }

    // Boolean array to track vertices for which the shortest path has been found
    bool* weightFound = new bool[gSize] ;
    for (int j = 0; j < gSize; j++) {
        weightFound[j] = false ;
    }

    // Mark the source vertex as processed
    weightFound[vertex] = true ;
    smallestWeight[vertex] = 0 ;

    // Process each vertex
    for (int i = 0; i < gSize - 1; i++) {
        double minWeight = DBL_MAX ;
        int v = -1 ;

        // Find the vertex with the smallest distance that hasn't been processed
        for (int j = 0; j < gSize; j++) {
            if (!weightFound[j] && smallestWeight[j] < minWeight) {
                v = j ;
                minWeight = smallestWeight[v] ;
            }
        }

        if (v == -1) {
            // All reachable vertices have been processed
            break ;
        }

        // Mark the vertex as processed
        weightFound[v] = true ;

        // Update distances for adjacent vertices
        for (int j = 0; j < gSize; j++) {
            if (!weightFound[j] && weights[v][j] < DBL_MAX) {
                if (minWeight + weights[v][j] < smallestWeight[j]) {
                    smallestWeight[j] = minWeight + weights[v][j] ;
                }
            }
        }
    }

    delete[] weightFound ;
}

// Print shortest distances
void weightedGraph::printShortestDistance(int vertex) {
    cout << "Source Vertex: " << vertex << "\n" ;
    cout << "Shortest Distance from Source to each Vertex.\n" ;
    cout << "Vertex  Shortest_Distance\n" ;

    for (int i = 0; i < gSize; i++) {
        cout << setw(6) << i << setw(18) ;
        if (smallestWeight[i] == DBL_MAX) {
            cout << "INF\n" ;
        } else {
            cout << smallestWeight[i] << "\n" ;
        }
    }
}

// Print the graph (adjacency matrix and weights) with improved formatting
void weightedGraph::printGraph() const {
    cout << "Graph weight matrix:\n" ;
    cout << setw(6) << " " ;
    for (int j = 0; j < gSize; j++) {
        cout << setw(8) << j ;
    }
    cout << endl ;

    for (int i = 0; i < gSize; i++) {
        cout << setw(6) << i ;
        for (int j = 0; j < gSize; j++) {
            if (weights[i][j] == DBL_MAX) {
                cout << setw(8) << "INF" ;
            } else {
                cout << setw(8) << weights[i][j] ;
            }
        }
        cout << endl ;
    }
}

int main() {
    weightedGraph g(5) ; // Create a graph with a maximum of 5 vertices
    g.createWeightedGraph() ; // Load graph data from input file
    g.printGraph() ; // Print the weight matrix

    int sourceVertex = 0 ;
    g.shortestPath(sourceVertex) ; // Compute shortest paths from vertex 0
    g.printShortestDistance(sourceVertex) ; // Print shortest distances

    return 0 ;
}
