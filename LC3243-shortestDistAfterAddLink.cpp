#include <vector>

class Solution {
    template <typename T> class Graph {
    public:
        using AdjacencyList = std::vector<std::vector<std::pair<int, T>>>;
        AdjacencyList adjList;

        Graph(int nodes) : adjList(nodes) {}

        void addEdge(int from, int to, T weight) {
            adjList[from].emplace_back(to, weight);
        }

        T dijkstra(int startNode) const {
            int n = adjList.size();
            std::vector<T> minCosts(n, std::numeric_limits<T>::max());
            minCosts[startNode] = static_cast<T>(0);

            using P = std::pair<T, int>;
            std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
            pq.push({0, startNode});

            while (!pq.empty()) {
                T currentCost = pq.top().first;
                int currentNode = pq.top().second;
                pq.pop();

                if (currentCost > minCosts[currentNode])
                    continue;

                for (const auto& [neighbor, weight] : adjList[currentNode]) {
                    T newCost = currentCost + weight;
                    if (newCost < minCosts[neighbor]) {
                        minCosts[neighbor] = newCost;
                        pq.push({newCost, neighbor});
                    }
                }
            }

            return minCosts[n - 1];
        }
    };

public:
    std::vector<int> shortestDistanceAfterQueries(int n,
                                             std::vector<std::vector<int>>& queries) {
        int q_size = queries.size();
        std::vector<int> out(q_size);
        Graph<int> G(n);

        for (int i = 0; i < n - 1; i++) {
            G.addEdge(i, i + 1, 1);
        }

        for (int i = 0; i < q_size; i++) {
            G.addEdge(queries[i][0], queries[i][1], 1);
            out[i] = G.dijkstra(0);
        }

        return out;
    }
};