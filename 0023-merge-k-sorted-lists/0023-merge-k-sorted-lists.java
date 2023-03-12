class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        Queue<ListNode> minHeap = new PriorityQueue<>((head1,head2)->head1.val-head2.val);
        for(ListNode listNode: lists){
            if(listNode!=null) minHeap.offer(listNode);
        }
        ListNode head=null,cur=null;
        while(!minHeap.isEmpty()){
            ListNode curNode = minHeap.poll();
            if(curNode.next!=null) minHeap.offer(curNode.next);
            if(head==null){   //First node of answer list
                head = new ListNode(curNode.val);
                cur = head;
            }
            else{
                cur.next = new ListNode(curNode.val);
                cur = cur.next;
            }
        }
        return head;
    }
}