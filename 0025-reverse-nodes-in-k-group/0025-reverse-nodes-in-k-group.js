var reverseKGroup = function(head, k) {
    // Base condition
    if (head === null || k === 1) {
        return head;
    }
    // Dummy node before head
    const dummy = new ListNode(-1);
    // Point the next of this dummy to the current head
    dummy.next = head;
    // Node to keep track of the previous node
    let previous = dummy;
    // Variable to keep count of the nodes in the linked list
    let count = 0;
    // Reference to the head which will be used to traverse
    let current = head;
    while (current !== null) {
        count++;
        if (count % k === 0) {
            previous = reverse(previous, current.next);
            current = previous.next;
        } else {
            current = current.next;
        }
    }
    return dummy.next;
};

const reverse = (start, end) => {
    // Previous node of the current node
    let previous = start.next;
    // Current node
    let current = previous.next;
    // Next node of the current node
    let next;
    // Loop for the whole interval
    while (current != end) {
        // Next node of the current node
        next = current.next;
        // Next of current will point to the previous
        current.next = start.next;
        // Current node will become the previous node
        start.next = current;
        // Move pointer ahead
        current = next;
    }
    previous.next = end;
    // Return head node of the reversed linked list
    return previous;
}