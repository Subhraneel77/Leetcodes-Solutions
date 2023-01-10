class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans){
        if (root==NULL)return;
        if (root->left)dfs(root->left,ans);
        if (root->right)dfs(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1,ans);
        dfs(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
