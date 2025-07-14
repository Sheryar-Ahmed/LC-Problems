class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
        if (!root) {
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
// The left subtree is constrained by the maximum value being the parent node's value.
// The right subtree is constrained by the minimum value being the parent node's value.
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};