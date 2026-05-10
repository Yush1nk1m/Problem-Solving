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

    public void reorderList(ListNode head) {
        ListNode slow, fast, reversed, curr, prev = null, next;
        slow = fast = head;
        while (slow != null && fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        reversed = slow.next;
        slow.next = null;
        while (reversed != null) {
            next = reversed.next;
            reversed.next = prev;
            prev = reversed;
            reversed = next;
        }
        reversed = prev;

        curr = head;
        while (reversed != null) {
            ListNode temp1 = curr.next, temp2 = reversed.next;
            curr.next = reversed;
            reversed.next = temp1;
            curr = temp1;
            reversed = temp2;
        }
    }
}
