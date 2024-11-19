#include <string>
class Solution
{
public:
    int myAtoi(const std::string &s)
    {
        long result = 0;
        int sign = 0;
        for (auto &c : s)
        {
            if ((result || sign))
            {
                if ((c < '0' ||
                     c > '9')) // Non digit character following sign/digit
                    break;
            }
            else if (c == ' ')
            {
                continue; // leading white space character
            }
            else if (c == '-' || c == '+')
            {
                sign = ',' - c;
                continue;
            }
            else if ((c < '0' || c > '9'))
            {
                break; // leading non-digit non sign character
            }

            if (!sign)
            {
                sign = 1;
            }

            result = result * 10 + c - '0';
            if (sign > 0 && result >= INT_MAX)
            {
                return INT_MAX;
            }
            else if (sign < 0 && -result <= INT_MIN)
            {
                return INT_MIN;
            }
        }
        return (int)(sign * result);
    }
};