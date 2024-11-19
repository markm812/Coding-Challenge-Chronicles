from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l = 0
        r = len(nums) - 1
        k = 0
        while l <= r:
            if nums[l] == val:
                while nums[r] == val and l < r:
                    r -= 1
                    k += 1
                tmp = nums[r]
                nums[r] = nums[l]
                nums[l] = tmp
                r -= 1
                k += 1
            l += 1

        nums = nums[: len(nums) - k]
        return len(nums)
