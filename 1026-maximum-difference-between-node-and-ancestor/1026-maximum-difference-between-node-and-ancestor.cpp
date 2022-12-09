class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        fill_maxmin_map(root, nullptr, nullptr);

        return find_answer(root);
    }

private:
    void fill_maxmin_map(TreeNode* root, TreeNode* max_node, TreeNode* min_node) {
        if (root == nullptr) {
            return;
        }

        max_ancestor[root] = max_node;
        min_ancestor[root] = min_node;

        if (max_node == nullptr || root->val > max_node->val) {
            max_node = root;
        }
        if (min_node == nullptr || root->val < min_node->val) {
            min_node = root;
        }

        fill_maxmin_map(root->left, max_node, min_node);
        fill_maxmin_map(root->right, max_node, min_node);
    }

    int find_answer(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int ret = 0;
        if (max_ancestor[node] != nullptr && min_ancestor[node] != nullptr) {
            ret = max(abs(node->val - max_ancestor[node]->val), abs(node->val - min_ancestor[node]->val));
        }

        ret = max(ret, find_answer(node->left));
        ret = max(ret, find_answer(node->right));

        return ret;
    }

    unordered_map<TreeNode*, TreeNode*>  max_ancestor;
    unordered_map<TreeNode*, TreeNode*>  min_ancestor;
};
