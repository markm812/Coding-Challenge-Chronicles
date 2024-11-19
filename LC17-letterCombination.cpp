#include <vector>
#include <string>
class Solution
{
private:
    std::vector<std::string> ans;
    std::string mapping[10] = {"", "", "abc", "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(const std::string &digits, std::string &output, int i)
    {
        if (i >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int num = digits[i] - '0';
        std::string value = mapping[num];

        for (int j = 0; j < value.length(); j++)
        {
            output.push_back(value[j]);
            solve(digits, output, i + 1);
            output.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(const std::string &digits)
    {
        if (digits.length() == 0)
        {
            return ans;
        }
        std::string output;
        solve(digits, output, 0);
        return ans;
    }
};