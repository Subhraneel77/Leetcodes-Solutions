class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next; // Start from the node after the initial 0
        ListNode* nextSum = modify;

        while (nextSum != nullptr) {
            int sum = 0;
            // Find the sum of all nodes until you encounter a 0.
            while (nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }

            // Assign the sum to the current node's value.
            modify->val = sum;
            // Move nextSum to the first non-zero value of the next block.
            nextSum = nextSum->next;
            // Move modify also to this node.
            modify->next = nextSum;
            modify = modify->next;
        }
        return head->next; // Skip the initial 0 node.
    }
};