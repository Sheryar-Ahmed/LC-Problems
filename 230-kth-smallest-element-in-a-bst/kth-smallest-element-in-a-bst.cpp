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
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal and do that upto k,return the kth element
        vector<int> sorted;
        inorder(root, sorted);
        return sorted[k-1];
    }
    void inorder(TreeNode* root, vector<int>& sorted){
        if(!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right,sorted);
    }
};