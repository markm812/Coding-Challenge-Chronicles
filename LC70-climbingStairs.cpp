#include <vector>
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        std::vector<int> ways(n + 1, -1);
        return walk(n - 1, ways) + walk(n - 2, ways);
    }

    int walk(int n, std::vector<int> &ways)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (ways[n] != -1)
            return ways[n];
        return ways[n] = walk(n - 1, ways) + walk(n - 2, ways);
    }
};