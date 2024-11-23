from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 0
        n_zeros = 0
        for i in range(n):
            if nums[i] == 0:
                n_zeros += 1
            if n_zeros > k:
                if nums[l] == 0:
                    n_zeros -= 1
                l += 1

        return n - l


