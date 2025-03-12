#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>   // for rand()
#include <ctime>     // for seeding random
#include <cmath>     // for distance calculation
struct Node {
    int id;
    int x;
    int y;

    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

class Graph {
private:
    std::vector<Node> nodes;

public:
    /**
     * @brief Constructs a graph with randomly generated nodes.
     * @param numNodes Number of nodes to generate.
     * @param maxX Maximum x-coordinate value.
     * @param maxY Maximum y-coordinate value.
     */
    Graph(int numNodes, int maxX = 100, int maxY = 100);

     /**
     * @brief Manually adds a node to the graph.
     * @param id Node ID.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     */
    void addNode(int id, int x, int y);

     /**
     * @brief Saves the graph to a file in TSP format.
     * @param filename Name of the file to save.
     */
    void saveToFile(const std::string& filename);

     /**
     * @brief Prints the graph nodes to the console.
     */
    void printGraph() const;

    /**
     * @brief Computes the Euclidean distance between two nodes.
     * @param a First node.
     * @param b Second node.
     * @return Euclidean distance between a and b.
     */
    double distance(const Node& a, const Node& b);
};

#endif // GRAPH_HPP
