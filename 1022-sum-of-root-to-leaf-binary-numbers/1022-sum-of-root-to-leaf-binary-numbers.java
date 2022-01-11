class Solution {
    int total;

    public int sumRootToLeaf(TreeNode root) {
        total = 0;
        if (root == null) return 0;
        sum(root, 0);
        return total;
    }

    void sum(TreeNode root, int parentValue){
        if (root == null){
            return;
        }
        int cur = parentValue * 2 + root.val;
        if (root.left == null && root.right == null){
            total += cur;
            return;
        }
        sum(root.left, cur);
        sum(root.right, cur);
    }
}
