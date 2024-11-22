from math import ceil


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 1, ceil(num / 2)
        while l <= r:
            m = (l + r) // 2
            sq = m**2
            if sq == num:
                return True
            if sq < num:
                l = m + 1
            else:
                r = m - 1
        return False
