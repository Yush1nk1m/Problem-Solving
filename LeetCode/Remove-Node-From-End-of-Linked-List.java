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

class Solution {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size = 0;
        ListNode curr = head, prev = null, next;

        while (curr != null) {
            ++size;
            curr = curr.next;
        }

        n = size - n - 1;
        curr = head;
        while (n >= 0) {
            --n;
            prev = curr;
            curr = curr.next;
        }

        if (curr == head) {
            head = head.next;
        } else {
            prev.next = curr.next;
        }

        return head;
    }
}
