class Solution(object):
    def reorderList(self, head):
        q = []
        while head:
            q.append(head)
            head = head.next
        p = dummy = ListNode(0)

        while len(q)>1:
            h = q.pop(0)
            t = q.pop()
            p.next = h
            h.next = t
            p = t
            p.next = None
        
        if q: 
            p.next = q.pop()
            p = p.next
            p.next = None
            
        return dummy.next