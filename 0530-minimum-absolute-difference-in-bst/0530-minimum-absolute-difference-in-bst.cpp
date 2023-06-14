class Solution {
public:
    int prev = INT_MAX;
    int ans = INT_MAX;
    
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    
    void inOrder(TreeNode* root) {
        if (root->left != nullptr)
            inOrder(root->left);
        
        ans = std::min(ans, std::abs(root->val - prev));
        prev = root->val;
        
        if (root->right != nullptr)
            inOrder(root->right);
    }
};
