from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:

        n = len(height)
        l, r = 0, n - 1
        total_water = 0
        l_max = height[0]
        r_max = height[-1]

        while l < r:
            if l_max < r_max:
                total_water += l_max - height[l]
                l += 1
                l_max = max(l_max, height[l])
            else:
                total_water += r_max - height[r]
                r -= 1
                r_max = max(r_max, height[r])
        return total_water
