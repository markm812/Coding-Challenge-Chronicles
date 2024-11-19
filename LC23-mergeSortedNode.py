from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nums = []
        for l in lists:
            while l is not None:
                nums.append(l.val)
                l = l.next
        nums.sort()
        out = ListNode()
        tmp = out
        for i in range(0, len(nums)):
            tmp.next = ListNode()
            tmp = tmp.next 
            tmp.val = nums[i]
        return out.next