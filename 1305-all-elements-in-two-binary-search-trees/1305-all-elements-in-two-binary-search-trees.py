class Solution(object):
    def getAllElements(self, root1, root2):
        def trverse(root):
            ans, dq = [], deque([root])
            while dq:
                node = dq.pop()
                if type(node) == int: ans.append(node)
                elif node: dq.extend([node.left, node.val, node.right])
            return ans

        l1, l2, ans = trverse(root1), trverse(root2), []
        while l1 and l2: ans.append(l1.pop() if l1[-1] < l2[-1] else l2.pop())
        return ans + list(reversed(l1 or l2))