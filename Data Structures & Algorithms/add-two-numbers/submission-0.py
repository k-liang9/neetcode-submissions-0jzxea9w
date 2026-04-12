# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        def recurse(l1, l2, carry):
            if not l1 and not l2 and carry == 0:
                return None

            if l1:
                val1 = l1.val
            else:
                val1 = 0

            if l2:
                val2 = l2.val
            else:
                val2 = 0

            sum_val = val1 + val2 + carry
            units_digit = sum_val % 10
            carry = sum_val // 10
            
            sum_node = ListNode(units_digit)

            if not l1 and not l2:
                next_node = recurse(None, None, carry)
            elif not l1:
                next_node = recurse(None, l2.next, carry)
            elif not l2:
                next_node = recurse(l1.next, None, carry)
            else:
                next_node = recurse(l1.next, l2.next, carry)

            sum_node.next = next_node
            return sum_node

        return recurse(l1, l2, 0)