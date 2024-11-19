#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> subsets_;

    void findSubsets(std::vector<int>& nums, int i, int n, std::vector<int> sub) {
        if (i >= n) {
            subsets_.push_back(sub);
            return;
        }
        findSubsets(nums, i + 1, n, sub);
        sub.push_back(nums[i]);
        findSubsets(nums, i + 1, n, sub);
    }
    
    std::vector<std::vector<int>> subsets(std::vector<int>& nums, int i = 0) {
        findSubsets(nums, 0, nums.size(), {});
        return subsets_;
    }
};