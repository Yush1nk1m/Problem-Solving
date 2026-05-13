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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = new ListNode();
        ListNode curr = head;
        while (l1 != null || l2 != null) {
            if (l1 == null) {
                curr.next = new ListNode((carry + l2.val) % 10);
                carry = (carry + l2.val) / 10;
                l2 = l2.next;
            } else if (l2 == null) {
                curr.next = new ListNode((carry + l1.val) % 10);
                carry = (carry + l1.val) / 10;
                l1 = l1.next;
            } else {
                curr.next = new ListNode((carry + l1.val + l2.val) % 10);
                carry = (carry + l1.val + l2.val) / 10;
                l1 = l1.next;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        if (carry == 1)
            curr.next = new ListNode(1);
        return head.next;
    }
}
