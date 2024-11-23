import collections
from typing import List


class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        dic = collections.Counter()
        for row in matrix:
            p = "".join("a" if num == row[0] else "b" for num in row)
            dic[p] = dic[p] + 1
        return max(dic.values())
