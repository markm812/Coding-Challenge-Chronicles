#include <vector>
#include <algorithm>

class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int closetSum = INT_MAX / 2;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (std::abs(target - sum) < abs(target - closetSum))
                {
                    closetSum = sum;
                }

                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                    return sum;
            }
        }
        return closetSum;
    }
};