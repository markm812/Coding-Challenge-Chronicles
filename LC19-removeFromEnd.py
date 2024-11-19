from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        p3 = ListNode(0, head)
        p1 = p2 = p3
        for _ in range(n+1):
            p2 = p2.next

        while p2 is not None:
            p2 = p2.next
            p1 = p1.next
        p1.next = p1.next.next
        return p3.next
        

        