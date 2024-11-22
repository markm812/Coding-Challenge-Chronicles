from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        lr, rr = 0, m - 1
        while lr <= rr:
            mr = (lr + rr) // 2
            if matrix[mr][0] == target:
                return True
            if target < matrix[mr][0]:
                rr = mr - 1
            elif target > matrix[mr][-1]:
                lr = mr + 1
            else:
                lc, rc = 0, n - 1
                while lc <= rc:
                    mc = (lc + rc) // 2
                    if matrix[mr][mc] == target:
                        return True
                    if matrix[mr][mc] > target:
                        rc = mc - 1
                    else:
                        lc = mc + 1
                return False
        return False
