class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // If either of the input vectors are empty, the tree is empty, so return null
    if (inorder.size() == 0 || postorder.size() == 0) return nullptr;

    // Initialize indices to the last elements of the inorder and postorder traversals
    int ip = inorder.size() - 1;
    int pp = postorder.size() - 1;

    // Create an empty stack to help us build the binary tree
    stack<TreeNode*> st;
    // Initialize prev to null since we haven't processed any nodes yet
    TreeNode* prev = nullptr;
    // Create the root node using the last element in the postorder traversal
    TreeNode* root = new TreeNode(postorder[pp]);
    // Push the root onto the stack and move to the next element in the postorder traversal
    st.push(root);
    pp--;

    // Process the rest of the nodes in the postorder traversal
    while (pp >= 0) {
        // While the stack is not empty and the top of the stack is the current inorder element
        while (!st.empty() && st.top()->val == inorder[ip]) {
            // The top of the stack is the parent of the current node, so pop it off the stack and update prev
            prev = st.top();
            st.pop();
            ip--;
        }
        // Create a new node for the current postorder element
        TreeNode* newNode = new TreeNode(postorder[pp]);
        // If prev is not null, the parent of the current node is prev, so attach the node as the left child of prev
        if (prev != nullptr) {
            prev->left = newNode;
        // If prev is null, the parent of the current node is the current top of the stack, so attach the node as the right child of the current top of the stack
        } else if (!st.empty()) {
            TreeNode* currTop = st.top();
            currTop->right = newNode;
        }
        // Push the new node onto the stack, reset prev to null, and move to the next element in the postorder traversal
        st.push(newNode);
        prev = nullptr;
        pp--;
    }

    // Return the root of the binary tree
    return root;
    }
};