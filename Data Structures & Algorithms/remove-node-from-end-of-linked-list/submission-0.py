# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        def recurse(cur):
            if cur is None:
                return 1, cur

            cnt_back, next_node = recurse(cur.next)

            cur.next = next_node
            if cnt_back == n:
                return cnt_back + 1, next_node
            else:
                return cnt_back + 1, cur

        cnt, head = recurse(head)
        return head