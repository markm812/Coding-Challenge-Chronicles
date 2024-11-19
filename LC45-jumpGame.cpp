#include <vector>
#include <deque>
class Solution
{
public:
    int jump(const std::vector<int> &nums)
    {
        int n = nums.size();

        std::vector<int> dist(n, 1e9);
        dist[0] = 0;

        std::deque<int> q;
        q.push_back(0);
        while (!q.empty())
        {
            int v = q.front();
            q.pop_front();

            if (v - 1 >= 0 && dist[v - 1] > dist[v] + 0)
            {
                dist[v - 1] = dist[v];
                q.push_front(v - 1);
            }

            int u = std::min(n - 1, v + nums[v]);
            if (dist[u] > dist[v] + 1)
            {
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
        return dist[n - 1];
    }
};