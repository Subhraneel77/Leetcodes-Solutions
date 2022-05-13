class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            Node* prev = nullptr;
            for(int i = 0; i < qSize; i++) {
                auto top = q.front();
                q.pop();
                top->next = prev;
                prev = top;
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }
        
        return root;
        
    }
};