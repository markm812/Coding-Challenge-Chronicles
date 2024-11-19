#include <vector>
#include <iterator>
#include <algorithm>

/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/editorial
 * The findMedianSortedArrays method finds the median of two sorted arrays using a binary search approach.
 * The method ensures that the time complexity is O(log(min(n, m))), where n and m are the sizes of the two arrays.
 *
 * - If the first array is larger than the second, the method swaps the arrays to ensure the first array is smaller.
 * - The binary search is performed on the smaller array to find the correct partition.
 * - The partition is adjusted based on the comparison of elements around the partition.
 * - The median is calculated based on the combined size of the arrays (even or odd).
 *
 * @intuition
 * - The goal is to partition the arrays such that the left half contains the same number of elements as the right half.
 * - The maximum element on the left side should be less than or equal to the minimum element on the right side.
 * - By adjusting the partition using binary search, we can efficiently find the correct partition.
 */
class Solution
{
public:
    // O(nlogn) no recurrsion solution
    // double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    // {
    //     std::copy(nums2.begin(), nums2.end(), std::back_inserter(nums1));
    //     int size = nums1.size();
    //     std::sort(nums1.begin(), nums1.end());
    //     if (size % 2)
    //         return nums1[size / 2];
    //     else
    //         return (double)(nums1[size / 2] + nums1[size / 2 - 1]) / 2;
    // }

    // O(log(min(n, m))) solution
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = n;
        while (l <= r)
        {
            int i = (l + r) / 2;
            int j = (n + m + 1) / 2 - i;
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == n) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == m) ? INT_MAX : nums2[j];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((n + m) % 2 == 0)
                {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return std::max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
        return 0.0;
    }
};