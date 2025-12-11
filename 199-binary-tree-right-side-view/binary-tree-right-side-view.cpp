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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans; // 1, 3
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root); // 2, 3
        while (!q.empty()) {
            int size = q.size(); // 2
            vector<int> curr;
            while (size--) {
                TreeNode* top = q.front();
                q.pop(); // 2
                if (top->left) {
                    q.push(top->left);
                    curr.push_back(top->left->val);
                }
                if (top->right) {
                    q.push(top->right);
                    curr.push_back(top->right->val);
                }
            }
            if (curr.size() > 0) {
                ans.push_back(curr[curr.size() - 1]);
            }
        }
        return ans;
    }
};