/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countGoodNodes(TreeNode* root, int maxSoFar) {
        if (!root) return 0;
        
        int good = (root->val >= maxSoFar) ? 1 : 0;
        maxSoFar = max(maxSoFar, root->val);
        
        good += countGoodNodes(root->left, maxSoFar);
        good += countGoodNodes(root->right, maxSoFar);
        
        return good;
    }
    
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return countGoodNodes(root, root->val);
    }
};