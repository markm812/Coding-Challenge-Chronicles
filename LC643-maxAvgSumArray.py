from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        max_s = s = sum(nums[:k])
        for i in range(k, n):
            s +=  nums[i] - nums[i-k]
            max_s = max(s, max_s)
        return max_s / k