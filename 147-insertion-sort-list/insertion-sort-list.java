class Solution {
    public ListNode insertionSortList(ListNode head) {
        // Dummy node as head of the sorted list
        ListNode dummy = new ListNode(0);
        ListNode curr = head;

        while(curr != null){
            // At each iteration, prev points to the dummy
            ListNode prev = dummy;
            ListNode next = curr.next; // Stores the next value of curr

            // Traverse till you find a node which greater than the prev val
            while(prev.next != null && prev.next.val < curr.val){
                prev = prev.next;
            }

            // Insert curr between prev and prev.next [Inserting the sorted node]
            curr.next = prev.next;
            prev.next = curr;

            // Move to the next node
            curr = next;
        }

        return dummy.next;
    }
}

// TC: O(N^2), SC: O(1)

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */