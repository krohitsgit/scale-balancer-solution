#include "scale_balancer.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main() {
    std::unordered_map<std::string, TreeNode*> nodeMap;
    std::map<std::string, std::pair<int, int>> addedWeightMap;
    std::string rootName;
    
    try {
        // Process input file and build tree
        processInputFile("./data/input.txt", rootName, nodeMap);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Balance the tree
    balanceTree(nodeMap[rootName], addedWeightMap);
        
    // Output results
    for (const auto& [node, weights] : addedWeightMap) {
        std::cout << node << "," << weights.first << "," << weights.second << std::endl;
    }
    
    // Clean up memory
    cleanupNodes(nodeMap);
    
    return 0;
}
