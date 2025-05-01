#include "Graph.hpp"
#include <chrono>

using namespace std;
int main() {
   Graph myGraph(10); // Generate a graph with 10 random nodes
    //cout << "Generated Graph Nodes:\n";
    //myGraph.printGraph();

    //myGraph.saveToFile("graph.tsp");

    Graph g(50); // Create 50 random nodes

    auto startNN = chrono::high_resolution_clock::now();
    g.nearestNeighborTour();
    auto endNN = chrono::high_resolution_clock::now();
    double nnLength = g.tourLength();
    cout << "NN tour length: " << nnLength << endl;
    cout << "NN time: " << chrono::duration<double>(endNN - startNN).count() << " seconds" << endl;

    auto startOpt = chrono::high_resolution_clock::now();
    g.twoOpt();
    auto endOpt = chrono::high_resolution_clock::now();
    double optLength = g.tourLength();
    cout << "2-Opt improved length: " << optLength << endl;
    cout << "2-Opt time: " << chrono::duration<double>(endOpt - startOpt).count() << " seconds" << endl;

    g.saveTourToFile("tour.txt");

    return 0;
}
