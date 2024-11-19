from typing import List


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        out, tmp, l = 0, 0, 0
        count = set()

        for r in range(len(nums)):
            # skip duplicates
            while nums[r] in count:
                tmp -= nums[l]
                count.remove(nums[l])
                l += 1

            # roll window
            if (r - l + 1) > k:
                tmp -= nums[l]
                count.remove(nums[l])
                l += 1

            # update tmp sum and count
            tmp += nums[r]
            count.add(nums[r])

            # update max sum
            if (r - l + 1) == k:
                out = max(out, tmp)

        return out
