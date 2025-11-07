class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (!p || !q) return nullptr;

        // If both p and q are greater than root, LCA is in right subtree
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If both p and q are smaller than root, LCA is in left subtree
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // Otherwise root is the split point and hence the LCA
        return root;
    }
};
