#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int n = s.size();
        int ans = 0;
        std::vector<int> index(128, -1);
        for (int i = 0, j = 0; j < n; j++)
        {
            // last occurence
            i = std::max(index[s[j]] + 1, i);
            // update length
            ans = std::max(ans, j - i + 1);
            // update last occurence
            index[s[j]] = j;
        }
        return ans;
    }
};