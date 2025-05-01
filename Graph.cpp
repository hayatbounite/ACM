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
double Graph::distance(const Node& a, const Node& b) const {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void Graph::nearestNeighborTour() {
    int n = nodes.size();
    if (n == 0) return;

    std::vector<bool> visited(n, false);
    tour.clear();
    tour.push_back(0); // Start from node 0
    visited[0] = true;

    for (int i = 0; i < n - 1; ++i) {
        int last = tour.back();
        int next = -1;
        double minDist = std::numeric_limits<double>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double d = distance(nodes[last], nodes[j]);
                if (d < minDist) {
                    minDist = d;
                    next = j;
                }
            }
        }
        tour.push_back(next);
        visited[next] = true;
    }
}

void Graph::twoOpt() {
    bool improved = true;
    int n = tour.size();

    while (improved) {
        improved = false;
        for (int i = 1; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                double before = distance(nodes[tour[i - 1]], nodes[tour[i]]) + distance(nodes[tour[j]], nodes[tour[j + 1]]);
                double after  = distance(nodes[tour[i - 1]], nodes[tour[j]]) + distance(nodes[tour[i]], nodes[tour[j + 1]]);
                if (after < before) {
                    std::reverse(tour.begin() + i, tour.begin() + j + 1);
                    improved = true;
                }
            }
        }
    }
}

double Graph::tourLength() const {
    double length = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        length += distance(nodes[tour[i]], nodes[tour[i + 1]]);
    }
    length += distance(nodes[tour.back()], nodes[tour[0]]);
    return length;
}


void Graph::saveTourToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for tour: " << filename << std::endl;
        return;
    }
    for (int id : tour) {
        file << nodes[id].id << std::endl; // external ID, not index
    }
    file << nodes[tour[0]].id << std::endl; // to complete the tour
    file.close();
}

