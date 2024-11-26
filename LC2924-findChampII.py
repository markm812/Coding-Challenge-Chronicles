from typing import List


class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        teams = set(range(n))

        for edge in edges:
            if edge[1] in teams:
                teams.remove(edge[1])
                n -= 1

        if n == 1:
            [element] = teams
            return element
        return -1
