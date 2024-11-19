#include <string>
#include <vector>
class Solution {
public:
    std::string convert(const std::string& s, int numRows) {
        int n = s.length();
        if (numRows == 1)
            return s;

        std::vector<std::string> vec(numRows, "");
        int p = 0;
        while (p < n) {
            for (int i = 0; i < numRows; i++) {
                if (p + i < n)
                    vec[i] += s[p + i];
            }
            for (int j = 0; j < numRows - 2; j++) {
                if (p + numRows + j < n)
                    vec[numRows - j - 2] += s[p + numRows + j];
            }
            p += numRows * 2 - 2;
        }
        std::string result = "";
        for (const auto& str : vec) {
            result += str;
        }
        return result;
    }
};