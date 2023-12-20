#include <iostream>
#include <vector>

// Define the node structure
struct Node {
    int value;
    std::vector<Node*> neighbors;
};

// Function to generate neighbors for a node
std::vector<Node*> generateNeighbors(Node* node) {
    std::vector<Node*> neighbors;

    // Example: Assuming node values represent an integer sequence
    if (node->value > 0) {
        Node* leftNeighbor = new Node{node->value - 1, {}};
        neighbors.push_back(leftNeighbor);
    }

    Node* rightNeighbor = new Node{node->value + 1, {}};
    neighbors.push_back(rightNeighbor);

    return neighbors;
}

int main() {
    Node* initialNode = new Node{5, {}};

    std::vector<Node*> neighbors = generateNeighbors(initialNode);

    std::cout << "Neighbors of " << initialNode->value << " are: ";
    for (Node* neighbor : neighbors) {
        std::cout << neighbor->value << " ";
    }

    // Cleanup memory
    for (Node* neighbor : neighbors) {
        delete neighbor;
    }
    delete initialNode;

    return 0;
}