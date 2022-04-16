class Solution {
public:
    
    int dfs(TreeNode* root, int aboveSum) {
        if(!root) return 0;
        
        int right = dfs(root->right, aboveSum);
        int left = dfs(root->left, right + root->val + aboveSum);
        
        int sumBelow = root->val + left + right; 
        
        root->val += aboveSum + right;
        
        return sumBelow;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};