class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:   
        m, n = len(matrix), len(matrix[0])     

        clear_r, clear_c = set(), set()

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    clear_r.add(i)
                    clear_c.add(j)

        for r in clear_r:
            for j in range(n):
                matrix[r][j] = 0

        for c in clear_c:
            for i in range(m):
                matrix[i][c] = 0