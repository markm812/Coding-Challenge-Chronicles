from typing import List

# 1 fix + 3 sum
# class Solution:
#     def three_sum_tp(self, nums: List[int], target: int):
#         res = []
#         for i, a in enumerate(nums):
#             if i > 0 and a == nums[i - 1]:
#                 continue
#             lptr, rptr = i + 1, len(nums) - 1
#             while lptr < rptr:
#                 three_sum = a + nums[lptr] + nums[rptr]
#                 if three_sum == target:
#                     res.append([i, lptr, rptr])
#                     lptr += 1
#                     while nums[lptr] == nums[lptr - 1] and lptr < rptr:
#                         lptr += 1
#                 elif three_sum < target:
#                     lptr += 1
#                 else:
#                     rptr -= 1
#         return res

#     def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
#         quadruplets = set()
#         nums.sort()
#         for i in range(0, len(nums)):
#             if i == 0 or nums[i] != nums[i - 1]:
#                 res = self.three_sum_tp(nums[:i] + nums[i + 1 :], target - nums[i])

#                 for threeSum in res:
#                     quad = []
#                     if i <= threeSum[0]:
#                         quad = [i, threeSum[0] + 1, threeSum[1] + 1, threeSum[2] + 1]
#                     elif i <= threeSum[1]:
#                         quad = [threeSum[0], i, threeSum[1] + 1, threeSum[2] + 1]
#                     elif i <= threeSum[2]:
#                         quad = [threeSum[0], threeSum[1], i, threeSum[2] + 1]
#                     else:
#                         quad = [threeSum[0], threeSum[1], threeSum[2], i]
#                     quadruplets.add(tuple([nums[quad[0]], nums[quad[1]], nums[quad[2]], nums[quad[3]]]))
#         ans = []
#         for _, q in enumerate(quadruplets):
#             ans.append(q)
#         return ans

# break down to 2 sum
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []

            # If we have run out of numbers to add, return res.
            if not nums:
                return res

            # There are k remaining values to add to the sum. The
            # average of these values is at least target // k.
            average_value = target // k

            # We cannot obtain a sum of target if the smallest value
            # in nums is greater than target // k or if the largest
            # value in nums is smaller than target // k.
            if average_value < nums[0] or nums[-1] < average_value:
                return res

            if k == 2:
                return twoSum(nums, target)

            for i in range(len(nums)):
                if i == 0 or nums[i - 1] != nums[i]:
                    for subset in kSum(nums[i + 1 :], target - nums[i], k - 1):
                        res.append([nums[i]] + subset)

            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            s = set()

            for i in range(len(nums)):
                if len(res) == 0 or res[-1][1] != nums[i]:
                    if target - nums[i] in s:
                        res.append([target - nums[i], nums[i]])
                s.add(nums[i])

            return res

        nums.sort()
        return kSum(nums, target, 4)