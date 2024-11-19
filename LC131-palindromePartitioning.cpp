#include <vector>
#include <string>
class Solution
{
public:
    std::vector<std::vector<std::string>> result;

    bool isParlindrome(const std::string &str)
    {
        int l = 0, r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(const std::string &str, int begin, int end,
               std::vector<std::string> &partitions)
    {
        if (begin > end)
        {
            result.push_back(partitions);
            return;
        }
        for (int i = begin; i <= end; ++i)
        {
            auto subStr = str.substr(begin, i - begin + 1);
            if (isParlindrome(subStr))
            {
                partitions.push_back(subStr);
                solve(str, i + 1, end, partitions);
                partitions.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(const std::string &s)
    {
        std::vector<std::string> parti;
        solve(s, 0, s.size() - 1, parti);
        return result;
    }
};