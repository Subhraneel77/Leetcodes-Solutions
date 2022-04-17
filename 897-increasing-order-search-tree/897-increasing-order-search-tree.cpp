class Solution {
    
    void dfs(TreeNode* root, TreeNode*& sentinel) {
        if(!root) return;
        dfs(root->left, sentinel);
        TreeNode* newNode = new TreeNode(root->val);
        sentinel->right = newNode;
        sentinel = sentinel->right;
        dfs(root->right, sentinel);
        return;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* sentinel = new TreeNode(0);
        TreeNode* ans = sentinel;
        dfs(root, sentinel);
        return ans->right;
    }
};