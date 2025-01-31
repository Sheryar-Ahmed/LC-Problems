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
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        dfs(root, max_path);
        return max_path;
    }
private:
    int dfs(TreeNode* root, int & max_path){
        if(root == NULL){
            return 0;
        }

        int left = max(dfs(root->left, max_path), 0);
        int right = max(dfs(root->right, max_path), 0);

        int curr_path = root->val+left+right;
        max_path = max(curr_path, max_path);

        return root->val+max(left,right);
    }
};