class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(char for char in s if char.isalnum()).lower()
        n = len(s)
        l, r = 0 , n -1
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

