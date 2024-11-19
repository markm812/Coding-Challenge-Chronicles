from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        out = ListNode(101, head)
        l, r = out, out.next
               
        while r:
            if l.val == r.val:
                r = r.next
            else:
                l.next = r
                l = r
                r = l.next
        l.next = None       
        return out.next