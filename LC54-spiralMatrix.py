from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix[0]), len(matrix)

        x = y = 0
        dx, dy = 1, 0
        out = []
        for i in range(m * n):
            out.append(matrix[y][x])
            matrix[y][x] = 101
            if (
                (x + dx < 0 or x + dx >= n)
                or (y + dy < 0 or y + dy >= m)
                or matrix[y + dy][x + dx] == 101
            ):
                dx, dy = -dy, dx
            x += dx
            y += dy
            if (x < 0 or x >= n) or (y < 0 or y >= m) or matrix[y][x] == 101:
                break
        return out
