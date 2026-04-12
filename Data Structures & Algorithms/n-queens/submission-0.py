# backtracking
# use an occupancy grid. each square a queen can move to is incremented by one
# when iterating through where to put a queen, check the occupancy grid. if 0, then it is a valid place to put a queen, else it is not valid
# when backtracking, decrement every square that the queen covers on the occupancy grid by 1

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        cur = [['.' for i in range(n)] for i in range(n)]
        occupancy = [[0 for i in range(n)] for i in range(n)]

        def update_occupancy(i, j, offset):
            for k in range(n):
                occupancy[i][k] += offset
                occupancy[k][j] += offset

            occupancy[i][j] -= offset

            for k in range(1, n, 1):
                in_range = False
                for row_factor in [-1, 1]:
                    for col_factor in [-1, 1]:
                        row = i + row_factor * k
                        col = j + col_factor * k
                        if 0 <= row < n and 0 <= col < n:
                            in_range = True
                            occupancy[row][col] += offset

                if not in_range:
                    break

        def backtrack(row, col, k):
            if k >= n:
                config = [''.join(row) for row in cur]
                res.append(config)
                return

            for i in range(row, n):
                for j in range(n):
                    if i == row and j < col:
                        continue
                    if occupancy[i][j] == 0:
                        cur[i][j] = 'Q'
                        update_occupancy(i, j, 1)
                        backtrack(i, j, k+1)
                        update_occupancy(i, j, -1)
                        cur[i][j] = '.'


        backtrack(0, 0, 0)

        return res