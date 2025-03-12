
#include "Graph.hpp"

Graph::Graph(int numNodes, int maxX, int maxY) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < numNodes; ++i) {
        nodes.push_back(Node(i + 1, rand() % maxX, rand() % maxY));
    }
}

void Graph::addNode(int id, int x, int y) {
    nodes.push_back(Node(id, x, y));
}

void Graph::saveToFile(const std::string& filename) {
    std::ofstream file(filename);

    file << "NAME: " << filename << std::endl;
    file << "TYPE: TSP" << std::endl;
    file << "DIMENSION: " << nodes.size() << std::endl;
    file << "NODE_COORD_SECTION" << std::endl;

    for (const auto& node : nodes) {
        file << node.id << " " << node.x << " " << node.y << std::endl;
    }

    file << "EOF" << std::endl;
    file.close();
}

void Graph::printGraph() const {
    for (const auto& node : nodes) {
        std::cout << "Node " << node.id << ": (" << node.x << ", " << node.y << ")\n";
    }
}

// Calculate Euclidean distance between two nodes
double Graph::distance(const Node& a, const Node& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
