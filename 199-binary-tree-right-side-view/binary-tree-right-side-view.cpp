#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // To store the rightmost nodes at each level
        if (!root) {
            return ans; // Return empty result if the tree is empty
        }

        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size(); // Number of nodes at the current level

            for (int i = 0; i < level_size; i++) {
                TreeNode* front = q.front();
                q.pop();

                // If this is the last node in the current level, add it to the result
                if (i == level_size - 1) {
                    ans.push_back(front->val);
                }

                // Add left and right children to the queue
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }

        return ans;
    }
};
