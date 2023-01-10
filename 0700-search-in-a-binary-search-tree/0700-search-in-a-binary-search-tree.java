class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
   
        if(root == null)
            return null;//Base Condition(If tree is empty )
        while (root != null && root.val !=val)
        {//Tree is not empty and root value is not equals to val
            root = val <root.val?root.left :root.right;//terminatory condition if val smaller than root value then search in left side else on right side
        }
        return root;  
    }
}