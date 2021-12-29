class Solution {
    public Node connect(Node root) {
        Node levelStart = root;
        while (levelStart != null) {
            Node curr = levelStart;
            while (curr != null) {
                if (curr.left != null) {
                    curr.left.next = curr.right;
                }
                if (curr.right != null && curr.next != null) {
                    curr.right.next = curr.next.left;
                }
                // move the current node to the next position
                curr = curr.next;
            }
            // move the levelStart node the next level's head position
            levelStart = levelStart.left;
        }
        return root;
    }
}