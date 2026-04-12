class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        rows = [set() for i in range(n)]
        cols = [set() for i in range(n)]
        grids = [[set() for i in range(3)] for i in range(3)]

        for i in range(n):
            for j in range(n):
                cur_space = board[i][j]
                if cur_space == ".":
                    continue
                
                cur_space = int(cur_space)
                row = i // 3
                col = j // 3
                if cur_space in rows[i] or cur_space in cols[j] or cur_space in grids[row][col]:
                    return False
                else:
                    rows[i].add(cur_space)
                    cols[j].add(cur_space)
                    grids[row][col].add(cur_space)

        return True