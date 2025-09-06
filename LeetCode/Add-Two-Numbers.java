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
        ListNode head = null, curr = null;

        do {
            int currVal = carry;
            currVal += (l1 != null) ? l1.val : 0;
            currVal += (l2 != null) ? l2.val : 0;
            ListNode temp = new ListNode(currVal % 10);
            carry = currVal / 10;

            if (head == null)
                head = curr = temp;
            else {
                curr.next = temp;
                curr = curr.next;
            }

            l1 = (l1 != null) ? l1.next : l1;
            l2 = (l2 != null) ? l2.next : l2;
        } while (l1 != null || l2 != null);

        if (carry > 0)
            curr.next = new ListNode(1);

        return head;
    }
}