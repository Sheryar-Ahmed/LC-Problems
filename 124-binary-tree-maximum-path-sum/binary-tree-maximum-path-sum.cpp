class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Postorder: left, right, node
        int leftGain = max(0, dfs(root->left));   // Ignore negative paths
        int rightGain = max(0, dfs(root->right));

        // Max path through current node
        int priceNewPath = root->val + leftGain + rightGain;

        // Update global max
        maxSum = max(maxSum, priceNewPath);

        // Return max gain to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
