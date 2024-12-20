class Solution {
public:
    void helper(TreeNode *node1, TreeNode *node2, int level) {
        if (!node1 || !node2)
            return;
        if (level & 1) {
            int temp = node1->val;
            node1->val = node2->val;
            node2->val = temp;
        }
        helper(node1->left, node2->right, level + 1);
        helper(node1->right, node2->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, 1);
        return root;
    }
};