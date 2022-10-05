class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int d = 1;
        
        while(d < depth - 1)
        {
            queue<TreeNode*> temp;
            
            while(q.empty() == false)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL)temp.push(node->left);

                if(node->right != NULL)temp.push(node->right);
            }
            
            q = temp;
            d++;
        }
        
        while(q.empty() == false)
        {
            TreeNode* node = q.front();
            q.pop();
            
            TreeNode* temp_left = node->left;
            
            node->left = new TreeNode(val);
            node->left->left = temp_left;
            
            TreeNode* temp_right = node->right;
            
            node->right = new TreeNode(val);
            node->right->right = temp_right;
        }
        
        return root;
    }
};