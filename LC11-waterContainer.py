from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n - 1
        max_height = 0
        while l < r:
            h = min(height[l], height[r]) * (r - l)
            if h > max_height:
                max_height = h
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return max_height
