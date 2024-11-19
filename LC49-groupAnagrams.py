from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dicts = {}
        for idx, s in enumerate(strs):
            key = "".join(sorted(s))
            if key in dicts:
                dicts[key].append(strs[idx])
            else:
                dicts[key] = [strs[idx]]
        return list(dicts.values())
