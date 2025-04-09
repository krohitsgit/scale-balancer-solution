#include "scale_balancer.h"
#include <iostream>
#include <fstream>
#include <sstream>

TreeNode* getNode(const std::string& s, std::unordered_map<std::string, TreeNode*>& nodeMap) {
    // If it's a number, create a leaf node
    if (!s.empty() && isdigit(s[0])) {
        return new TreeNode(stoi(s));
    }
    
    // Otherwise create or retrieve a named node
    auto it = nodeMap.find(s);
    if (it == nodeMap.end()) {
        nodeMap[s] = new TreeNode(1, s);
    }
    return nodeMap[s];
}

int balanceTree(TreeNode* node, std::map<std::string, std::pair<int, int>>& addedWeightMap) {
    if (!node) return 0;
    
    int leftSum = balanceTree(node->left, addedWeightMap);
    int rightSum = balanceTree(node->right, addedWeightMap);
    
    // Initialize with zeros
    int leftExtra = 0, rightExtra = 0;
    
    if (leftSum < rightSum) {
        leftExtra = rightSum - leftSum;
    } else if (rightSum < leftSum) {
        rightExtra = leftSum - rightSum;
    }
    
    // Record weight adjustments for named nodes
    if (!node->nodename.empty()) {
        addedWeightMap[node->nodename] = {leftExtra, rightExtra};
    }
    
    // Return total weight including any balancing weights
    return node->val + leftSum + rightSum + leftExtra + rightExtra;
}

void processInputFile(const std::string& filename, std::string& rootName, 
                     std::unordered_map<std::string, TreeNode*>& nodeMap) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("Unable to open input file: " + filename);
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(fin, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Skip comment lines that start with #
        if (line[0] == '#') {
            continue;
        }
        
        std::stringstream ss(line);
        std::string parent, left, right;
        
        std::getline(ss, parent, ',');
        std::getline(ss, left, ',');
        std::getline(ss, right, ',');
        
        if (firstLine) {
            rootName = parent;
            firstLine = false;
        }
        
        TreeNode* parentNode = getNode(parent, nodeMap);
        parentNode->left = getNode(left, nodeMap);
        parentNode->right = getNode(right, nodeMap);
    }
    
    fin.close();
}

void cleanupNodes(std::unordered_map<std::string, TreeNode*>& nodeMap) {
    for (auto& [name, node] : nodeMap) {
        delete node;
    }
    nodeMap.clear();
}
