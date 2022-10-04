class Solution {
public:
    bool hasPathSum(TreeNode* root, int tar) {
        if(!root) return false;     // if no root then nothing is possible

        tar -= root -> val;       // if node exists then we'll consider it a possibility. Deduct its value from target
        if(!(root -> left) && !(root -> right)) return tar == 0;   // if a leaf node, return true iff tar == 0

        // if either left or right subtree of a non leaf node leads to correct configuration, return true.
        return hasPathSum(root -> left, tar) || hasPathSum(root -> right, tar);
    }
};
