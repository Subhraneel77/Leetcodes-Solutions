class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *curr = head;

        map<int, ListNode*> m;
        m[0] = dummy;

        int prefix = 0;
        while(curr) {
            prefix += curr -> val;

            if(m.count(prefix)) {
                ListNode *p = m[prefix] -> next;
                int val = prefix;
                while(p != curr) {
                    val += p -> val;
                    m.erase(val);
                    p = p -> next;
                }
                m[prefix] -> next = curr -> next;
                
            }else {
                m[prefix] = curr;
            }
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};
