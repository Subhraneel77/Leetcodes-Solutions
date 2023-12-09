class Solution {
public:
    vector<int> vec; 
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }
};