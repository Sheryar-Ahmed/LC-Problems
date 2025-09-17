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
    TreeNode* prev = nullptr; // we know inorder must be strictly increasing.
public:
    bool isValidBST(TreeNode* root) { return inorder(root); }
    bool inorder(TreeNode* root) {
        if (!root)
            return true;
        if (!inorder(root->left)) {
            return false;
        }
        if (prev && root->val <= prev->val)
            return false;
        prev = root;
        if (!inorder(root->right)) {
            return false;
        }
        return true;
    }
};