class Solution {
public:
    bool hasCycle(ListNode *head) {
        int max=10001;
        for(int i=0;i<max;i++)
        {
            if(head) head=head->next;
            else return false;
        }
        return true;    
    }
};