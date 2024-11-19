from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def checkSubBox(row, column):
            s = set()
            for i in range(3):
                for j in range(3):
                    c = board[row + i][column + j]
                    if c != '.' and c in s:
                        return False
                    else:
                        s.add(c)
            return True

        n = len(board)
        for i in range(n):
            s1 = set()
            s2 = set()
            for j in range(0, n):
                if i % 3 == 0 and j % 3 == 0 and not checkSubBox(i, j):
                    return False
                c1 = board[i][j]
                c2 = board[j][i]
                if (c1 != "." and c1 in s1) or (c2 != "." and c2 in s2):
                    return False
                s1.add(c1)
                s2.add(c2)
        return True