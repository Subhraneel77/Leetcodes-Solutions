var swapPairs = function (head) {
    // Dummy node
    const dummy = new ListNode(0);
    // Point the next of dummy node to the head
    dummy.next = head;
    // This node will be used to traverse the list
    let current = dummy;
    // Loop until we reach to the second last node
    while (current.next !== null && current.next !== undefined && current.next.next !== null) {
        // First node of the pair
        let first = current.next;
        // Second node of the pair
        let second = current.next.next;
        // Point the next of first node to the node after second node
        first.next = second.next;
        // Now the current node's next should be the second node
        current.next = second;
        // Linking the original second node to the first node
        current.next.next = first;
        // Move the pointer two nodes ahead
        current = current.next.next;
    }
    return dummy.next;
};