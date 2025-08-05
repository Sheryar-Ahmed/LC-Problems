class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        // Post-order traversal: process children first
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Now check if this is a leaf and its value == target
        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }

        return root;
    }
};
