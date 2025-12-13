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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* prev = nullptr;
        preorder(prev, root);
    }
    void preorder(TreeNode*& prev, TreeNode* curr) {
        if (!curr)
            return;
        if (curr->right)
            preorder(prev, curr->right);
        if (curr->left)
            preorder(prev, curr->left);
        curr->right = prev;
        curr->left = nullptr;
        prev = curr;
    }
};