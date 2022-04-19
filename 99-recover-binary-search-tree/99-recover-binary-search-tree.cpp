class Solution {

    void dfs(TreeNode* root, vector<int>& cheat) {
        if(!root) return;
        
        dfs(root->left, cheat);
        cheat.push_back(root->val);
        dfs(root->right, cheat);
    }
    
    void cheatAgain(TreeNode* root, vector<int>& cheat, int& i) {
        if(!root) return;
        cheatAgain(root->left, cheat, i);
        if(root->val != cheat[i]) {
            root->val = cheat[i];
        }
        i++;
        cheatAgain(root->right, cheat, i);
        
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> cheat;
        dfs(root, cheat);
        sort(cheat.begin(), cheat.end());
        int i = 0;
        cheatAgain(root, cheat, i);
        return;
        
    }
};