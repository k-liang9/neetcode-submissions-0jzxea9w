# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        nodes = []

        while head is not None:
            nodes.append(head)
            head = head.next

        l, r = 0, len(nodes) - 1
        dummy = ListNode()
        tail = dummy
        while l < r:
            tail.next = nodes[l]
            tail = tail.next
            tail.next = nodes[r]
            tail = tail.next
            l += 1
            r -= 1

        if l == r:
            tail.next = nodes[l]
            tail = tail.next

        tail.next = None