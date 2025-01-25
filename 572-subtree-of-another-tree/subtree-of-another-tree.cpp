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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false; // If the main tree is empty, it can't contain subRoot.
        }

        // Check if the current subtree matches or recurse on left and right subtrees.
        if (isEqual(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isEqual(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true; // Both trees are empty, they are equal.
        }
        if (!root || !subRoot) {
            return false; // One tree is empty, the other is not, they are not equal.
        }
        // Compare the current nodes and their subtrees.
        return (root->val == subRoot->val) &&
               isEqual(root->left, subRoot->left) &&
               isEqual(root->right, subRoot->right);
    }
};
