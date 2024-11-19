class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        openBrackets = ['(', '{' , '[']
        brackets = {')' : '(', '}':'{',']':'['}
        for p in s:
            if p in openBrackets:
                stack.append(p)
            else:
                if not stack:
                    return False
                if brackets[p] != stack.pop():
                    return False    
        return not stack