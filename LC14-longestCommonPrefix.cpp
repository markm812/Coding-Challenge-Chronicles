#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::sort(strs.begin(), strs.end());
        int a = strs.size();
        std::string n = strs[0], m = strs[a - 1], ans = "";
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] != m[i])
            {
                break;
            }
            ans += n[i];
        }
        return ans;
    }
};