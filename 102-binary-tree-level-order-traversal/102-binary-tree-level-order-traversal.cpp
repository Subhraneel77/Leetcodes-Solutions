class Solution {
public:
    
    vector<vector<int>> solve(vector<TreeNode*> k, vector<vector<int>> res){
        if (k.size()==0) return res;
        
        vector<TreeNode*> newk;
        vector<int> lvl;
        
        for (int i=0; i < k.size(); i++){
            lvl.push_back( k[i] -> val );
            if ( k[i] -> left ) newk.push_back( k[i] -> left);
            if ( k[i] -> right ) newk.push_back( k[i] -> right);
        }
        
        res.push_back(lvl);
        return solve(newk, res);
        
    }   
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<TreeNode*> k{root};
        vector<vector<int>> res;
        
        if (root==NULL) return res;
        
        return solve(k,res);
        
    }
};
