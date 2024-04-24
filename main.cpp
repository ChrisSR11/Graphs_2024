#include <iostream>
#include "GraphT.h"
using namespace std;

int main() {
    
    GraphT<int> graph;
    
    graph.AddVertex("Atlanta");
    graph.AddVertex("Austin");
    graph.AddVertex("Chicago");
    graph.AddVertex("Dallas");
    graph.AddVertex("Denver");
    graph.AddVertex("Houston");
    graph.AddVertex("Washington");
    
    graph.AddEdge("Atlanta", "Houston", 800);
    graph.AddEdge("Atlanta", "Washington", 600);

    graph.AddEdge("Austin", "Dallas", 200);
    graph.AddEdge("Austin", "Houston", 160);

    graph.AddEdge("Chicago", "Denver", 1000);
    
    graph.AddEdge("Dallas", "Austin", 200);
    graph.AddEdge("Dallas", "Chicago", 900);
    graph.AddEdge("Dallas", "Denver", 780);

    graph.AddEdge("Denver", "Atlanta", 1400);
    graph.AddEdge("Denver", "Chicago", 1000);

    graph.AddEdge("Houston", "Atlanta", 800);

    graph.AddEdge("Washington", "Atlanta", 600);
    graph.AddEdge("Washington", "Atlanta", 1300);
    
    int* weight = graph.GetWeight("Atlanta", "Houston");
    if (weight != nullptr)
        cout << *weight << endl;
    else
        cout << "No connection!" << endl;
    
    queue<string> adjactentVertices;
    adjactentVertices = graph.GetToVertices("Dallas");
    
    cout << "Dallas is connected to:" << endl;
    while (!adjactentVertices.empty()) {
        cout << "  " << adjactentVertices.front() << endl;
        adjactentVertices.pop();
    }
    
    return 0;
}
