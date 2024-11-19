from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        p1 = head
        p2 = p1.next

        while p1 is not None and p2 is not None:
            tmp = p1.val
            p1.val = p2.val
            p2.val = tmp
            p1 = p2.next
            if p2.next is None:
                break
            p2 = p2.next.next
        
        return head

