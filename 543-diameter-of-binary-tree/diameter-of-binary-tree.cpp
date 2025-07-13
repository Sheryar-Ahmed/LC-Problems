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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        cal(root, diameter);
        return diameter;
    }
    int cal(TreeNode* root, int& diameter){
        if(!root) return 0;
        int left = cal(root->left, diameter);
        int right = cal(root->right, diameter);
        diameter = max(diameter, left+right); // that's the nodes point
        return 1+max(left, right); // height calculation
    }
};