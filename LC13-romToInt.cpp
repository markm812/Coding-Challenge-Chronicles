#include <unordered_map>
#include <string>
class Solution
{
public:
    int romanToInt(const std::string &s)
    {
        std::unordered_map<char, int> RTOI = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

        int result = 0, i = 0, n = s.length();
        while (i < n - 1)
        {
            if (RTOI[s[i]] >= RTOI[s[i + 1]])
            {
                result += RTOI[s[i]];
                i++;
            }
            else
            {
                result -= RTOI[s[i]];
                result += RTOI[s[i + 1]];
                i += 2;
            }
        }
        result += RTOI[s[i]];
        return result;
    }
};