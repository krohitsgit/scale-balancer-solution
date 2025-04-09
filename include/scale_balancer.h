#pragma once

#include <string>
#include <unordered_map>
#include <map>
#include <utility>

/**
 * TreeNode structure representing a node in the binary tree
 */
struct TreeNode {
    int val;
    std::string nodename;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int v, std::string s = "") : val(v), nodename(s), left(nullptr), right(nullptr) {}
    
    // Destructor
    ~TreeNode() = default;
};

/**
 * Gets a tree node
 */
TreeNode* getNode(const std::string& s, std::unordered_map<std::string, TreeNode*>& nodeMap);

/**
 * Balances the tree starting from the given node
 */
int balanceTree(TreeNode* node, std::map<std::string, std::pair<int, int>>& addedWeightMap);

/**
 * Process input file and build tree
 */
void processInputFile(const std::string& filename, std::string& rootName, 
                      std::unordered_map<std::string, TreeNode*>& nodeMap);

/**
 * Clean up memory allocated for tree nodes
 */
void cleanupNodes(std::unordered_map<std::string, TreeNode*>& nodeMap);
