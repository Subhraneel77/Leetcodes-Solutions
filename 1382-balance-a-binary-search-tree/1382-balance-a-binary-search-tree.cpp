class Solution {
public:
    vector<int> arr;
    inline void inOrder(TreeNode* root){
        vector<TreeNode*> stack;
        TreeNode* node=root;
        while (node || !stack.empty()){
            while(node){
                stack.push_back(node);
                node=node->left;
            }
            node=stack.back();
            stack.pop_back();
            
            arr.push_back(node->val);

            node=node->right;
        }
    }

    TreeNode* balanceBST(int l, int r){
        if (l>r) return NULL;
        const int m=(l+r)/2;
        TreeNode* left=(l>m-1)?NULL:balanceBST(l, m-1);
        TreeNode* right=(m+1>r)?NULL:balanceBST(m+1, r);
        return new TreeNode(arr[m], left, right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return balanceBST(0, arr.size()-1);
    }
};





auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();