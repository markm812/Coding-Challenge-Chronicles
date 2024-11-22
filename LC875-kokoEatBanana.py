from math import ceil
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def canEat(k):
            hours = 0
            for p in piles:
                hours += ceil(p/k)
            return hours <= h

        max_k = max(piles)
        min_k = ceil(sum(piles) / h)
        while min_k < max_k:
            mid_k = (min_k + max_k) // 2
            if canEat(mid_k):
                max_k = mid_k 
            else:
                min_k = mid_k + 1
        return min_k

