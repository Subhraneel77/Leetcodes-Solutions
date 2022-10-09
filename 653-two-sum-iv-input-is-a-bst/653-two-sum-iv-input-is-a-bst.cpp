
class Solution {
public:
    bool solve(TreeNode*root,unordered_map<int,int>&mp,int &k)
    {
        
        // int dif=abs(k-root->val);
           if(root==nullptr)return 0;
            if(mp.find(k-root->val)!=mp.end()){
                return true;
            }
            mp[root->val]++;
        return solve(root->right,mp,k) || solve(root->left,mp,k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        if(!root)return 0;
        return solve(root,mp,k);
        
    }
};