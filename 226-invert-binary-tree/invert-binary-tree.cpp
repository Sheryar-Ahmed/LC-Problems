/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { return dfs(root); }
    TreeNode* dfs(TreeNode* node) {
        if (!node)
            return nullptr;

        // 1. Recurse (DFS)
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        
        // 2. Mutate current node or pointers
        node->left = right; node->right = left;

        return node;
    }
};