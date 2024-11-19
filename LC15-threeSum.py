from typing import List


def three_sum_tp(nums: List[int], target: int):
    nums.sort()
    res = []

    for i, a in enumerate(nums):
        if i > 0 and a == nums[i - 1]:
            continue
        lptr, rptr = i + 1, len(nums) - 1
        while lptr < rptr:
            three_sum = a + nums[lptr] + nums[rptr]
            if three_sum == target:
                res.append([a, nums[lptr], nums[rptr]])
                lptr += 1
                while nums[lptr] == nums[lptr - 1] and lptr < rptr:
                    lptr += 1
            elif three_sum < target:
                lptr += 1
            else:
                rptr -= 1
    return res


# Test cases
print(three_sum_tp([-1, 0, 1, 2, -1, -4], 0))  # [[-1, -1, 2], [-1, 0, 1]]
print(three_sum_tp([0, 0, 0, 0], 0))  # [[0, 0, 0]]
print(three_sum_tp([1, 1, 0, -1, -2], 0))  # [  [-2, 1, 1], [-1, 0, 1]]
print(three_sum_tp([-1,-2,-3,-4,-6], 0)) # []
