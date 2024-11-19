class Solution
{
public:
    long reverse(int x)
    {
        long result = 0;
        while (x != 0)
        {
            int remainder = x % 10;
            result = result * 10 + remainder;
            x = x / 10;
        }
        return result;
    }

    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        return reverse(x) == x;
    }
};