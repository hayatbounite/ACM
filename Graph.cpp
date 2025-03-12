#include "Graph.hpp"

Graph::Graph(int numNodes, int maxX, int maxY) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < numNodes; ++i) {
        nodes.emplace_back(i + 1, rand() % maxX, rand() % maxY);
    }
}

void Graph::addNode(int id, int x, int y) {
    nodes.emplace_back(id, x, y);
}

void Graph::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    file << "NAME: " << filename << "\nTYPE: TSP\nDIMENSION: " << nodes.size() << "\nNODE_COORD_SECTION\n";
    for (const auto& node : nodes) {
        file << node.id << " " << node.x << " " << node.y << std::endl;
    }
    file << "EOF" << std::endl;
}

void Graph::printGraph() const {
    for (const auto& node : nodes) {
        std::cout << "Node " << node.id << ": (" << node.x << ", " << node.y << ")\n";
    }
}
double Graph::distance(const Node& a, const Node& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
