class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Helper function for deserialization
    TreeNode* buildTree(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();

        if (val == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> nodes;

        while (getline(ss, item, ',')) {
            nodes.push(item);
        }

        return buildTree(nodes);
    }
};
