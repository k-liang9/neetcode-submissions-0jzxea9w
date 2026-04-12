class Solution:
    def isValid(self, s: str) -> bool:
        p_stack = []
        for ch in s:
            if ch == '(' or ch == '{' or ch == '[':
                p_stack.append(ch)
            
            if ch == ')' or ch == '}' or ch == ']':
                if len(p_stack) == 0:
                    return False
                last_paren = p_stack.pop()
                if (
                    ch == ')' and last_paren != '(' or
                    ch == '}' and last_paren != '{' or
                    ch == ']' and last_paren != '['
                ):
                    return False
        
        return len(p_stack) == 0