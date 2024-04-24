
#include "GraphT.h"

template<class T>
GraphT<T>::GraphT() {
    //no dynamic memory for unordered map
    //nothing to do!
}

template<class T>
void GraphT<T>::AddVertex(string vertex) {
   vertices.insert(vertex);
}

template<class T>
void GraphT<T>::AddEdge(string vertexA, string vertexB, T weight) {
    if(vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0)
        throw VertexNotFound();

    pair<string, T> edgeWeightPair;
    edgeWeightPair.first = vertexB;
    edgeWeightPair.second = weight;

    graph[vertexA].insert(edgeWeightPair);
}

template<class T>
T* GraphT<T>::GetWeight(string vertexA, string vertexB) {
    //checks to see if vertices are in the graph
    if(vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0)
        throw VertexNotFound();

    //check to see if there is an occurs in the vertexB from vertexA
    if(graph[vertexA].count(vertexB) == 0)
        return nullptr;

    /*
    //get the from vertex (vertically) and get the to vertex (horizontally)
    //like a 2D array
    //pair<string, T> -> p1["string"] -> p1.second
    T* val = new T;
    *val = graph[vertexA][vertexB];
    return val;
     */

    return new T(graph[vertexA][vertexB]);
}

template<class T>
queue<string> GraphT<T>::GetToVertices(string vertex) {
    //check to see if the vertex exists in our unordered set of vertex
    if(vertices.count(vertex) == 0)
        throw VertexNotFound();

    queue<string> adjacentVerticies;

    for(auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        //it is the set containing a pair of string (vertex) and T (it's weight)
        //it->first = vertex
        //it->second = weight

        adjacentVerticies.push(it->first);
    }

    return adjacentVerticies;
}
