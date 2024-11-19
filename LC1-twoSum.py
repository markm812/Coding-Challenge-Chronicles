from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        occurence = {}
        for i in range(len(nums)):
            remain = target - nums[i]
            if remain in occurence:
                return [i, occurence[remain]]
            occurence[nums[i]] = i
        return []