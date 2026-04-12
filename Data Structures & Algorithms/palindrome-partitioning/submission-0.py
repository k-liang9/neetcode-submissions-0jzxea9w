class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res_ints = []
        cur = []

        def is_palindrome(i, j):
            while (i < j):
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            
            return True

        def dfs(i):
            if i >= len(s):
                res_ints.append(cur.copy())
                return

            for j in range(i, len(s)):
                if is_palindrome(i, j):
                    cur.append(j+1)
                    dfs(j+1)
                    cur.pop()
        
        dfs(0)

        res = []
        for ints in res_ints:
            prev = 0
            substrs = []
            for i in ints:
                substrs.append(s[prev:i])
                prev = i
            res.append(substrs)
        
        return res