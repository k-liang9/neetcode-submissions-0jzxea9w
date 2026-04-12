# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        new_head = self.reverse(head, head.next)
        head.next = None
        return new_head

    def reverse(self, prev, cur):
        if cur is None:
            return prev

        temp = cur.next
        cur.next = prev
        return self.reverse(cur, temp)