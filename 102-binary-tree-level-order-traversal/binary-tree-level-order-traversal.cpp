#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // To store the result
        if (!root) {
            return ans; // Return empty result if the tree is empty
        }

        queue<TreeNode*> q; // Queue to store nodes for BFS
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size(); // Number of nodes at the current level
            vector<int> level;         // Vector to store the current level's nodes

            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val); // Add the current node's value to the level

                // Push left and right children if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            ans.push_back(level); // Add the current level to the result
        }

        return ans;
    }
};
