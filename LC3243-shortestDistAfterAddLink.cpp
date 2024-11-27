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

// Bottom-up DP

// class Solution {
// public:
//     // Function to find the minimum distance from node 0 to node n-1
//     int findMinDistance(vector<vector<int>> &adjList, int n) {
//         vector<int> dp(n);
//         dp[n - 1] = 0;  // Base case: distance to destination (n-1) is 0

//         // Iterate from the second last node down to the first node
//         for (int currentNode = n - 2; currentNode >= 0; currentNode--) {
//             int minDistance = n;
//             // Explore neighbors to find the minimum distance
//             for (auto neighbor : adjList[currentNode]) {
//                 minDistance = min(minDistance, dp[neighbor] + 1);
//             }
//             dp[currentNode] = minDistance;  // Store the calculated distance for
//                                             // the current node
//         }
//         return dp[0];
//     }

//     vector<int> shortestDistanceAfterQueries(int n,
//                                              vector<vector<int>> &queries) {
//         vector<int> answer;
//         vector<vector<int>> adjList(n, vector<int>(0));

//         // Initialize edges between consecutive nodes
//         for (int i = 0; i < n - 1; i++) {
//             adjList[i].push_back(i + 1);
//         }

//         // Process each query to add new edges
//         for (auto &road : queries) {
//             int u = road[0];
//             int v = road[1];
//             adjList[u].push_back(v);  // Add the directed edge from u to v

//             // Calculate the minimum distance after adding the new edge
//             answer.push_back(findMinDistance(adjList, n));
//         }
//         return answer;
//     }
// };