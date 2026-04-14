class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        res = matrix[0].copy()
        i, j = 0, n-1
        step_i, step_j = m-1, n-1
        dirs = [(1, 0), (0, -1), (-1, 0), (0, 1)]
        dir_idx = 0

        while True:
            di, dj = dirs[dir_idx]
            if di == 0:
                steps = step_j
            else:
                steps = step_i
            
            if steps == 0:
                break

            for _ in range(steps):
                i += di
                j += dj
                res.append(matrix[i][j])
            
            if di == 0:
                step_j -= 1
            else:
                step_i -= 1

            dir_idx = (dir_idx + 1) % 4

        return res