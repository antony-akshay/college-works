# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        carry = 0
        current = dummy

        while l1 is not None or l2 is not None or carry!=0:

            if l1 is not None:
                val1 = l1.val
            else:
                val1 = 0

            if l2 is not None:
                val2 = l2.val
            else:
                val2 = 0

            total = val1+val2+carry
            carry = total // 10
            next_num = total % 10

            new_node = ListNode(next_num) 
            current.next = new_node
            current = new_node

            if l1 is not None:
                l1=l1.next
            if l2 is not None:
                l2=l2.next
        return dummy.next
