class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // 1️⃣ Traverse like BST
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 2️⃣ Found the node to delete

            // Case 1: Leaf node
            if (!root->left && !root->right) {
                return nullptr;
            }

            // Case 2: One child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: Two children
            TreeNode* minRight = findMin(root->right);   // Successor
            root->val = minRight->val;                   // Replace value
            root->right = deleteNode(root->right, minRight->val); // Delete successor
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};
