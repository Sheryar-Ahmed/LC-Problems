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
 */class Solution {
public:
    unordered_map<TreeNode*, int> memo;

    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];

        int robNow = root->val;
        if (root->left) {
            robNow += rob(root->left->left);
            robNow += rob(root->left->right);
        }
        if (root->right) {
            robNow += rob(root->right->left);
            robNow += rob(root->right->right);
        }

        int skipNow = rob(root->left) + rob(root->right);

        return memo[root] = max(robNow, skipNow);
    }
};
