from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        longest = 0
        for n in nums:
            tmp = n
            if tmp - 1 not in s:
                count = 1
                while tmp + 1 in s:
                    tmp += 1
                    count += 1
                longest = max(longest, count)
        return longest
