from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = 0
        r = 1
        k = 1
        while r < len(nums):
            if nums[r-1] != nums[r]:
                k += 1
                l += 1
                nums[l] = nums[r]
            r += 1
        return k