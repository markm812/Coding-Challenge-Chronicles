class Solution:

    def divide(self, dividend: int, divisor: int) -> int:
        positive = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            q = 0
            while dividend > (divisor << (q + 1)):
                q += 1
            res += 1 << q
            dividend -= divisor << q
        if res == (1 << 31) and positive:
            return (1 << 31) - 1
        return res if positive else -res
