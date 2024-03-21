class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;

        ListNode *p, *c, *n;

        p = head;
        c = head->next;
        n = c->next;

        while( n !=NULL ) {
            c->next = p;
            p = c;
            c = n;
            n = n->next;
        }

        head->next = NULL;
        c->next = p;

        return c;
        
    }
};