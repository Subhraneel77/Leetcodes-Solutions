class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isMirror(t1, t2):
            if not t1 and not t2:
                return True
            if not t1 or not t2:
                return False
            return t1.val == t2.val and isMirror(t1.right, t2.left) and isMirror(t1.left, t2.right)
        
        return isMirror(root, root)