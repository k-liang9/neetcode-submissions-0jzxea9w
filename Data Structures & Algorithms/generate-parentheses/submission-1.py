class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        cur = ['(']
        def dfs(open, close):
            if open == close == n:
                res.append(cur.copy())
                return
            
            if open < n:
                cur.append('(')
                dfs(open+1, close)
                cur.pop()
            
            if close < n and close < open:
                cur.append(')')
                dfs(open, close+1)
                cur.pop()

        dfs(1, 0)

        res = [''.join(i) for i in res]
        return res