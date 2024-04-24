
#ifndef GRAPHT_H
#define GRAPHT_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class VertexNotFound {};
class NoEdgeFound {};

template<class T>
class GraphT {
public:
    GraphT();
    
    // Add vertex to graph
    void AddVertex(string vertex);
    
    // Add edge between verticies
    void AddEdge(string vertexA, string vertexB, T weight);
    
    // Returns weight between two vertices
    T GetWeight(string vertexA, string vertexB);
    
    // Returns queue of vertices connected to vertex
    queue<string> GetToVertices(string vertex);
private:
    unordered_map<string, unordered_map<string, T>> graph;
    unordered_set<string> vertices;
};

#include "GraphT.cpp"

#endif // GRAPHT_H
