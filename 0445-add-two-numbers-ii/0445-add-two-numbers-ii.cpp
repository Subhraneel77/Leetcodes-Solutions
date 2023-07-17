class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stack1, stack2;

        // Push values of l1 into stack1
        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        // Push values of l2 into stack2
        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* result = nullptr;

        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int sumVal = carry;

            // Add the top values from stack1 and stack2, if available
            if (!stack1.empty()) {
                sumVal += stack1.top();
                stack1.pop();
            }
            if (!stack2.empty()) {
                sumVal += stack2.top();
                stack2.pop();
            }

            // Create a new node with the sum % 10
            ListNode* node = new ListNode(sumVal % 10);

            // Set the new node as the next node of the result list
            node->next = result;
            result = node;

            // Update the carry
            carry = sumVal / 10;
        }

        return result;
    }
};