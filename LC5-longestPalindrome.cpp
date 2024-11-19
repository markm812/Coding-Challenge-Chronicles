#include <string>
#include <vector>

class Solution
{
public:
    // Expand from center solution
    // Time complexity: O(n^2)
    std::string longestPalindrome(const std::string &s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        auto expand_from_center = [&](int left, int right)
        {
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        std::string max_str = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++)
        {
            std::string odd = expand_from_center(i, i);
            std::string even = expand_from_center(i, i + 1);

            if (odd.length() > max_str.length())
            {
                max_str = odd;
            }
            if (even.length() > max_str.length())
            {
                max_str = even;
            }
        }

        return max_str;
    }

    /* Giga chad Manacher's Algorithm
     * The algorithm runs in linear time. This can be seen by noting that Center strictly increases after each outer
     * loop and the sum Center + Radius is non-decreasing. Moreover, the number of operations in the first inner loop is
     * linear in the increase of the sum Center + Radius while the number of operations in the second inner loop is
     * linear in the increase of Center. Since Center ≤ 2n+1 and Radius ≤ n, the total number of operations in the first
     * and second inner loops is O(n) and the total number of operations in the outer loop, other than those in the inner
     * loops, is also O(n). The overall running time is therefore O(n).
     */
    // Time complexity: O(n)
    // std::string longestPalindrome(const std::string &s)
    // {
    //     std::string s_prime = "#";
    //     for (char c : s)
    //     {
    //         s_prime += c;
    //         s_prime += "#";
    //     }

    //     int n = s_prime.length();
    //     std::vector<int> palindrome_radii(n, 0);
    //     int center = 0;
    //     int radius = 0;

    //     for (int i = 0; i < n; i++)
    //     {
    //         int mirror = 2 * center - i;

    //         if (i < radius)
    //         {
    //             palindrome_radii[i] = std::min(radius - i, palindrome_radii[mirror]);
    //         }

    //         while (i + 1 + palindrome_radii[i] < n &&
    //                i - 1 - palindrome_radii[i] >= 0 &&
    //                s_prime[i + 1 + palindrome_radii[i]] ==
    //                    s_prime[i - 1 - palindrome_radii[i]])
    //         {
    //             palindrome_radii[i]++;
    //         }

    //         if (i + palindrome_radii[i] > radius)
    //         {
    //             center = i;
    //             radius = i + palindrome_radii[i];
    //         }
    //     }

    //     int max_length = 0;
    //     int center_index = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (palindrome_radii[i] > max_length)
    //         {
    //             max_length = palindrome_radii[i];
    //             center_index = i;
    //         }
    //     }

    //     int start_index = (center_index - max_length) / 2;
    //     std::string longest_palindrome = s.substr(start_index, max_length);

    //     return longest_palindrome;
    // }
};