class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        letter_map = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

        res = []
        cur = []

        def dfs(i):
            if i >= len(digits):
                res.append(''.join(cur))
                return

            idx = ord(digits[i]) - ord('2')
            for ch in letter_map[idx]:
                cur.append(ch)
                dfs(i+1)
                cur.pop()
            
            return

        dfs(0)

        return res