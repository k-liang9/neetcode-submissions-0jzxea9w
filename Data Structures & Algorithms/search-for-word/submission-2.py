class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        h = len(board)
        w = len(board[0])
        used = [[False for i in range(w)] for j in range(h)]

        def dfs(i, j, index):
            if index >= len(word):
                return True

            if i < 0 or i >= h or j < 0 or j >= w or used[i][j]:
                return False

            if board[i][j] == word[index]:
                index += 1
                used[i][j] = True
                res = dfs(i-1, j, index) or dfs(i+1, j, index) or dfs(i, j-1, index) or dfs(i, j+1, index)
                used[i][j] = False
                return res
            else:
                return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True

        return False